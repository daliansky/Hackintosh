//
//  kern_config.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_config_hpp
#define kern_config_hpp

/**
 *  Enable kext patching support
 */
#define LILU_KEXTPATCH_SUPPORT 1

/**
 *  Enable compression and decompression support
 */
#define LILU_COMPRESSION_SUPPORT 1

/**
 *  Enable advanced disassembly API based on capstone
 */
// #define LILU_ADVANCED_DISASSEMBLY 1

/**
 *  Specify custom initialisation code
 *  Use these in plugins in Xcode Project Preprocessor Macros section.
 */
// #define LILU_CUSTOM_IOKIT_INIT 1
// #define LILU_CUSTOM_KMOD_INIT 1

#endif /* kern_config_hpp */
