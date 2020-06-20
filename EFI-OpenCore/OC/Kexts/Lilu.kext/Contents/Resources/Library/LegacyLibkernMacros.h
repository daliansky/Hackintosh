//
//  LegacyLibkernMacros.h
//  Lilu
//
//  Copyright © 2019 vit9696. All rights reserved.
//

#ifndef LegacyLibkernMacros_h
#define LegacyLibkernMacros_h

// This is a compatibility header to let Lilu build with different Xcode
// versions and be able to use legacy headers and clang analyzer.

#include <libkern/c++/OSMetaClass.h>

#if !defined(LIBKERN_RETURNS_NOT_RETAINED)
#define LIBKERN_RETURNS_NOT_RETAINED
#elif defined(__clang_major__) && __clang_major__ < 11
#undef LIBKERN_RETURNS_NOT_RETAINED
#define LIBKERN_RETURNS_NOT_RETAINED
#endif

#if !defined(LIBKERN_RETURNS_RETAINED)
#define LIBKERN_RETURNS_RETAINED
#elif defined(__clang_major__) && __clang_major__ < 11
#undef LIBKERN_RETURNS_RETAINED
#define LIBKERN_RETURNS_RETAINED
#endif

#if !defined(LIBKERN_CONSUMED)
#define LIBKERN_CONSUMED
#elif defined(__clang_major__) && __clang_major__ < 11
#undef LIBKERN_CONSUMED
#define LIBKERN_CONSUMED
#endif

#if !defined(LIBKERN_CONSUMES_THIS)
#define LIBKERN_CONSUMES_THIS
#elif defined(__clang_major__) && __clang_major__ < 11
#undef LIBKERN_CONSUMES_THIS
#define LIBKERN_CONSUMES_THIS
#endif

#if !defined(LIBKERN_RETURNS_RETAINED_ON_ZERO)
#define LIBKERN_RETURNS_RETAINED_ON_ZERO
#elif defined(__clang_major__) && __clang_major__ < 11
#undef LIBKERN_RETURNS_RETAINED_ON_ZERO
#define LIBKERN_RETURNS_RETAINED_ON_ZERO
#endif

#if !defined(LIBKERN_RETURNS_RETAINED_ON_NONZERO)
#define LIBKERN_RETURNS_RETAINED_ON_NONZERO
#elif defined(__clang_major__) && __clang_major__ < 11
#undef LIBKERN_RETURNS_RETAINED_ON_NONZERO
#define LIBKERN_RETURNS_RETAINED_ON_NONZERO
#endif

#endif /* LegacyLibkernMacros_h */
