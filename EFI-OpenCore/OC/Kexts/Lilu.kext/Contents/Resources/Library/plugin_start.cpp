//
//  plugin_start.cpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>
#include <Headers/kern_util.hpp>

#ifndef LILU_CUSTOM_KMOD_INIT
bool ADDPR(startSuccess) = false;
#else
// Workaround custom kmod code and enable by default
bool ADDPR(startSuccess) = true;
#endif

bool ADDPR(debugEnabled) = false;
uint32_t ADDPR(debugPrintDelay) = 0;

#if !defined(LILU_CUSTOM_KMOD_INIT) || !defined(LILU_CUSTOM_IOKIT_INIT)

static const char kextVersion[] {
#ifdef DEBUG
	'D', 'B', 'G', '-',
#else
	'R', 'E', 'L', '-',
#endif
	xStringify(MODULE_VERSION)[0], xStringify(MODULE_VERSION)[2], xStringify(MODULE_VERSION)[4], '-',
	getBuildYear<0>(), getBuildYear<1>(), getBuildYear<2>(), getBuildYear<3>(), '-',
	getBuildMonth<0>(), getBuildMonth<1>(), '-', getBuildDay<0>(), getBuildDay<1>(), '\0'
};

#endif

#ifndef LILU_CUSTOM_IOKIT_INIT

OSDefineMetaClassAndStructors(PRODUCT_NAME, IOService)

PRODUCT_NAME *ADDPR(selfInstance) = nullptr;

IOService *PRODUCT_NAME::probe(IOService *provider, SInt32 *score) {
	ADDPR(selfInstance) = this;
	setProperty("VersionInfo", kextVersion);
	auto service = IOService::probe(provider, score);
	return ADDPR(startSuccess) ? service : nullptr;
}

bool PRODUCT_NAME::start(IOService *provider) {
	ADDPR(selfInstance) = this;
	if (!IOService::start(provider)) {
		SYSLOG("init", "failed to start the parent");
		return false;
	}

	return ADDPR(startSuccess);
}

void PRODUCT_NAME::stop(IOService *provider) {
	ADDPR(selfInstance) = nullptr;
	IOService::stop(provider);
}

#endif /* LILU_CUSTOM_IOKIT_INIT */

#ifndef LILU_CUSTOM_KMOD_INIT

EXPORT extern "C" kern_return_t ADDPR(kern_start)(kmod_info_t *, void *) {
	// This is an ugly hack necessary on some systems where buffering kills most of debug output.
	PE_parse_boot_argn("liludelay", &ADDPR(debugPrintDelay), sizeof(ADDPR(debugPrintDelay)));

	auto error = lilu.requestAccess();
	if (error == LiluAPI::Error::NoError) {
		error = lilu.shouldLoad(ADDPR(config).product, ADDPR(config).version, ADDPR(config).runmode, ADDPR(config).disableArg, ADDPR(config).disableArgNum,
								ADDPR(config).debugArg, ADDPR(config).debugArgNum, ADDPR(config).betaArg, ADDPR(config).betaArgNum, ADDPR(config).minKernel,
								ADDPR(config).maxKernel, ADDPR(debugEnabled));

		if (error == LiluAPI::Error::NoError) {
			DBGLOG("init", "%s bootstrap %s", xStringify(PRODUCT_NAME), kextVersion);
			(void)kextVersion;
			ADDPR(startSuccess) = true;
			ADDPR(config).pluginStart();
		} else {
			SYSLOG("init", "parent said we should not continue %d", error);
		}

		lilu.releaseAccess();
	} else {
		SYSLOG("init", "failed to call parent %d", error);
	}

	// Report success but actually do not start and let I/O Kit unload us.
	// This works better and increases boot speed in some cases.
	return KERN_SUCCESS;
}

EXPORT extern "C" kern_return_t ADDPR(kern_stop)(kmod_info_t *, void *) {
	// It is not safe to unload Lilu plugins unless they were disabled!
	return ADDPR(startSuccess) ? KERN_FAILURE : KERN_SUCCESS;
}

#endif /* LILU_CUSTOM_KMOD_INIT */

#ifdef __MAC_10_15

// macOS 10.15 adds Dispatch function to all OSObject instances and basically
// every header is now incompatible with 10.14 and earlier.
// Here we add a stub to permit older macOS versions to link.
// Note, this is done in both kern_util and plugin_start as plugins will not link
// to Lilu weak exports from vtable.

kern_return_t WEAKFUNC PRIVATE OSObject::Dispatch(const IORPC rpc) {
	PANIC("util", "OSObject::Dispatch plugin stub called");
}

kern_return_t WEAKFUNC PRIVATE OSMetaClassBase::Dispatch(const IORPC rpc) {
	PANIC("util", "OSMetaClassBase::Dispatch plugin stub called");
}

#endif
