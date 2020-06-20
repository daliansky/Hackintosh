//
//  kern_crypto.hpp
//  Lilu
//
//  Copyright © 2017 vit9696. All rights reserved.
//

#ifndef kern_crypto_h
#define kern_crypto_h

#include <Headers/kern_config.hpp>
#include <Headers/kern_util.hpp>
#include <stdint.h>

namespace Crypto {
	/**
	 *  Currently this is equal to both key size and block size
	 */
	static constexpr uint32_t BlockSize = 16;

	/**
	 *  Currently this is guaranteed hash size
	 */
	static constexpr uint32_t MinDigestSize = 32;

	/**
	 *  Encrypted data format
	 */
	struct PACKED Encrypted {
		uint8_t iv[BlockSize];                         // Initialisation vector
		struct PACKED Data {
			uint32_t size;				               // Actual encrypted buffer size
			uint8_t buf[BlockSize - sizeof(uint32_t)]; // Encrypted buffer >= BlockSize
		};

		union {
			Data enc;
			uint8_t buf[BlockSize];
		};
	};

	/**
	 *  Securely erase memory buffer
	 *  Based off cc_clear from corecrypto (src/cc_clear.c)
	 *
	 *  @param len buffer length
	 *  @param dst buffer pointer
	 */
	inline void zeroMemory(size_t len, void *dst) {
		auto vptr = reinterpret_cast<volatile char *>(dst);
		while (len--)
			*vptr++ = '\0';
	}

	/**
	 *  Generates cryptographically secure encryption key (from /dev/random)
	 *
	 *  @return generated key of at least BlockSize bits long (must be freeded by Buffer::deleter) or nullptr
	 */
	EXPORT uint8_t *genUniqueKey(uint32_t size=BlockSize);

	/**
	 *  Encrypts data of specified size and stores in Encrypted format
	 *
	 *  @param key  encryption key returned by genUniqueKey
	 *  @param src  source data
	 *  @param size data size, encrypted size is returned on success
	 *
	 *  @return encrypted data in Encrypted format (must be freed by Buffer::deleter) or nullptr
	 */
	EXPORT uint8_t *encrypt(const uint8_t *key, const uint8_t *src, uint32_t &size);

	/**
	 *  Decrypts data of specified size stored in Encrypted format
	 *
	 *  @param key  encryption key returned by genUniqueKey
	 *  @param src  source data
	 *  @param size data size, decrypted size is returned on success
	 *
	 *  @return decrypted data (must be freed by Buffer::deleter) or nullptr
	 */
	EXPORT uint8_t *decrypt(const uint8_t *key, const uint8_t *src, uint32_t &size);

	/**
	 *  Calculate digest of given size
	 *
	 *  @param src  source data
	 *  @param size data size
	 *
	 *  @return digest hash of at least MinDigestSize bytes (must be freeded by Buffer::deleter) or nullptr
	 */
	EXPORT uint8_t *hash(const uint8_t *src, uint32_t size);
}

#endif /* kern_crypto_h */
