//
//  kern_user.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_user_hpp
#define kern_user_hpp

#include <Headers/kern_config.hpp>
#include <Headers/kern_patcher.hpp>

#include <mach/shared_region.h>
#include <sys/kauth.h>

class UserPatcher {
public:
	/**
	 *  Initialise UserPatcher, prepare for modifications
	 *
	 *  @param patcher        kernel patcher instance
	 *  @param preferSlowMode policy boot type
	 *
	 *  @return true on success
	 */
	bool init(KernelPatcher &patcher, bool preferSlowMode);

	/**
	 *  Deinitialise UserPatcher, must be called regardless of the init error
	 */
	void deinit();

	/**
	 *  Obtain page protection
	 *
	 *  @param map  vm map
	 *  @param addr map offset
	 *
	 *  @return protection
	 */
	EXPORT vm_prot_t getPageProtection(vm_map_t map, vm_map_address_t addr);

	/**
	 *  Mach segment/section references for patch locations
	 */
	enum FileSegment : uint32_t {
		SegmentsTextStart,
		SegmentTextText = SegmentsTextStart,
		SegmentTextStubs,
		SegmentTextConst,
		SegmentTextCstring,
		SegmentTextUstring,
		SegmentsTextEnd = SegmentTextUstring,
		SegmentsDataStart,
		SegmentDataConst = SegmentsDataStart,
		SegmentDataCfstring,
		SegmentDataCommon,
		SegmentsDataEnd = SegmentDataCommon,
		SegmentTotal
	};

	/**
	 *  Mach segment names kept in sync with FileSegment
	 */
	const char *fileSegments[SegmentTotal] {
		"__TEXT",
		"__TEXT",
		"__TEXT",
		"__TEXT",
		"__TEXT",
		"__DATA",
		"__DATA",
		"__DATA"
	};

	/**
	 *  Mach section names kept in sync with FileSegment
	 */
	const char *fileSections[SegmentTotal] {
		"__text",
		"__stubs",
		"__const",
		"__cstring",
		"__ustring",
		"__const",
		"__cfstring",
		"__common"
	};

	/**
	 * Binary modification patches flags
	 */
	enum BinaryModPatchFlags {
		/*
		 * Only applies to one process, not globally.
		 */
		LocalOnly = 1
	};

	/**
	 *  Structure holding lookup-style binary patches
	 */
	struct BinaryModPatch {
		cpu_type_t cpu;
		uint32_t flags;
		const uint8_t *find;
		const uint8_t *replace;
		size_t size;
		size_t skip;
		size_t count;
		FileSegment segment;
		uint32_t section;
	};

	static_assert(sizeof(BinaryModPatch) == 56, "BinaryModPatch ABI compatibility failure");

	/**
	 *  Structure describing the modifications for the binary
	 */
	struct BinaryModInfo {
		const char *path;
		BinaryModPatch *patches;
		size_t count;
		vm_address_t startTEXT;
		vm_address_t endTEXT;
		vm_address_t startDATA;
		vm_address_t endDATA;
	};

	/**
	 *  Structure describing relevant processes run
	 */
	struct ProcInfo {
		/**
		 *  Process matching flags
		 */
		enum ProcFlags {
			MatchExact  = 0,
			MatchAny    = 1,
			MatchPrefix = 2,
			MatchSuffix = 4,
			MatchMask   = MatchExact | MatchAny | MatchPrefix | MatchSuffix
		};

		/**
		 *  Unused (aka disabled) proc info section
		 */
		static constexpr uint32_t SectionDisabled {0};

		const char *path {nullptr};
		uint32_t len {0};
		uint32_t section {SectionDisabled};
		uint32_t flags {MatchExact};
	};

	/**
	 *  External callback type for on process invocation
	 *
	 *  @param user    user provided pointer at registering
	 *  @param patcher user patcher instance
	 *  @param map     process image vm_map
	 *  @param path    path to the binary absolute or relative
	 *  @param len     path length excluding null terminator
	 */
	using t_BinaryLoaded = void (*)(void *user, UserPatcher &patcher, vm_map_t map, const char *path, size_t len);

	/**
	 *  Instructs user patcher to do further actions
	 *
	 *  @param procs    process list
	 *  @param procNum  process list size
	 *  @param mods     modification list
	 *  @param modNum   modification list size
	 *  @param callback callback function
	 *  @param user     pointer that will be passed to the callback function
	 */
	bool registerPatches(ProcInfo **procs, size_t procNum, BinaryModInfo **mods, size_t modNum, t_BinaryLoaded callback, void *user);

	/**
	 *  Reads current process header
	 *
	 *  @param map     vm map
	 *  @param header  Mach-O header
	 *
	 *  @return false on failure
	 */
	EXPORT bool getTaskHeader(vm_map_t map, mach_header_64 &header);

	/**
	 *  Disables dyld_shared_cache for the current process
	 *
	 *  @param map  vm map
	 *
	 *  @return false on mach image failure
	 */
	EXPORT bool injectRestrict(vm_map_t map);

	/**
	 *  Injects payload into the process right after the header with EP replacement.
	 *
	 *  @param map      vm map
	 *  @param payload  code
	 *  @param size     code size (up to PAGE_SIZE)
	 *  @param ep       original entrypoint (may be written to code before copying)
	 *
	 *  @return false on mach image failure
	 */
	EXPORT bool injectPayload(vm_map_t map, uint8_t *payload, size_t size, void *ep=nullptr);

	/**
	 *  Allocates a new segment in the process.
	 *
	 *  @param map      vm map
	 *  @param addr     allocation address (e.g. a little below SHARED_REGION_BASE_X86_64)
	 *  @param payload  code
	 *  @param size     code size (must be PAGE_SIZE-aligned)
	 *  @param prot     segment protection
	 *
	 *  @return allocated address or 0 on failure
	 */
	EXPORT vm_address_t injectSegment(vm_map_t taskPort, vm_address_t addr, uint8_t *payload, size_t size, vm_prot_t prot);

	/**
	 *  Activates monitoring functions if necessary
	 */
	void activate();

private:

	/**
	 *  Kernel function prototypes
	 */
	using vm_shared_region_t = void *;
	using shared_file_mapping_np = void *;
	using t_currentMap = vm_map_t (*)(void);
	using t_getTaskMap = vm_map_t (*)(task_t);
	using t_getMapMin = vm_map_offset_t (*)(vm_map_t);
	using t_vmMapSwitchProtect = void (*)(vm_map_t, boolean_t);
	using t_vmMapCheckProtection = boolean_t (*)(vm_map_t, vm_offset_t, vm_offset_t, vm_prot_t);
	using t_vmMapReadUser = kern_return_t (*)(vm_map_t, vm_map_address_t, const void *, vm_size_t);
	using t_vmMapWriteUser = kern_return_t (*)(vm_map_t, const void *, vm_map_address_t, vm_size_t);

	/**
	 *  Original kernel function trampolines
	 */
	mach_vm_address_t orgCodeSignValidatePageWrapper {};
	mach_vm_address_t orgCodeSignValidateRangeWrapper {};
	mach_vm_address_t orgVmSharedRegionMapFile {};
	mach_vm_address_t orgVmSharedRegionSlide {};
	mach_vm_address_t orgVmSharedRegionSlideMojave {};
	t_currentMap orgCurrentMap {nullptr};
	t_getMapMin orgGetMapMin {nullptr};
	t_getTaskMap orgGetTaskMap {nullptr};
	t_vmMapSwitchProtect orgVmMapSwitchProtect {nullptr};
	t_vmMapCheckProtection orgVmMapCheckProtection {nullptr};
	t_vmMapReadUser orgVmMapReadUser {nullptr};
	t_vmMapWriteUser orgVmMapWriteUser {nullptr};
	mach_vm_address_t orgTaskSetMainThreadQos {};

	/**
	 *  Kernel function wrappers
	 */
	static boolean_t codeSignValidatePageWrapper(void *blobs, memory_object_t pager, memory_object_offset_t page_offset, const void *data, unsigned *tainted);
	static boolean_t codeSignValidateRangeWrapper(void *blobs, memory_object_t pager, memory_object_offset_t range_offset, const void *data, memory_object_size_t data_size, unsigned *tainted);
	static vm_map_t swapTaskMap(task_t task, thread_t thread, vm_map_t map, boolean_t doswitch);
	static vm_map_t vmMapSwitch(vm_map_t map);
	static kern_return_t vmSharedRegionMapFile(vm_shared_region_t shared_region, unsigned int mappings_count, shared_file_mapping_np *mappings, memory_object_control_t file_control, memory_object_size_t file_size, void *root_dir, uint32_t slide, user_addr_t slide_start, user_addr_t slide_size);
	static void execsigs(proc_t p, thread_t thread);
	static int vmSharedRegionSlide(uint32_t slide, mach_vm_offset_t entry_start_address, mach_vm_size_t entry_size, mach_vm_offset_t slide_start, mach_vm_size_t slide_size, memory_object_control_t sr_file_control);
	static int vmSharedRegionSlideMojave(uint32_t slide, mach_vm_offset_t entry_start_address, mach_vm_size_t entry_size, mach_vm_offset_t slide_start, mach_vm_size_t slide_size, mach_vm_offset_t slid_mapping, memory_object_control_t sr_file_control);
	static void taskSetMainThreadQos(task_t task, thread_t main_thread);

	/**
	 *  Applies page patches to the memory range
	 *
	 *  @param data_ptr  pages in kernel memory
	 *  @param data_size data size divisible by PAGE_SIZE
	 */
	void performPagePatch(const void *data_ptr, size_t data_size);

	/**
	 * dyld shared cache map entry structure
	 */
	struct MapEntry {
		const char *filename;
		size_t length;
		vm_address_t startTEXT;
		vm_address_t endTEXT;
		vm_address_t startDATA;
		vm_address_t endDATA;
	};

	/**
	 *  Obtains __TEXT addresses from .map files
	 *
	 *  @param mapBuf     read .map file
	 *  @param mapSz      .map file size
	 *  @param mapEntries entries to look for
	 *  @param nentries   number of entries
	 *
	 *  @return number of entries found
	 */
	size_t mapAddresses(const char *mapBuf, MapEntry *mapEntries, size_t nentries);

	/**
	 *  Stored ASLR slide of dyld shared cache
	 */
	uint32_t storedSharedCacheSlide {0};

	/**
	 *  Set once shared cache slide is defined
	 */
	bool sharedCacheSlideStored {false};

	/**
	 *  Set on init to decide on whether to use __RESTRICT or patch dyld shared cache
	 */
	bool patchDyldSharedCache {false};

	/**
	 *  Kernel patcher instance
	 */
	KernelPatcher *patcher {nullptr};

	/**
	 *  Pending callback entry
	 */
	struct PendingUser {
		/**
		 *  Patch requested for path
		 */
		char path[MAXPATHLEN] {};

		/**
		 *  Patch requested for path
		 */
		uint32_t pathLen {0};
	};

	/**
	 *  Stored pending callback
	 */
	ThreadLocal<PendingUser *, 32> pending;

	/**
	 *  Current minimal proc name length
	 */
	uint32_t currentMinProcLength {0};

	/**
	 *  Provided binary modification list
	 */
	BinaryModInfo **binaryMod {nullptr};

	/**
	 *  Amount of provided binary modifications
	 */
	size_t binaryModSize {0};

	/**
	 *  Provided process list
	 */
	ProcInfo **procInfo {nullptr};

	/**
	 *  Amount of provided processes
	 */
	size_t procInfoSize {0};

	/**
	 *  Provided global callback for on proc invocation
	 */
	ppair<t_BinaryLoaded, void *> userCallback {};

	/**
	 *  Applies dyld shared cache patches
	 *
	 *  @param map     current process map
	 *  @param slide   ASLR offset
	 *  @param cpu     cache cpu type
	 *  @param restore true to rollback the changes
	 */
	void patchSharedCache(vm_map_t map, uint32_t slide, cpu_type_t cpu, bool applyChanges=true);

	/**
	 *  Structure holding userspace lookup patches
	 */
	struct LookupStorage {
		struct PatchRef {
			size_t i {0};
			evector<off_t> pageOffs;
			evector<off_t> segOffs;
			static PatchRef *create() {
				return new PatchRef;
			}
			static void deleter(PatchRef *r NONNULL) {
				r->pageOffs.deinit();
				r->segOffs.deinit();
				delete r;
			}
		};

		const BinaryModInfo *mod {nullptr};
		evector<PatchRef *, PatchRef::deleter> refs;
		Page *page {nullptr};
		vm_address_t pageOff {0};

		static LookupStorage *create() {
			auto p = new LookupStorage;
			if (p) {
				p->page = Page::create();
				if (!p->page) {
					deleter(p);
					p = nullptr;
				}
			}
			return p;
		}

		static void deleter(LookupStorage *p NONNULL) {
			if (p->page) {
				Page::deleter(p->page);
				p->page = nullptr;
			}
			p->refs.deinit();
			delete p;
		}
	};

	struct Lookup {
		uint32_t offs[4] {};
		static constexpr size_t matchNum {4};
		evector<uint64_t> c[matchNum];
	};

	evector<LookupStorage *, LookupStorage::deleter> lookupStorage;
	Lookup lookup;

	/**
	 *  Restrict 64-bit entry overlapping DYLD_SHARED_CACHE to enforce manual library loading
	 */
	segment_command_64 restrictSegment64 {
		LC_SEGMENT_64,
		sizeof(segment_command_64),
		"__RESTRICT",
		SHARED_REGION_BASE_X86_64,
		1, 0, 0, 0, 0, 0, 0
	};

	/**
	 *  Restrict 32-bit entry overlapping DYLD_SHARED_CACHE to enforce manual library loading
	 */
	segment_command restrictSegment32 {
		LC_SEGMENT,
		sizeof(segment_command),
		"__RESTRICT",
		SHARED_REGION_BASE_I386,
		1, 0, 0, 0, 0, 0, 0
	};

	/**
	 *  Temporary buffer for reading image data
	 */
	uint8_t tmpBufferData[PAGE_SIZE*3] {};

	/**
	 *  Kernel auth listener handle
	 */
	kauth_listener_t listener {nullptr};

	/**
	 *  Patcher status
	 */
	bool activated {false};

	/**
	 *  Validation cookie
	 */
	void *cookie {nullptr};

	/**
	 *  Flags for codesign (PL) offset in struct proc. (uint32_t p_csflags)
	 */
	size_t csFlagsOffset {0};

	/**
	 *  Exec callback
	 *
	 *  @param credential kauth credential
	 *  @param idata      cookie
	 *  @param action     passed action, we only need KAUTH_FILEOP_EXEC
	 *  @param arg0       pointer to vnode (vnode *) for executable
	 *  @param arg1       pointer to path (char *) to executable
	 *
	 *  @return 0 to allow further execution
	 */
	static int execListener(kauth_cred_t /* credential */, void *idata, kauth_action_t action, uintptr_t /* arg0 */, uintptr_t arg1, uintptr_t, uintptr_t);

	/**
	 *  Unrestricted vm_protect, that takes care of Mojave codesign limitations for everyone's good.
	 *  See vm_protect description.
	 */
	kern_return_t vmProtect(vm_map_t map, vm_offset_t start, vm_size_t size, boolean_t set_maximum, vm_prot_t new_protection);

	/**
	 *  Callback invoked at process loading
	 *
	 *  @param path binary path
	 *  @param len  path length
	 */
	void onPath(const char *path, uint32_t len);

	/**
	 *  Reads files from BinaryModInfos and prepares lookupStorage
	 *
	 *  @return true on success
	 */
	bool loadFilesForPatching();

	/**
	 *  Reads dyld shared cache and obtains segment offsets
	 *
	 *  @return true on success
	 */
	bool loadDyldSharedCacheMapping();

	/**
	 *  Prepares quick page lookup based on lookupStorage values
	 *
	 *  @return true on success
	 */
	bool loadLookups();

	/**
	 *  Hooks memory access to get ready for patching
	 *
	 *  @return true on success
	 */
	bool hookMemoryAccess();

	/**
	 *  Peforms the actual binary patching
	 *
	 *  @param map  vm map
	 *  @param path binary path
	 *  @param len  path length
	 */
	void patchBinary(vm_map_t map, const char *path, uint32_t len);

	/**
	 *  Dyld shared cache map path for 10.10+ on Haswell
	 */
	static constexpr const char *SharedCacheMapHaswell {"/private/var/db/dyld/dyld_shared_cache_x86_64h.map"};

	/**
	 *  Dyld shared cache map path for all other systems and older CPUs
	 */
	static constexpr const char *SharedCacheMapLegacy {"/private/var/db/dyld/dyld_shared_cache_x86_64.map"};

};

#endif /* kern_user_hpp */
