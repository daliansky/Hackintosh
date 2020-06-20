//
//  kern_atomic.hpp
//  Lilu
//
//  Copyright © 2018 vit9696. All rights reserved.
//

#ifndef kern_atomic_h
#define kern_atomic_h

#if defined(__has_include)
#if __has_include(<stdatomic.h>)
#include <stdatomic.h>
#else

// Provide basic atomic support for legacy compilers

typedef enum memory_order {
	memory_order_relaxed = __ATOMIC_RELAXED,
	memory_order_consume = __ATOMIC_CONSUME,
	memory_order_acquire = __ATOMIC_ACQUIRE,
	memory_order_release = __ATOMIC_RELEASE,
	memory_order_acq_rel = __ATOMIC_ACQ_REL,
	memory_order_seq_cst = __ATOMIC_SEQ_CST
} memory_order;

#define ATOMIC_VAR_INIT(value) (value)
#define atomic_init __c11_atomic_init

#define atomic_store_explicit __c11_atomic_store
#define atomic_load_explicit __c11_atomic_load
#define atomic_compare_exchange_strong_explicit __c11_atomic_compare_exchange_strong

#endif
#else
// Assume <stdatomic.h> to be available when there is no __has_include.
#include <stdatomic.h>
#endif

#endif /* kern_atomic_h */
