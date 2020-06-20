//
//  kern_compression.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_compression_hpp
#define kern_compression_hpp

#include <Headers/kern_config.hpp>

#ifdef LILU_COMPRESSION_SUPPORT

#include <Headers/kern_util.hpp>
#include <stdint.h>

namespace Compression {

	/**
	 *  Compression constants and modes
	 */
	static constexpr uint32_t Magic {0x706D6F63}; //comp
	static constexpr uint32_t ModeLZVN {0x6E767A6C}; //lzvn
	static constexpr uint32_t ModeLZSS {0x73737A6C}; //lzss

	/**
	 *  Compressed header structure
	 */
	struct Header {
		uint32_t magic;
		uint32_t compression;
		uint32_t hash; // adler32
		uint32_t decompressed;
		uint32_t compressed;
		uint32_t version;
		uint32_t padding[90];
	};

	/**
	 *  Typed decompressing function (currently for lzvn and lzss)
	 *
	 *  @param compression compression type
	 *  @param dstlen      decompression buffer size
	 *  @param src         compressed data
	 *  @param srclen      compressed data size
	 *  @param buffer      preallocated buffer to use
	 *
	 *  @return decompressed buffer (must be freeded by Buffer::deleter if not preallocated)
	 */
	EXPORT uint8_t *decompress(uint32_t compression, uint32_t dstlen, const uint8_t *src, uint32_t srclen, uint8_t *buffer=nullptr);

	/**
	 *  Typed compressing function (currently for lzss)
	 *
	 *  @param compression compression type
	 *  @param dstlen      maximum compression buffer size
	 *  @param src         uncompressed data
	 *  @param srclen      uncompressed data size
	 *  @param buffer      preallocated buffer to use
	 *
	 *  @return compressed buffer with its actual size in dstlen (must be freeded by Buffer::deleter if not preallocated)
	 */
	EXPORT uint8_t *compress(uint32_t compression, uint32_t &dstlen, const uint8_t *src, uint32_t srclen, uint8_t *buffer=nullptr);

}

#endif /* LILU_COMPRESSION_SUPPORT */

#endif /* kern_compression_hpp */
