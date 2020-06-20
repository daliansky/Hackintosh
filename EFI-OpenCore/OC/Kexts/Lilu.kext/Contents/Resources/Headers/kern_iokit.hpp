//
//  kern_iokit.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_iokit_hpp
#define kern_iokit_hpp

#include <Headers/kern_config.hpp>
#include <Headers/kern_util.hpp>
#include <Headers/kern_patcher.hpp>
#include <Library/LegacyLibkernMacros.h>

#include <libkern/c++/OSSerialize.h>
#include <IOKit/IORegistryEntry.h>

namespace WIOKit {

	/**
	 *  AppleHDAEngine::getLocation teaches us to use loop infinitely when talking to IOReg
	 *  This feels mad and insane, since it may prevent the system from booting.
	 *  Although this had never happened, we will use a far bigger fail-safe stop value.
	 */
	static constexpr size_t bruteMax {0x10000000};

	/**
	 *  Read typed OSData
	 *
	 *  @param obj    read object
	 *  @param value  read value
	 *  @param name   propert name
	 *
	 *  @return true on success
	 */
	template <typename T>
	inline bool getOSDataValue(const OSObject *obj, const char *name, T &value) {
		if (obj) {
			auto data = OSDynamicCast(OSData, obj);
			if (data && data->getLength() == sizeof(T)) {
				value = *static_cast<const T *>(data->getBytesNoCopy());
				DBGLOG("iokit", "getOSData %s has %llX value", name, static_cast<uint64_t>(value));
				return true;
			} else {
				SYSLOG("iokit", "getOSData %s has unexpected format", name);
			}
		} else {
			DBGLOG("iokit", "getOSData %s was not found", name);
		}
		return false;
	}

	/**
	 *  Read typed OSData through a temp type
	 *
	 *  @param obj    read object
	 *  @param value  read value
	 *  @param name   propert name
	 *
	 *  @return true on success
	 */
	template <typename AS, typename T>
	inline bool getOSDataValue(const OSObject *obj, const char *name, T &value) {
		AS tmp;
		if (getOSDataValue(obj, name, tmp)) {
			value = static_cast<T>(tmp);
			return true;
		}

		return false;
	}

	/**
	 *  Read typed OSData from IORegistryEntry
	 *
	 *  @see getOSDataValue
	 */
	template <typename T>
	inline bool getOSDataValue(const IORegistryEntry *sect, const char *name, T &value) {
		return getOSDataValue(sect->getProperty(name), name, value);
	}

	/**
	 *  Read typed OSData from IORegistryEntry
	 *
	 *  @see getOSDataValue
	 */
	template <typename AS, typename T>
	inline bool getOSDataValue(const IORegistryEntry *sect, const char *name, T &value) {
		return getOSDataValue<AS>(sect->getProperty(name), name, value);
	}

	/**
	 *  Read typed OSData from IORegistryEntry
	 *
	 *  @see getOSDataValue
	 */
	template <typename T>
	inline bool getOSDataValue(const OSDictionary *dict, const char *name, T &value) {
		return getOSDataValue(dict->getObject(name), name, value);
	}

	/**
	 *  Read typed OSData from IORegistryEntry
	 *
	 *  @see getOSDataValue
	 */
	template <typename AS, typename T>
	inline bool getOSDataValue(const OSDictionary *dict, const char *name, T &value) {
		return getOSDataValue<AS>(dict->getObject(name), name, value);
	}

	/**
	 *  Retrieve property object
	 *
	 *  @param entry    IORegistry entry
	 *  @param property property name
	 *
	 *  @return property object (must be released) or nullptr
	 */
	EXPORT LIBKERN_RETURNS_RETAINED OSSerialize *getProperty(IORegistryEntry *entry, const char *property);

	/**
	 *  Model variants
	 */
	struct ComputerModel {
		enum {
			ComputerInvalid = 0x0,
			ComputerLaptop  = 0x1,
			ComputerDesktop = 0x2,
			ComputerAny = ComputerLaptop | ComputerDesktop
		};
	};

	/**
	 *  PCI GPU Vendor identifiers
	 */
	struct VendorID {
		enum : uint16_t {
			ATIAMD = 0x1002,
			AMDZEN = 0x1022,
			NVIDIA = 0x10DE,
			Intel  = 0x8086,
			VMware = 0x15AD,
			QEMU   = 0x1B36,
		};
	};

	/**
	 *  PCI class codes
	 */
	struct ClassCode {
		enum : uint32_t {
			VGAController     = 0x030000,
			// I have never seen this one, but laptops are evil.
			XGAController     = 0x030100,
			// Some laptops use this for Optimus GPUs.
			Ex3DController    = 0x030200,
			DisplayController = 0x038000,
			PCIBridge         = 0x060400,
			// HDA device on some laptops like Acer Aspire VN7-592G (INSYDE).
			HDAMmDevice       = 0x040100,
			// Watch out for PCISubclassMask, 0x040380 is common on laptops.
			HDADevice         = 0x040300,
			// This does not seem to be documented. It works on Haswell at least.
			IMEI              = 0x078000,
			// To ignore device subclasses.
			PCISubclassMask   = 0xFFFF00,
		};
	};

	/**
	 *  Definitions of PCI Config Registers
	 */
	enum PCIRegister : uint8_t {
		kIOPCIConfigVendorID                = 0x00,
		kIOPCIConfigDeviceID                = 0x02,
		kIOPCIConfigCommand                 = 0x04,
		kIOPCIConfigStatus                  = 0x06,
		kIOPCIConfigRevisionID              = 0x08,
		kIOPCIConfigClassCode               = 0x09,
		kIOPCIConfigCacheLineSize           = 0x0C,
		kIOPCIConfigLatencyTimer            = 0x0D,
		kIOPCIConfigHeaderType              = 0x0E,
		kIOPCIConfigBIST                    = 0x0F,
		kIOPCIConfigBaseAddress0            = 0x10,
		kIOPCIConfigBaseAddress1            = 0x14,
		kIOPCIConfigBaseAddress2            = 0x18,
		kIOPCIConfigBaseAddress3            = 0x1C,
		kIOPCIConfigBaseAddress4            = 0x20,
		kIOPCIConfigBaseAddress5            = 0x24,
		kIOPCIConfigCardBusCISPtr           = 0x28,
		kIOPCIConfigSubSystemVendorID       = 0x2C,
		kIOPCIConfigSubSystemID             = 0x2E,
		kIOPCIConfigExpansionROMBase        = 0x30,
		kIOPCIConfigCapabilitiesPtr         = 0x34,
		kIOPCIConfigInterruptLine           = 0x3C,
		kIOPCIConfigInterruptPin            = 0x3D,
		kIOPCIConfigMinimumGrant            = 0x3E,
		kIOPCIConfigMaximumLatency          = 0x3F
	};

	/**
	 *  Fixed offsets for PCI Config I/O virtual methods
	 */
	struct PCIConfigOffset {
		enum : size_t {
			ConfigRead32      = 0x10A,
			ConfigWrite32     = 0x10B,
			ConfigRead16      = 0x10C,
			ConfigWrite16     = 0x10D,
			ConfigRead8       = 0x10E,
			ConfigWrite8      = 0x10F,
			GetBusNumber      = 0x11D,
			GetDeviceNumber   = 0x11E,
			GetFunctionNumber = 0x11F
		};
	};

	/**
	 *  PCI Config I/O method prototypes
	 */
	using t_PCIConfigRead32 = uint32_t (*)(IORegistryEntry *service, uint32_t space, uint8_t offset);
	using t_PCIConfigRead16 = uint16_t (*)(IORegistryEntry *service, uint32_t space, uint8_t offset);
	using t_PCIConfigRead8  = uint8_t  (*)(IORegistryEntry *service, uint32_t space, uint8_t offset);
	using t_PCIConfigWrite32 = void (*)(IORegistryEntry *service, uint32_t space, uint8_t offset, uint32_t data);
	using t_PCIConfigWrite16 = void (*)(IORegistryEntry *service, uint32_t space, uint8_t offset, uint16_t data);
	using t_PCIConfigWrite8  = void (*)(IORegistryEntry *service, uint32_t space, uint8_t offset, uint8_t data);
	using t_PCIGetBusNumber = uint8_t (*)(IORegistryEntry *service);
	using t_PCIGetDeviceNumber = uint8_t (*)(IORegistryEntry *service);
	using t_PCIGetFunctionNumber = uint8_t (*)(IORegistryEntry *service);

	/**
	 *  Read PCI Config register
	 *
	 *  @param service  IOPCIDevice-compatible service.
	 *  @param reg      PCI config register
	 *  @param space    adress space
	 *  @param size     read size for reading custom registers
	 *
	 *  @return value read
	 */
	EXPORT uint32_t readPCIConfigValue(IORegistryEntry *service, uint32_t reg, uint32_t space = 0, uint32_t size = 0);

	/**
	 *  Retrieve PCI device address
	 *
	 *  @param service   IOPCIDevice-compatible service.
	 *  @param bus       bus address
	 *  @param device    device address
	 *  @param function  function address
	 */
	EXPORT void getDeviceAddress(IORegistryEntry *service, uint8_t &bus, uint8_t &device, uint8_t &function);

	/**
	 *  Retrieve the computer type
	 *
	 *  @return valid computer type or ComputerAny
	 */
	EXPORT int getComputerModel() DEPRECATE("Use BaseDeviceInfo");

	/**
	 *  Retrieve computer model and/or board-id properties
	 *
	 *  @param model    model name output buffer or null
	 *  @param modelsz  model name output buffer size
	 *  @param board    board identifier output buffer or null
	 *  @param boardsz  board identifier output buffer size
	 *
	 *  @return true if relevant properties already are available, otherwise buffers are unchanged
	 */
	EXPORT bool getComputerInfo(char *model, size_t modelsz, char *board, size_t boardsz) DEPRECATE("Use BaseDeviceInfo");

	/**
	 *  Retrieve an ioreg entry by path/prefix
	 *
	 *  @param path    an exact lookup path
	 *  @param prefix  entry prefix at path
	 *  @param plane   plane to lookup in
	 *  @param proc    process every found entry with the method
	 *  @param brute   kick ioreg until a value is found
	 *  @param user    pass some value to the callback function
	 *
	 *  @return entry pointer (must NOT be released) or nullptr (on failure or in proc mode)
	 */
	EXPORT LIBKERN_RETURNS_NOT_RETAINED IORegistryEntry *findEntryByPrefix(const char *path, const char *prefix, const IORegistryPlane *plane, bool (*proc)(void *, IORegistryEntry *)=nullptr, bool brute=false, void *user=nullptr);

	/**
	 *  Retrieve an ioreg entry by path/prefix
	 *
	 *  @param entry   an ioreg entry to look in
	 *  @param prefix  entry prefix at path
	 *  @param plane   plane to lookup in
	 *  @param proc    process every found entry with the method
	 *  @param brute   kick ioreg until a value is found
	 *  @param user    pass some value to the callback function
	 *
	 *  @return entry pointer (must NOT be released) or nullptr (on failure or in proc mode)
	 */
	EXPORT LIBKERN_RETURNS_NOT_RETAINED IORegistryEntry *findEntryByPrefix(IORegistryEntry *entry, const char *prefix, const IORegistryPlane *plane, bool (*proc)(void *, IORegistryEntry *)=nullptr, bool brute=false, void *user=nullptr);

	/**
	 *  Check if we are using prelinked kernel/kexts or not
	 *
	 *  @return true when confirmed that we definitely are
	 */
	EXPORT bool usingPrelinkedCache();

	/**
	 *  Properly rename the device
	 *
	 *  @param  entry   device to rename
	 *  @param  name    new name
	 *  @param  compat  correct compatible
	 *
	 *  @return true on success
	 */
	EXPORT bool renameDevice(IORegistryEntry *entry, const char *name, bool compat=true);
}

#endif /* kern_iokit_hpp */
