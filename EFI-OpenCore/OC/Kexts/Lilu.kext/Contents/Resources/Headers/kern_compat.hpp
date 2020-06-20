//
//  kern_compat.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_compat_hpp
#define kern_compat_hpp

#include <Headers/kern_config.hpp>
//Actually do not include to catch real errors
//#include <Availability.h>
#include <string.h>

// Please do not use memcpy and similar functions, since they compile
// to macros unsupported by any other system with 10.13 SDK unless
// Availability.h header is included.
#define lilu_os_memcpy(...)  (memcpy)(__VA_ARGS__)
#define lilu_os_memmove(...) (memmove)(__VA_ARGS__)
#define lilu_os_strncpy(...) (strncpy)(__VA_ARGS__)
#define lilu_os_strncat(...) (strncat)(__VA_ARGS__)
#define lilu_os_strlcat(...) (strlcat)(__VA_ARGS__)
#define lilu_os_strlcpy(...) (strlcpy)(__VA_ARGS__)
#define lilu_os_strcat(...)  (strcat)(__VA_ARGS__)
#define lilu_os_bcopy(...)   (bcopy)(__VA_ARGS__)

// Additionally disallow the use of the original functions
#ifndef LILU_DISABLE_MEMFUNC_REDEFINE

#ifdef memcpy
#undef memcpy
#define memcpy(...) _Pragma("GCC error \"Avoid memcpy due to 10.13 SDK bugs!\"")
#endif

#ifdef memmove
#undef memmove
#define memmove(...) _Pragma("GCC error \"Avoid memmove due to 10.13 SDK bugs!\"")
#endif

#ifdef strncpy
#undef strncpy
#define strncpy(...) _Pragma("GCC error \"Avoid strncpy due to 10.13 SDK bugs!\"")
#endif

#ifdef strncat
#undef strncat
#define strncat(...) _Pragma("GCC error \"Avoid strncat due to 10.13 SDK bugs!\"")
#endif

#ifdef strlcat
#undef strlcat
#define strlcat(...) _Pragma("GCC error \"Avoid strlcat due to 10.13 SDK bugs!\"")
#endif

#ifdef strlcpy
#undef strlcpy
#define strlcpy(...) _Pragma("GCC error \"Avoid strlcpy due to 10.13 SDK bugs!\"")
#endif

#ifdef strcat
#undef strcat
#define strcat(...) _Pragma("GCC error \"Avoid strcat due to 10.13 SDK bugs!\"")
#endif

#ifdef bcopy
#undef bcopy
#define bcopy(...) _Pragma("GCC error \"Avoid bcopy due to 10.13 SDK bugs!\"")
#endif

#endif /* LILU_DISABLE_MEMFUNC_REDEFINE */

// This may not be nice but will protect users from changes in KernInfo strcture.
#ifndef LILU_DISABLE_BRACE_WARNINGS
#pragma clang diagnostic error "-Wmissing-braces"
#endif

#endif /* kern_compat_hpp */
