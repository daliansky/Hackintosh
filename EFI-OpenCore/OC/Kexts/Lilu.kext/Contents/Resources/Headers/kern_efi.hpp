//
//  kern_efi.hpp
//  Lilu
//
//  Copyright © 2018 vit9696. All rights reserved.
//

#ifndef kern_efi_h
#define kern_efi_h

#include <Headers/kern_util.hpp>

#include <pexpert/i386/efi.h>

/**
 *  Convert 32-bit EFI errors provided by Apple to 64-bit EFI errors
 */
#define EFI_ERROR64(x) (((x) & ~(1ULL << 31)) | (1ULL << 63))
static_assert(EFI_LOAD_ERROR == 0x80000001 && EFI_ERROR64(EFI_LOAD_ERROR) == 0x8000000000000001,
	"Apple has finally upgraded EFI headers!");

class EfiRuntimeServices {
	IOLock *accessLock {nullptr};
	static EfiRuntimeServices *instance;
public:
	/**
	 *  Activates EFI Runtime Services
	 */
	static void activate();

	/**
	 *  Lilu custom GUIDs exports, see OcSupportPkg/Include/Guid/OcVariables.h
	 */
	EXPORT static const EFI_GUID LiluVendorGuid;
	EXPORT static const EFI_GUID LiluReadOnlyGuid;
	EXPORT static const EFI_GUID LiluWriteOnlyGuid;

	/**
	 *  Get EFI Runtime Services wrapper if supported
	 *
	 *  @param lock  lock instance during the run, must be put back
	 *
	 *  @return wrapper instance
	 */
	EXPORT static EfiRuntimeServices *get(bool lock=false);

	/**
	 *  Put EFI Runtime Services wrapper to unlock
	 */
	EXPORT void put();

	/**
	 *  Perform system reset (does not return on success)
	 *
	 *  @param type reset type
	 */
	EXPORT void resetSystem(EFI_RESET_TYPE type);

	/**
	 *  Obtain EFI variable, invokes EFI_RUNTIME_SERVICES::GetVariable.
	 *
	 *  @param name  variable name
	 *  @param guid  vendor guid
	 *  @param attr  variable attributes
	 *  @param size  data buffer size updated on read
	 *  @param data  read data
	 *
	 *  @return EFI_STATUS code
	 */
	EXPORT uint64_t getVariable(const char16_t *name, const EFI_GUID *guid, uint32_t *attr, uint64_t *size, void *data);

	/**
	 *  Set EFI variable, invokes EFI_RUNTIME_SERVICES::SetVariable.
	 *
	 *  @param name  variable name
	 *  @param guid  vendor guid
	 *  @param attr  variable attributes
	 *  @param size  data buffer size
	 *  @param data  data to write
	 *
	 *  @return EFI_STATUS code
	 */
	EXPORT uint64_t setVariable(const char16_t *name, const EFI_GUID *guid, uint32_t attr, uint64_t size, void *data);
};

#endif /* kern_efi_h */
