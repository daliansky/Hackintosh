//
//  kern_api.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_api_h
#define kern_api_h

#include <Headers/kern_config.hpp>
#include <Headers/kern_patcher.hpp>
#include <Headers/kern_user.hpp>
#include <Headers/kern_util.hpp>

#include <stdint.h>
#include <sys/types.h>
#include <libkern/OSAtomic.h>

class LiluAPI {
public:
	/**
	 *  Initialise lilu api
 	 */
	void init();

	/**
	 *  Deinitialise lilu api
	 */
	void deinit();

	/**
	 *  Errors returned by functions
	 */
	enum class Error {
		NoError,
		LockError,
		MemoryError,
		UnsupportedFeature,
		IncompatibleOS,
		Disabled,
		TooLate,
		Offline
	};

	/**
	 *  Minimal API version that guarantees forward ABI compatibility
	 *  Present due to lack of OSBundleCompatibleVersion at kext injection
	 */
	static constexpr size_t CompatibilityVersion {parseModuleVersion("1.2.0")};

	/**
	 *  Obtains api access by holding a lock, which is required when accessing out of the main context
	 *
	 *  @param version  api compatibility version
	 *  @param check    do not wait on the lock but return Error::LockError on failure
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error requestAccess(size_t version=CompatibilityVersion, bool check=false);

	/**
	 *  Releases api lock
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error releaseAccess();

	/**
	 *  You are supposed declare that your plugins work in at least one of these modes
	 *  It is assumed that single user mode is equal to normal, because it is generally
	 *  used to continue the load of a complete OS, and by default Lilu itself ignores it.
	 */
	enum RunningMode : uint32_t {
		RunningNormal            = 1,
		AllowNormal              = RunningNormal,
		RunningInstallerRecovery = 2,
		AllowInstallerRecovery   = RunningInstallerRecovery,
		RunningSafeMode          = 4,
		AllowSafeMode            = RunningSafeMode
	};

	/**
	 *  Obtain current run mode similarly to requirements
	 *
	 *  @return run mode mask (RunningMode)
	 */
	inline uint32_t getRunMode() {
		return currentRunMode;
	}

	/**
	 *  Decides whether you are eligible to continue
	 *
	 *  @param product       product name
	 *  @param version       product version
	 *  @param runmode       bitmask of allowed enviornments
	 *  @param disableArg    pointer to disabling boot arguments array
	 *  @param disableArgNum number of disabling boot arguments
	 *  @param debugArg      pointer to debug boot arguments array
	 *  @param debugArgNum   number of debug boot arguments
	 *  @param betaArg       pointer to beta boot arguments array
	 *  @param betaArgNum    number of beta boot arguments
	 *  @param min           minimal required kernel version
	 *  @param max           maximum supported kernel version
	 *  @param printDebug    returns debug printing status (based on debugArg)
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error shouldLoad(const char *product, size_t version, uint32_t runmode, const char **disableArg, size_t disableArgNum, const char **debugArg, size_t debugArgNum, const char **betaArg, size_t betaArgNum, KernelVersion min, KernelVersion max, bool &printDebug);

	/**
	 *  Kernel patcher loaded callback
	 *
	 *  @param user    user provided pointer at registering
	 *  @param patcher kernel patcher instance
	 */
	using t_patcherLoaded = void (*)(void *user, KernelPatcher &patcher);

	/**
	 *  Registers custom provided callbacks for later invocation on kernel patcher initialisation
	 *
	 *  @param callback your callback function
	 *  @param user     your pointer that will be passed to the callback function
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error onPatcherLoad(t_patcherLoaded callback, void *user=nullptr);

	/**
	 *  Registers custom provided callbacks for later invocation on kernel patcher initialisation
	 *  Enforced version, which panics on registration failure (assuming your code cannot continue otherwise)
	 *
	 *  @param callback your callback function
	 *  @param user     your pointer that will be passed to the callback function
	 */
	inline void onPatcherLoadForce(t_patcherLoaded callback, void *user=nullptr) {
		auto err = onPatcherLoad(callback, user);
		if (err != Error::NoError)
			PANIC("api", "onPatcherLoad failed with code %d", err);
	}

	/**
	 *  Kext loaded callback
	 *  Note that you will get notified of all the requested kexts for speed reasons
	 *
	 *  @param user    user provided pointer at registering
	 *  @param patcher kernel patcher instance
	 *  @param id      loaded kinfo id
	 *  @param slide   loaded slide
	 *  @param size    loaded memory size
	 */
	using t_kextLoaded = void (*)(void *user, KernelPatcher &patcher, size_t id, mach_vm_address_t slide, size_t size);

	/**
	 *  Registers custom provided callbacks for later invocation on kext load
	 *
	 *  @param infos    your kext list (make sure to point to const memory)
	 *  @param num      number of provided kext entries
	 *  @param callback your callback function (optional)
	 *  @param user     your pointer that will be passed to the callback function (optional)
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error onKextLoad(KernelPatcher::KextInfo *infos, size_t num=1, t_kextLoaded callback=nullptr, void *user=nullptr);

	/**
	 *  Registers custom provided callbacks for later invocation on kext load
	 *  Enforced version, which panics on registration failure (assuming your code cannot continue otherwise)
	 *
	 *  @param infos    your kext list (make sure to point to const memory)
	 *  @param num      number of provided kext entries
	 *  @param callback your callback function (optional)
	 *  @param user     your pointer that will be passed to the callback function (optional)
	 */
	inline void onKextLoadForce(KernelPatcher::KextInfo *infos, size_t num=1, t_kextLoaded callback=nullptr, void *user=nullptr) {
		auto err = onKextLoad(infos, num, callback, user);
		if (err != Error::NoError)
			PANIC("api", "onKextLoad failed with code %d", err);
	}

	/**
	 *  Registers custom provided callbacks for later invocation on binary load
	 *
	 *  @param infos    your binary list (make sure to point to const memory)
	 *  @param num      number of provided binary entries
	 *  @param callback your callback function (could be null)
	 *  @param user     your pointer that will be passed to the callback function
	 *  @param mods     optional mod list (make sure to point to const memory)
	 *  @param modnum   number of provided mod entries
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error onProcLoad(UserPatcher::ProcInfo *infos, size_t num=1, UserPatcher::t_BinaryLoaded callback=nullptr, void *user=nullptr, UserPatcher::BinaryModInfo *mods=nullptr, size_t modnum=0);

	/**
	 *  Registers custom provided callbacks for later invocation on binary load
	 *  Enforced version, which panics on registration failure (assuming your code cannot continue otherwise)
	 *
	 *  @param infos    your binary list (make sure to point to const memory)
	 *  @param num      number of provided binary entries
	 *  @param callback your callback function (could be null)
	 *  @param user     your pointer that will be passed to the callback function
	 *  @param mods     optional mod list (make sure to point to const memory)
	 *  @param modnum   number of provided mod entries
	 */
	inline void onProcLoadForce(UserPatcher::ProcInfo *infos, size_t num=1, UserPatcher::t_BinaryLoaded callback=nullptr, void *user=nullptr, UserPatcher::BinaryModInfo *mods=nullptr, size_t modnum=0) {
		auto err = onProcLoad(infos, num, callback, user, mods, modnum);
		if (err != Error::NoError)
			PANIC("api", "onProcLoad failed with code %d", err);
	}

	/**
	 *  Kext loaded callback
	 *  Note that you will get notified of all the requested kexts for speed reasons
	 *
	 *  @param user          user provided pointer at registering
	 *  @param task          task
	 *  @param entitlement   loaded kinfo id
	 *  @param original      original entitlement value
	 */
	using t_entitlementRequested = void (*)(void *user, task_t task, const char *entitlement, OSObject *&original);

	/**
	 *  Registers custom provided callbacks for later invocation on entitlement registration
	 *
	 *  @param callback your callback function
	 *  @param user     your pointer that will be passed to the callback function
	 *
	 *  @return Error::NoError on success
	 */
	EXPORT Error onEntitlementRequest(t_entitlementRequested callback, void *user=nullptr);

	/**
	 *  Registers custom provided callbacks for later invocation on entitlement registration
	 *  Enforced version, which panics on registration failure (assuming your code cannot continue otherwise)
	 *
	 *  @param callback your callback function
	 *  @param user     your pointer that will be passed to the callback function
	 */
	inline void onEntitlementRequestForce(t_entitlementRequested callback, void *user=nullptr) {
		auto err = onEntitlementRequest(callback, user);
		if (err != Error::NoError)
			PANIC("api", "onEntitlementRequest failed with code %d", err);
	}

	/**
	 *  Processes all the registered patcher load callbacks
	 *
	 *  @param patcher kernel patcher instance
	 */
	void processPatcherLoadCallbacks(KernelPatcher &patcher);

	/**
	 *  Processes all the registered kext load callbacks
	 *
	 *  @param patcher    kernel patcher instance
	 *  @param id         loaded kinfo id
	 *  @param slide      loaded slide
	 *  @param size       loaded memory size
	 *  @param reloadable kinfo could be unloaded
	 */
	void processKextLoadCallbacks(KernelPatcher &patcher, size_t id, mach_vm_address_t slide, size_t size, bool reloadable);

	/**
	 *  Processes all the registered user patcher load callbacks
	 *
	 *  @param patcher user patcher instance
	 */
	void processUserLoadCallbacks(UserPatcher &patcher);

	/**
	 *  Processes all the registered binary load callbacks
	 *
	 *  @param patcher kernel patcher instance
	 *  @param map     process image vm_map
	 *  @param path    path to the binary absolute or relative
	 *  @param len     path length excluding null terminator
	 */
	void processBinaryLoadCallbacks(UserPatcher &patcher, vm_map_t map, const char *path, size_t len);

	/**
	 *  Activates patchers
	 *
	 *  @param kpatcher  kernel patcher instance
	 *  @param upatcher  user patcher instance
	 */
	void activate(KernelPatcher &kpatcher, UserPatcher &upatcher);

private:

	/**
	 *  Api lock
	 */
	IOLock *access {nullptr};

	/**
	 *  Defines current running modes
	 */
	uint32_t currentRunMode {};

	/**
	 *  No longer accept any requests
	 */
	bool apiRequestsOver {false};

	/**
	 *  Stores call function and user pointer
	 */
	template <typename T, typename Y=void *>
	using stored_pair = ppair<T, Y>;

	/**
	 *  Stores multiple callbacks
	 */
	template <typename T, typename Y=void *>
	using stored_vector = evector<stored_pair<T, Y> *, stored_pair<T, Y>::deleter>;

	/**
	 *  List of patcher callbacks
	 */
	stored_vector<t_patcherLoaded> patcherLoadedCallbacks;

	/**
	 *  List of kext callbacks
	 */
	stored_vector<t_kextLoaded> kextLoadedCallbacks;

	/**
	 *  List of binary callbacks
	 */
	stored_vector<UserPatcher::t_BinaryLoaded> binaryLoadedCallbacks;

	/**
	 *  List of entitlement callbacks
	 */
	stored_vector<t_entitlementRequested> entitlementRequestedCallbacks;

	/**
	 *  List of processed kexts
	 */
	stored_vector<KernelPatcher::KextInfo *, size_t> storedKexts;

	/**
	 *  List of processed procs
	 */
	evector<UserPatcher::ProcInfo *> storedProcs;

	/**
	 *  List of processed binary mods
	 */
	evector<UserPatcher::BinaryModInfo *> storedBinaryMods;

	/**
	 *  Copy client entitlement type (see IOUserClient)
	 */
	using t_copyClientEntitlement = OSObject *(*)(task_t, const char *);

	/**
	 *  Hooked entitlement copying method
	 */
	static OSObject *copyClientEntitlement(task_t task, const char *entitlement);

	/**
	 *  Trampoline for original entitlement copying method
	 */
	t_copyClientEntitlement orgCopyClientEntitlement {nullptr};
};

EXPORT extern LiluAPI lilu;

#endif /* kern_api_h */
