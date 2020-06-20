//
//  kern_patcher.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_patcher_hpp
#define kern_patcher_hpp

#include <Headers/kern_config.hpp>
#include <Headers/kern_compat.hpp>
#include <Headers/kern_util.hpp>
#include <Headers/kern_mach.hpp>
#include <Headers/kern_disasm.hpp>

#include <mach/mach_types.h>

namespace Patch { union All; void deleter(All * NONNULL); }
#ifdef LILU_KEXTPATCH_SUPPORT
struct OSKextLoadedKextSummaryHeader;
struct OSKextLoadedKextSummary;
#endif /* LILU_KEXTPATCH_SUPPORT */

class KernelPatcher {
public:

	/**
	 *  Errors set by functions
	 */
	enum class Error {
		NoError,
		NoKinfoFound,
		NoSymbolFound,
		KernInitFailure,
		KernRunningInitFailure,
		KextListeningFailure,
		DisasmFailure,
		MemoryIssue,
		MemoryProtection,
		PointerRange,
		AlreadyDone,
		LockError,
		Unsupported,
		InvalidSymbolFound
	};

	/**
	 *  Get last error
	 *
	 *  @return error code
	 */
	EXPORT Error getError();

	/**
	 *  Reset all the previous errors
	 */
	EXPORT void clearError();

	/**
	 *  Initialise KernelPatcher, prepare for modifications
	 */
	void init();

	/**
	 *  Deinitialise KernelPatcher, must be called regardless of the init error
	 */
	void deinit();

	/**
	 *  Kernel write lock used for performing kernel & kext writes to disable cpu preemption
	 *  See MachInfo::setKernelWriting
	 */
	EXPORT static IOSimpleLock *kernelWriteLock;

	/**
	 *  Kext information
	 */
	struct KextInfo;

#ifdef LILU_KEXTPATCH_SUPPORT
	struct KextInfo {
		static constexpr size_t Unloaded {0};
		enum SysFlags : size_t {
			Loaded,      // invoke for kext if it is already loaded
			Reloadable,  // allow the kext to unload and get patched again
			Disabled,    // do not load this kext (formerly achieved pathNum = 0, this no longer works)
			FSOnly,      // do not use prelinkedkernel (kextcache) as a symbol source
			FSFallback,  // perform fs fallback if kextcache failed
			Reserved,
			SysFlagNum,
		};
		static constexpr size_t UserFlagNum {sizeof(size_t)-SysFlagNum};
		static_assert(UserFlagNum > 0, "There should be at least one user flag");
		const char *id {nullptr};
		const char **paths {nullptr};
		size_t pathNum {0};
		bool sys[SysFlagNum] {};
		bool user[UserFlagNum] {};
		size_t loadIndex {Unloaded}; // Updated after loading

		/**
		 *  Disable this info from being used
		 *  May be called from onPatcherLoad callbacks to disable certain kexts
		 */
		void switchOff() {
			sys[KernelPatcher::KextInfo::Disabled] = true;
		}
	};

	static_assert(sizeof(KextInfo) == 5 * sizeof(size_t), "KextInfo is no longer ABI compatible");
#endif /* LILU_KEXTPATCH_SUPPORT */

	/**
	 *  Loads and stores kinfo information locally
	 *
	 *  @param id         kernel item identifier
	 *  @param paths      item filesystem path array
	 *  @param num        number of path entries
	 *  @param isKernel   kinfo is kernel info
	 *  @param fsonly     avoid using prelinkedkernel for kexts
	 *  @param fsfallback fallback to reading from filesystem if prelink failed
	 *
	 *  @return loaded kinfo id
	 */
	EXPORT size_t loadKinfo(const char *id, const char * const paths[], size_t num=1, bool isKernel=false, bool fsonly=false, bool fsfallback=false);

#ifdef LILU_KEXTPATCH_SUPPORT
	/**
	 *  Loads and stores kinfo information locally
	 *
	 *  @param info kext to load, updated on success
	 *
	 *  @return loaded kinfo id
	 */
	EXPORT size_t loadKinfo(KextInfo *info);
#endif /* LILU_KEXTPATCH_SUPPORT */

	/**
	 *  Kernel kinfo id
	 */
	static constexpr size_t KernelID {0};

	/**
	 *  Update running information
	 *
	 *  @param id    loaded kinfo id
	 *  @param slide loaded slide
	 *  @param size  loaded memory size
	 *  @param force force recalculatiob
	 */
	EXPORT void updateRunningInfo(size_t id, mach_vm_address_t slide=0, size_t size=0, bool force=false);

	/**
	 *  Any kernel
	 */
	static constexpr uint32_t KernelAny {0};

	/**
	 *  Check kernel compatibility
	 *
	 *  @param min minimal requested version or KernelAny
	 *  @param max maximum supported version or KernelAny
	 *
	 *  @return true on success
	 */
	EXPORT static bool compatibleKernel(uint32_t min, uint32_t max);

	/**
	 *  Erase coverage instruction prefix (like inc qword ptr[]), that causes function routing to fail
	 *
	 *  @param addr   address to valid instruction code
	 *  @param count  amount of instructions to inspect
	 */
	EXPORT void eraseCoverageInstPrefix(mach_vm_address_t addr, size_t count=5);

	/**
	 *  Erase coverage instruction prefix (like inc qword ptr[]), that causes function routing to fail
	 *
	 *  @param addr   address to valid instruction code
	 *  @param count  amount of instructions to inspect
	 *  @param limit  amount of bytes to inspect
	 */
	EXPORT void eraseCoverageInstPrefix(mach_vm_address_t addr, size_t count, off_t limit);

	/**
	 *  Solve a kinfo symbol
	 *
	 *  @param id      loaded kinfo id
	 *  @param symbol  symbol to solve
	 *
	 *  @return running symbol address or 0
	 */
	EXPORT mach_vm_address_t solveSymbol(size_t id, const char *symbol);

	/**
	 *  Solve a kinfo symbol in range with designated type
	 *
	 *  @param id      loaded kinfo id
	 *  @param symbol  symbol to solve
	 *  @param start   start address range
	 *  @param size    address range size
	 *  @param crash   kernel panic on invalid non-zero address
	 *
	 *  @return running symbol address or 0 casted to type T (mach_vm_address_t)
	 */
	template <typename T = mach_vm_address_t>
	inline T solveSymbol(size_t id, const char *symbol, mach_vm_address_t start, size_t size, bool crash=false) {
		auto addr = solveSymbol(id, symbol);
		if (addr) {
			if (addr >= start && addr < start + size)
				return (T)addr;

			code = Error::InvalidSymbolFound;
			SYSTRACE("patcher", "address " PRIKADDR " is out of range " PRIKADDR " with size %lX",
				CASTKADDR(addr), CASTKADDR(start), size);

			PANIC_COND(crash, "patcher", "address " PRIKADDR " is out of range " PRIKADDR " with size %lX",
				CASTKADDR(addr), CASTKADDR(start), size);
		}

		return (T)nullptr;
	}

	/**
	 *  Hook kext loading and unloading to access kexts at early stage
	 */
	EXPORT void setupKextListening();

	/**
	 *  Free file buffer resources and effectively make prelinked kext loading impossible
	 */
	void freeFileBufferResources();

	/**
	 *  Activates monitoring functions if necessary
	 */
	void activate();

	/**
	 *  Load handling structure
	 */
	class KextHandler {
		using t_handler = void (*)(KextHandler *);
		KextHandler(const char * const i, size_t idx, t_handler h, bool l, bool r) :
			id(i), index(idx), handler(h), loaded(l), reloadable(r) {}
	public:
		static KextHandler *create(const char * const i, size_t idx, t_handler h, bool l=false, bool r=false) {
			return new KextHandler(i, idx, h, l, r);
		}
		static void deleter(KextHandler *i NONNULL) {
			delete i;
		}

		void *self {nullptr};
		const char * const id {nullptr};
		size_t index {0};
		mach_vm_address_t address {0};
		size_t size {0};
		t_handler handler {nullptr};
		bool loaded {false};
		bool reloadable {false};
	};

#ifdef LILU_KEXTPATCH_SUPPORT
	/**
	 *  Enqueue handler processing at kext loading
	 *
	 *  @param handler  handler to process
	 */
	EXPORT void waitOnKext(KextHandler *handler);

	/**
	 *  Update kext handler features
	 *
	 *  @param info  loaded kext info with features
	 */
	void updateKextHandlerFeatures(KextInfo *info);

	/**
	 *  Arbitrary kext find/replace patch
	 */
	struct LookupPatch {
		KextInfo *kext;
		const uint8_t *find;
		const uint8_t *replace;
		size_t size;
		size_t count;
	};

	/**
	 *  Apply a find/replace patch
	 *
	 *  @param patch patch to apply
	 */
	EXPORT void applyLookupPatch(const LookupPatch *patch);

	/**
	 *  Apply a find/replace patch with additional constraints
	 *
	 *  @param patch              patch to apply
	 *  @param startingAddress    start with this address (or kext/kernel lowest address)
	 *  @param maxSize            maximum size to lookup (or kext/kernel max size)
	 */
	EXPORT void applyLookupPatch(const LookupPatch *patch, uint8_t *startingAddress, size_t maxSize);
#endif /* LILU_KEXTPATCH_SUPPORT */

	/**
	 *  Route function to function
	 *
	 *  @param from         function to route
	 *  @param to           routed function
	 *  @param buildWrapper create entrance wrapper
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param revertible   patches could be reverted
	 *
	 *  @return wrapper pointer or 0 on success
	 */
	EXPORT mach_vm_address_t routeFunction(mach_vm_address_t from, mach_vm_address_t to, bool buildWrapper=false, bool kernelRoute=true, bool revertible=true);

	/**
	 *  Route function to function with long jump
	 *
	 *  @param from         function to route
	 *  @param to           routed function
	 *  @param buildWrapper create entrance wrapper
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param revertible   patches could be reverted
	 *
	 *  @return wrapper pointer or 0 on success
	 */
	EXPORT mach_vm_address_t routeFunctionLong(mach_vm_address_t from, mach_vm_address_t to, bool buildWrapper=false, bool kernelRoute=true, bool revertible=true);

	/**
	 *  Route function to function with short jump
	 *
	 *  @param from         function to route
	 *  @param to           routed function
	 *  @param buildWrapper create entrance wrapper
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param revertible   patches could be reverted
	 *
	 *  @return wrapper pointer or 0 on success
	 */
	EXPORT mach_vm_address_t routeFunctionShort(mach_vm_address_t from, mach_vm_address_t to, bool buildWrapper=false, bool kernelRoute=true, bool revertible=true);

	/**
	 *  Route block at assembly level
	 *
	 *  @param from         address to route
	 *  @param opcodes      opcodes to insert
	 *  @param opnum        number of opcodes
	 *  @param buildWrapper create entrance wrapper
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *
	 *  @return wrapper pointer or 0 on success
	 */
	EXPORT mach_vm_address_t routeBlock(mach_vm_address_t from, const uint8_t *opcodes, size_t opnum, bool buildWrapper=false, bool kernelRoute=true);

	/**
	 *  Route virtual function to function
	 *
	 *  @param obj      OSObject-compatible instance
	 *  @param off      function offset in a virtual table (arch-neutral, i.e. divided by sizeof(uintptr_t)
	 *  @param func     function to replace with
	 *  @param orgFunc  pointer to store the original function
	 *
	 *  @return true on success
	 */
	template <typename T>
	static inline bool routeVirtual(void *obj, size_t off, T func, T *orgFunc=nullptr) {
		// First OSObject (and similar) field is its virtual table.
		auto vt = obj ? reinterpret_cast<T **>(obj)[0] : nullptr;
		if (vt) {
			// Do not try to replace twice!
			if (vt[off] == func)
				return false;
			if (orgFunc) *orgFunc = vt[off];
			vt[off] = func;
			return true;
		}
		return false;
	}

	/**
	 *  Route request to simplify casting and error handling
	 *  See routeMultiple.
	 *
	 *  symbol  symbol to lookup
	 *  from    solved symbol (assigned by routeMultiple)
	 *  to      destination address
	 *  org     trampoline storage to the original symbol
	 */
	struct RouteRequest {
		const char *symbol {nullptr};
		mach_vm_address_t from {0};
		const mach_vm_address_t to {0};
		mach_vm_address_t *org {nullptr};

		/**
		 *  Construct RouteRequest for wrapping a function
		 *  @param s  symbol to lookup
		 *  @param t  destination address
		 *  @param o  trampoline storage to the original symbol
		 */
		template <typename T>
		RouteRequest(const char *s, T t, mach_vm_address_t &o) :
			symbol(s), to(reinterpret_cast<mach_vm_address_t>(t)), org(&o) { }

		/**
		 *  Construct RouteRequest for routing a function
		 *  @param s  symbol to lookup
		 *  @param t  destination address
		 */
		template <typename T>
		RouteRequest(const char *s, T t) :
			symbol(s), to(reinterpret_cast<mach_vm_address_t>(t)) { }
	};

	/**
	 *  Simple route multiple functions with basic error handling
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param num          requests array size
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *
	 *  @return false if it at least one error happened
	 */
	EXPORT bool routeMultiple(size_t id, RouteRequest *requests, size_t num, mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false);

	/**
	 *  Simple route multiple functions with basic error handling with long routes
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param num          requests array size
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *
	 *  @return false if it at least one error happened
	 */
	EXPORT bool routeMultipleLong(size_t id, RouteRequest *requests, size_t num, mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false);

	/**
	 *  Simple route multiple functions with basic error handling with short routes
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param num          requests array size
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *
	 *  @return false if it at least one error happened
	 */
	EXPORT bool routeMultipleShort(size_t id, RouteRequest *requests, size_t num, mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false);

	/**
	 *  Simple route multiple functions with basic error handling
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *
	 *  @return false if it at least one error happened
	 */
	template <size_t N>
	inline bool routeMultiple(size_t id, RouteRequest (&requests)[N], mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false) {
		return routeMultiple(id, requests, N, start, size, kernelRoute, force);
	}

	/**
	 *  Simple route multiple functions with basic error handling with long routes
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *
	 *  @return false if it at least one error happened
	 */
	template <size_t N>
	inline bool routeMultipleLong(size_t id, RouteRequest (&requests)[N], mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false) {
		return routeMultipleLong(id, requests, N, start, size, kernelRoute, force);
	}

	/**
	 *  Simple route multiple functions with basic error handling with long routes
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *
	 *  @return false if it at least one error happened
	 */
	template <size_t N>
	inline bool routeMultipleShort(size_t id, RouteRequest (&requests)[N], mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false) {
		return routeMultipleShort(id, requests, N, start, size, kernelRoute, force);
	}

private:
	/**
	 *  Jump type for routing
	 */
	enum class JumpType {
		Auto,
		Long,
		Short
	};

	/**
	 *  The minimal reasonable memory requirement
	 */
	static constexpr size_t TempExecutableMemorySize {4096};

	/**
	 *  As of 10.12 we seem to be not allowed to call vm_ functions from several places including onKextSummariesUpdated.
	 */
	static uint8_t tempExecutableMemory[TempExecutableMemorySize];

	/**
	 *  Offset to tempExecutableMemory that is safe to use
	 */
	size_t tempExecutableMemoryOff {0};

	/**
	 *  Patcher status
	 */
	bool activated {false};

	/**
	 *  Read previous jump destination from function
	 *
	 *  @param from         formerly routed function
	 *
	 *  @return wrapper pointer on success or 0
	 */
	mach_vm_address_t readChain(mach_vm_address_t from);

	/**
	 *  Created routed trampoline page
	 *
	 *  @param func     original area
	 *  @param min      minimal amount of bytes that will be overwritten
	 *  @param opcodes  opcodes to insert before function
	 *  @param opnum    number of opcodes
	 *
	 *  @return trampoline pointer or 0
	 */
	mach_vm_address_t createTrampoline(mach_vm_address_t func, size_t min, const uint8_t *opcodes=nullptr, size_t opnum=0);

	/**
	 *  Route function to function
	 *
	 *  @param from         function to route
	 *  @param to           routed function
	 *  @param buildWrapper create entrance wrapper
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param revertible   patches could be reverted
	 *  @param jumpType     jump type to use, relative short or absolute long
	 *
	 *  @return wrapper pointer or 0 on success
	 */
	mach_vm_address_t routeFunctionInternal(mach_vm_address_t from, mach_vm_address_t to, bool buildWrapper=false, bool kernelRoute=true, bool revertible=true, JumpType jumpType=JumpType::Auto);

	/**
	 *  Simple route multiple functions with basic error handling with long routes
	 *
	 *  @param id           kernel item identifier
	 *  @param requests     an array of requests to replace
	 *  @param num          requests array size
	 *  @param start        start address range
	 *  @param size         address range size
	 *  @param kernelRoute  kernel change requiring memory protection changes and patch reverting at unload
	 *  @param force        continue on first error
	 *  @param jumpType     jump type to use, relative short or absolute long
	 *
	 *  @return false if it at least one error happened
	 */
	bool routeMultipleInternal(size_t id, RouteRequest *requests, size_t num, mach_vm_address_t start=0, size_t size=0, bool kernelRoute=true, bool force=false, JumpType jumpType=JumpType::Auto);

#ifdef LILU_KEXTPATCH_SUPPORT
	/**
	 *  Called at kext loading and unloading if kext listening is enabled
	 */
	static void onKextSummariesUpdated();

	/**
	 *  A pointer to loaded kext information
	 */
	OSKextLoadedKextSummaryHeader **loadedKextSummaries {nullptr};

	/**
	 *  A pointer to kext summaries update
	 */
	void (*orgUpdateLoadedKextSummaries)(void) {nullptr};

	/**
	 *  Process already loaded kexts once at the start
	 *
	 *  @param summaries loaded kext summaries
	 *  @param num       number of loaded kext summaries
	 */
	void processAlreadyLoadedKexts(OSKextLoadedKextSummary *summaries, size_t num);

#endif /* LILU_KEXTPATCH_SUPPORT */

	/**
	 *  Kernel prelink image in case prelink is used
	 */
	MachInfo *prelinkInfo {nullptr};

	/**
	 *  Loaded kernel items
	 */
	evector<MachInfo *, MachInfo::deleter> kinfos;

	/**
	 *  Applied patches
	 */
	evector<Patch::All *, Patch::deleter> kpatches;

#ifdef LILU_KEXTPATCH_SUPPORT	
	/**
	 *  Awaiting kext notificators
	 */
	evector<KextHandler *, KextHandler::deleter> khandlers;

	/**
	 *  Awaiting already loaded kext list
	 */
	bool waitingForAlreadyLoadedKexts {false};

#endif /* LILU_KEXTPATCH_SUPPORT */

	/**
	 *  Current error code
	 */
	Error code {Error::NoError};
	static constexpr size_t INVALID {0};

	/**
	 *  Jump instruction sizes
	 */
	static constexpr size_t SmallJump {1 + sizeof(int32_t)};
	static constexpr size_t LongJump {6 + sizeof(uint64_t)};
	static constexpr uint8_t SmallJumpPrefix {0xE9};
	static constexpr uint16_t LongJumpPrefix {0x25FF};

	/**
	 *  Possible kernel paths
	 */
#ifdef LILU_COMPRESSION_SUPPORT
	const char *prelinkKernelPaths[6] {
		// This is the usual kernel cache place, which often the best thing to use
		"/System/Library/Caches/com.apple.kext.caches/Startup/kernelcache",
		// Otherwise fallback to one of the prelinked kernels
		// Since we always verify the LC_UUID value, trying the kernels could be done in any order.
		"/System/Library/PrelinkedKernels/prelinkedkernel", // normal
		"/macOS Install Data/Locked Files/Boot Files/prelinkedkernel", // 10.13 installer
		"/com.apple.boot.R/prelinkedkernel", // 10.12+ fusion drive installer
		"/com.apple.boot.S/System/Library/PrelinkedKernels/prelinkedkernel", // 10.11 fusion drive installer
		"/com.apple.recovery.boot/prelinkedkernel" // recovery
	};
#endif

	const char *kernelPaths[2] {
		"/System/Library/Kernels/kernel",	//since 10.10
		"/mach_kernel"
	};
};

#endif /* kern_patcher_hpp */
