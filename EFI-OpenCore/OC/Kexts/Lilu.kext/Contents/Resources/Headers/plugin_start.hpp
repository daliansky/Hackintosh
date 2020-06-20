//
//  kern_start.hpp
//  AppleALC
//
//  Copyright © 2016 vit9696. All rights reserved.
//

#ifndef kern_start_hpp
#define kern_start_hpp

#include <Headers/kern_util.hpp>

#include <Library/LegacyIOService.h>
#include <sys/types.h>

struct PluginConfiguration {
	const char *product;        // Product name (e.g. xStringify(PRODUCT_NAME))
	size_t version;             // Product version (e.g. parseModuleVersion(xStringify(MODULE_VERSION)))
	uint32_t runmode;           // Product supported environments (e.g. LiluAPI::AllowNormal)
	const char **disableArg;    // Pointer to disabling boot arguments array
	size_t disableArgNum;       // Number of disabling boot arguments
	const char **debugArg;      // Pointer to debug boot arguments array
	size_t debugArgNum;         // Number of debug boot arguments
	const char **betaArg;       // Pointer to beta boot arguments array
	size_t betaArgNum;          // Number of beta boot arguments
	KernelVersion minKernel;    // Minimal required kernel version
	KernelVersion maxKernel;    // Maximum supported kernel version
	void (*pluginStart)();      // Main function
};

#ifndef LILU_CUSTOM_KMOD_INIT

extern PluginConfiguration ADDPR(config);

extern bool ADDPR(startSuccess);

#endif /* LILU_CUSTOM_KMOD_INIT */

#ifndef LILU_CUSTOM_IOKIT_INIT

class EXPORT PRODUCT_NAME : public IOService {
	OSDeclareDefaultStructors(PRODUCT_NAME)
public:
	IOService *probe(IOService *provider, SInt32 *score) override;
	bool start(IOService *provider) override;
	void stop(IOService *provider) override;
};

extern PRODUCT_NAME *ADDPR(selfInstance);

#endif /* LILU_CUSTOM_IOKIT_INIT */

#endif /* kern_start_hpp */
