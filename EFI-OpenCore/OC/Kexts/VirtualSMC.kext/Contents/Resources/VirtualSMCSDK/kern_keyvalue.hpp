//
//  kern_keyvalue.hpp
//  VirtualSMC
//
//  Copyright © 2017 vit9696. All rights reserved.
//

#ifndef kern_keyvalue_hpp
#define kern_keyvalue_hpp

#include <Headers/kern_atomic.hpp>
#include <VirtualSMCSDK/AppleSmcBridge.hpp>
#include <VirtualSMCSDK/kern_value.hpp>

struct VirtualSMCKeyValue {
	/**
	 *  Key name
	 */
	SMC_KEY key;

	/**
	 *  Key value
	 */
	_Atomic(VirtualSMCValue *) value = ATOMIC_VAR_INIT(nullptr);

	/**
	 *  Original value
	 */
	_Atomic(VirtualSMCValue *) backup = nullptr;

	/**
	 *  Should key value pair be serialisable
	 *
	 *  @param confidential  confidential serialisation stores are allowed
	 *
	 *  @return true if should be saved
	 */
	bool serializable(bool confidential) const;

	/**
	 *  Get serialized size (normally key, size, key data)
	 *
	 *  @return size in bytes
	 */
	size_t serializedSize() const;

	/**
	 *  Write serialized data to the buffer
	 *
	 *  @param dst  serialization buffer reference of at least serializedSize()
	 */
	void serialize(uint8_t *&dst) const;

	/**
	 *  Read serialized data
	 *
	 *  @param src   serialization buffer reference (increased)
	 *  @param size  serialization buffer size (decreased)
	 *  @param name  read key name
	 *  @param out   read key data (must be preallocated)
	 *  @param outsz key data size
	 *
	 *  @return true on succesful read
	 */
	static bool deserialize(const uint8_t *&src, uint32_t &size, SMC_KEY &name, SMC_DATA *out, SMC_DATA_SIZE &outsz);

	/**
	 *  Create key/value pair for storage
	 *
	 *  @param k  key name
	 *  @param v  key value
	 *
	 *  @return key/value pair
	 */
	static VirtualSMCKeyValue create(SMC_KEY k, VirtualSMCValue *v) {
		VirtualSMCKeyValue kv {k};
		atomic_init(&kv.value, v);
		atomic_init(&kv.backup, nullptr);
		return kv;
	}

	/**
	 *  Key/value deleter responsible for freeing value dynamic memory
	 *
	 *  @param kv key/value pair
	 */
	static void deleter(VirtualSMCKeyValue &kv) {
		// This is just an old compiler crash workaround, no need for atomicity here!
		auto v = atomic_load_explicit(&kv.value, memory_order_relaxed);
		auto b = atomic_load_explicit(&kv.backup, memory_order_relaxed);
		if (v) VirtualSMCValue::deleter(v);
		if (b) VirtualSMCValue::deleter(b);
	}

	/**
	 *  Key comparator for sorting
	 *
	 *  @param a  first key
	 *  @param b  second key
	 *
	 *  @return like qsort (<0 if a goes before b)
	 */
	static int compare(const SMC_KEY a, const SMC_KEY b) {
		if (a == b)
			return 0;
		else if (OSSwapInt32(a) < OSSwapInt32(b))
			return -1;
		return 1;
	}

	/**
	 *  Key value comparator for sorting
	 *
	 *  @param a  opaque k/v pointer
	 *  @param b  opaque k/v pointer
	 *
	 *  @return like qsort (<0 if a goes before b)
	 */
	static int compare(const void *a, const void *b) {
		return compare(static_cast<const VirtualSMCKeyValue *>(a)->key, static_cast<const VirtualSMCKeyValue *>(b)->key);
	}
};


#endif /* kern_keyvalue_hpp */
