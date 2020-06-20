//
//  kern_nvram.hpp
//  Lilu
//
//  Copyright © 2017 vit9696. All rights reserved.
//

#ifndef kern_nvram_hpp
#define kern_nvram_hpp

#include <Headers/kern_util.hpp>
#include <Library/LegacyIOService.h>
#include <libkern/c++/OSSymbol.h>
#include <libkern/libkern.h>
#include <stdint.h>

/**
 *  Some of the most common GUIDs used for variable storage on macOS
 */
#define NVRAM_GLOBAL_GUID "8BE4DF61-93CA-11D2-AA0D-00E098032B8C"
#define NVRAM_APPLE_BOOT_GUID "7C436110-AB2A-4BBB-A880-FE41995C9F82"
#define NVRAM_APPLE_VENDOR_GUID "4D1EDE05-38C7-4A6A-9CC6-4BCCA8B38C14"
#define NVRAM_APPLE_FILEVAULT_GUID "8D63D4FE-BD3C-4AAD-881D-86FD974BC1DF"
#define NVRAM_APPLE_PASSWORD_UI_GUID "9EBA2D25-BBE3-4AC2-A2C6-C87F44A1278C"

/**
 *  Custom GUIDs used for Lilu preferences
 *  Must be kept in sync to OcSupportPkg/Include/Guid/OcVariables.h
 */
#define LILU_VENDOR_GUID "4D1FDA02-38C7-4A6A-9CC6-4BCCA8B30102"
#define LILU_READ_ONLY_GUID "E09B9297-7928-4440-9AAB-D1F8536FBF0A"
#define LILU_WRITE_ONLY_GUID "F0B9AF8F-2222-4840-8A37-ECF7CC8C12E1"

/**
 *  Prefix variable name with a GUID
 */
#define NVRAM_PREFIX(x, y) x ":" y

class NVStorage {
	/**
	 *  Local nvram controller reference
	 */
	IORegistryEntry *dtEntry {nullptr};

public:
	/**
	 *  Compress data with a default compression algorithm
	 *
	 *  @param src        source data
	 *  @param size       data size (updated with new size)
	 *  @param sensitive  contains sensitive data
	 *
	 *  @return compressed data (must be freed with Buffer::deleter) or nullptr
	 */
	EXPORT uint8_t *compress(const uint8_t *src, uint32_t &size, bool sensitive=false);

	/**
	 *  Decompress data compressed with compress
	 *
	 *  @param src        compressed data
	 *  @param size       data size (updated with new size)
	 *  @param sensitive  contains sensitive data
	 *
	 *  @return decompressed data (must be freed with Buffer::deleter) or nullptr
	 */
	EXPORT uint8_t *decompress(const uint8_t *src, uint32_t &size, bool sensitive=false);

	/**
	 *  Value storage options
	 */
	enum Options {
		OptAuto         = 0,  // Default options
		OptRaw          = 1,  // i/o as raw buffer
		OptCompressed   = 2,  // Apply compression (see kern_compression.hpp)
		OptEncrypted    = 4,  // Apply encryption with device-unique key (see kern_crypto.hpp)
		OptChecksum     = 8,  // Append CRC32 checksum to the end
		OptSensitive    = 16  // Value contains sensitive data
	};

	/**
	 *  Prepended value header unless OptRaw is used
	 *  After the header the following fields should go:
	 *  uint8_t iv[16]; aes initialisation vector (if OptEncrypted is set)
	 *  uint32_t size;  decryption size           (if OptEncrypted is set, encrypted)
	 *  uint32_t size;  decompression size        (if OptCompressed is set, encrypted if OptEncrypted)
	 *  uint8_t data[]; content data              (encrypted if OptEncrypted)
	 *  uint32_t crc32; CRC32 cheksum             (if OptChecksum is set)
	 */
	struct PACKED Header {
		static constexpr uint16_t Magic = 0xC717;
		static constexpr uint8_t MaxVer = 1;
		using Checksum = uint32_t;

		uint16_t magic {Magic};
		uint8_t version {MaxVer};
		uint8_t opts {OptAuto};
	};

	/**
	 *  Attempt to connect to active nvram, may fail at early stages
	 *
	 *  @return true on success
	 */
	EXPORT bool init();

	/**
	 *  Relinquish resources used, must be called regardless of the init error
	 */
	EXPORT void deinit();

	/**
	 *  Read data from nvram
	 *
	 *  @param key    key name
	 *  @param size   amount of data read
	 *  @param opts   bitmask of Options, may set option requirements
	 *  @param enckey encryption key (platform-defined if OptEncrypted is set)
	 *
	 *  @return pointer to data (must be freed via Buffer::deleter), nullptr on failure
	 */
	EXPORT uint8_t *read(const char *key, uint32_t &size, uint8_t opts=OptAuto, const uint8_t *enckey=nullptr);

	/**
	 *  Read data from nvram
	 *
	 *  @param key    key name
	 *  @param opts   bitmask of Options, may set option requirements
	 *  @param enckey encryption key (platform-defined if OptEncrypted is set)
	 *
	 *  @return pointer to data (must be freed via OSData::release), nullptr on failure
	 */
	EXPORT OSData *read(const char *key, uint8_t opts=OptAuto, const uint8_t *enckey=nullptr);

	/**
	 *  Write data to nvram
	 *
	 *  @param key    key name
	 *  @param src    source buffer
	 *  @param size   buffer size
	 *  @param opts   bitmask of Options
	 *  @param enckey encryption key (platform-defined if OptEncrypted is set)
	 *
	 *  @return true on success
	 */
	EXPORT bool write(const char *key, const uint8_t *src, uint32_t sz, uint8_t opts=OptAuto, const uint8_t *enckey=nullptr);

	/**
	 *  Write data to nvram
	 *
	 *  @param key    key name
	 *  @param data   data object to write
	 *  @param opts   bitmask of Options
	 *  @param enckey encryption key (platform-defined if OptEncrypted is set)
	 *
	 *  @return true on success
	 */
	EXPORT bool write(const char *key, const OSData *data, uint8_t opts=OptAuto, const uint8_t *enckey=nullptr);

	/**
	 *  Delete key from nvram
	 *
	 *  @param key        key name
	 *  @param sensitive  sensitive data
	 *
	 *  @return true on successful deletion or if key is missing
	 */
	EXPORT bool remove(const char *key, bool sensitive=false);

	/**
	 *  Synchronize with nvram controller
	 *  This method might fail if synchronisation was done recently.
	 *
	 *  @return true if synchronised
	 */
	EXPORT bool sync();

	/**
	 *  Exports nvram to a plist file
	 *
	 *  @param filename  file path
	 *  @oaram max       max output size
	 *  @param sensitive contains sensitive data
	 *
	 *  @return true if saved
	 */
	EXPORT bool save(const char *filename, uint32_t max=0x20000, bool sensitive=false);

	/**
	 *  Check whether key exists
	 *
	 *  @param key        key name
	 *
	 *  @return true if key exists
	 */
	EXPORT bool exists(const char *key);
};

#endif /* kern_nvram_hpp */
