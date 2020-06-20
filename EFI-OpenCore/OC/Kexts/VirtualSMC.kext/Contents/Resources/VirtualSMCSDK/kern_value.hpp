//
//  kern_keyvalue.hpp
//  VirtualSMC
//
//  Copyright © 2018 vit9696. All rights reserved.
//

#ifndef kern_value_hpp
#define kern_value_hpp

#include <Headers/kern_util.hpp>
#include <libkern/c++/OSData.h>

#include <VirtualSMCSDK/AppleSmcBridge.hpp>

/**
 *  Serialization level determining external value storage necessity
 */
enum class EXPORT SerializeLevel {
	None,
	Normal,
	Confidential,
	Default = Confidential
};

class VirtualSMCKeystore;
class VirtualSMCKeyValue;

class EXPORT VirtualSMCValue {
	friend VirtualSMCKeystore;
	friend VirtualSMCKeyValue;
protected:

	/**
	 *  Value contents retrieved by other protocols
	 */
	SMC_DATA data[SMC_MAX_DATA_SIZE] {};

	/**
	 *  Actual value contents size (could be less than SMC_MAX_DATA_SIZE)
	 */
	SMC_DATA_SIZE size {};

	/**
	 *  One of the enum types defined in AppleSmc.h specifying value type
	 */
	SMC_KEY_TYPE type {};

	/**
	 *  Bitmask of key attributes defined in AppleSmc.h defining value abilities
	 */
	SMC_KEY_ATTRIBUTES attr {};

	/**
	 *  Serialization level defining the necessity to serialize values on power events
	 */
	SerializeLevel serializeLevel {SerializeLevel::None};

	/**
	 *  On read access, update the data if needed, and perform custom access control.
	 *  For base value, always allow the access if keystore allowed it.
	 *
	 *  @return SmcSuccess if allowed
	 */
	virtual SMC_RESULT readAccess() {
		return SmcSuccess;
	}

	/**
	 *  On write access, update the data if needed, and perform custom access control.
	 *  For base value, always allow the access if keystore allowed it.
	 *
	 *  @return SmcSuccess if allowed
	 */
	virtual SMC_RESULT writeAccess() {
		return SmcSuccess;
	}

public:
	/**
	 *  Initialises a value with existing data.
	 *
	 *  @param  data      Initial data, must be at least size bytes
	 *  @param  size      Amount of data bytes used, at most SMC_MAX_DATA_SIZE
	 *  @param  type      Value type
	 *  @param  attr      Value attributes
	 *  @param  level     Serialization necessity
	 *
	 *  @return true on success
	 */
	EXPORT bool init(const SMC_DATA *data, SMC_DATA_SIZE size, SMC_KEY_TYPE type, SMC_KEY_ATTRIBUTES attr, SerializeLevel level = SerializeLevel::None);

	/**
	 *  Initialises a value with  an OSDictionary.
	 *  Dictionary keys are described in VirtualKeystore::merge(const OSArray *) method.
	 *
	 *  @param dict  An OSDictionary that describes the value
	 *
	 *  @return true on success
	 */
	EXPORT bool init(const OSDictionary *dict);

	/**
	 *  Obtain value contents
	 *
	 *  @param size  Amount of used bytes
	 *
	 *  @return Pointer to the value data buffer.
	 *
	 *  The buffer shall never be modified externally.
	 */
	const SMC_DATA *get(SMC_DATA_SIZE &size) const;

	/**
	 *  Update the internal buffer, assuming the same
	 *  amount of bytes is used for this value.
	 *
	 *  @param src  new contents
	 */
	virtual SMC_RESULT update(const SMC_DATA *src);

	/**
	 *  Checks serialization necessity
	 *
	 *  @param confidential  confidential information storage is allowed
	 *
	 *  @retrurn true if the value needs to be serialized
	 */
	bool serializable(bool confidential) const {
		return serializeLevel == SerializeLevel::Normal ||
		       (serializeLevel == SerializeLevel::Confidential && confidential);
	}

	/**
	 *  It is not recommended to free created values but you can if you need
	 */
	virtual ~VirtualSMCValue() = default;

	/**
	 *  Used for storing values in evector
	 *
	 *  @param inst  value to be freed
	 */
	static void deleter(VirtualSMCValue *inst) {
		delete inst;
	}
};

#endif /* kern_value_hpp */
