//
//  kern_vsmcapi.hpp
//  VirtualSMC
//
//  Copyright © 2018 vit9696. All rights reserved.
//

#ifndef kern_vsmcapi_hpp
#define kern_vsmcapi_hpp

#include <Headers/kern_util.hpp>
#include <VirtualSMCSDK/kern_smcinfo.hpp>
#include <VirtualSMCSDK/kern_keyvalue.hpp>
#include <Library/LegacyIOService.h>

namespace VirtualSMCAPI {
	/**
	 *  SMC device service name. Please be aware that the same name is used for any (including physical) SMC device.
	 */
	static constexpr const char *ServiceName = "APP0001";

	/**
	 *  Main communication platform function interface.
	 *  Takes plugin IOService and VirtualSMCPlugin as arguments. No modifications to struct contents are allowed once it is submitted.
	 *  Virtual key functions may be invoked asynchronously from inside IOSimpleLock context, so they should be designed
	 *  with the help of lock-free algorithms.
	 */
	static constexpr const char *SubmitPlugin = "VirtualSMCSubmitPlugin";

	/**
	 *  A total maximum of allowed plugins for installation.
	 */
	static constexpr size_t PluginMax = 16;

	/**
	 *  Accepted plugin API (and ABI) compatibility
	 */
	static constexpr size_t Version = 1;

	/**
	 *  Sorted key storage containing pairs of keys and values.
	 */
	using KeyStorage = evector<VirtualSMCKeyValue&, VirtualSMCKeyValue::deleter>;

	/**
	 *  Main description structure submitted by a plugin. Must be unchanged and never deallocated after submission.
	 */
	struct Plugin {
		const char *product;        // Product name (e.g. xStringify(PRODUCT_NAME))
		size_t version;             // Product version (e.g. parseModuleVersion(xStringify(MODULE_VERSION)))
		size_t apiver;              // Product API compatibility (i.e. VirtualSMCAPIVersion)
		// Please note, that storage vectors MUST be sorted. Otherwise the behaviour is undefined.
		KeyStorage data, dataHidden;
	};

	/**
	 *  Register plugin handler for plugin loading
	 *
	 *  @param handler  function to handle the notification
	 *  @param context  function context
	 *
	 *  @result notifier (must be released) or nullptr
	 */
	EXPORT IONotifier *registerHandler(IOServiceMatchingNotificationHandler handler, void *context);

	/**
	 *  Asynchronous event poster, which may be used for submitting plugin events.
	 *  Note, this may only be used after SubmitPlugin.
	 *
	 *  @param code      event code to post
	 *  @param data      data to include in the interrupt
	 *  @param dataSize  size of the supplied data
	 *
	 *  @return true on success
	 */
	EXPORT bool postInterrupt(SMC_EVENT_CODE code, const void *data=nullptr, uint32_t dataSize=0);

	/**
	 *  Obtain emulated SMC device info to determine used keys and their format.
	 *  Note, this may only be used within SubmitPlugin or afterwards.
	 *
	 *  @param info      device info object to be copied to
	 *
	 *  @return true on success
	 */
	EXPORT bool getDeviceInfo(SMCInfo &info);

	/**
	 *  Adds a key with given value to a key storage.
	 *  Does nothing if given value is nullptr.
	 *
	 *  @param key     an SMC key
	 *  @param data    a key storage to add the key to
	 *  @param val     an SMC value for the given key
	 *
	 *  @return true on success
	 */
	EXPORT bool addKey(SMC_KEY key, KeyStorage &data, VirtualSMCValue *val);

	/**
	 *  Initializes the given value with the appropriate data. Creates new value if nullptr passed as thisValue.
	 *
	 *  @param smcData          a pointer to SMC_DATA to be used for the value.
	 *  @param smcDataSize      a size of given SMC_DATA. Cannot be 0.
	 *  @param smcKeyType       a key type to init value with.
	 *  @param thisValue        a pointer to VirtualSMCValue. Must always be heap-based, don't use address take operator (&). If nullptr passed an instance of VirtualSMCValue will be created for you. Defaults to nullptr.
	 *  @param smcKeyAttrs      a key attributes as SMC_KEY_ATTRIBUTES flags. Defaults to SMC_KEY_ATTRIBUTE_READ.
	 *  @param serializeLevel   a serialize level needed. Defaults to SerializeLevel::None.
	 *
	 *  @return thisValue either passed or created new on success, nullptr if something went wrong.
	 */
	EXPORT VirtualSMCValue *valueWithData(const SMC_DATA *smcData, SMC_DATA_SIZE smcDataSize, SMC_KEY_TYPE smcKeyType, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None);

	/**
	 *  Decode Apple SP signed fixed point fractional format
	 *
	 *  @param type  encoding type, e.g. SmcKeyTypeSp78
	 *  @param value value as it is read from SMC_DATA field
	 *
	 *  @return floating point value
	 */
	EXPORT double decodeSp(uint32_t type, uint16_t value);

	/**
	 *  Encode Apple SP signed fixed point fractional format
	 *
	 *  @param type  encoding type, e.g. SmcKeyTypeSp78
	 *  @param value source value
	 *
	 *  @return value as it is to be written to SMC_DATA field
	 */
	EXPORT uint16_t encodeSp(uint32_t type, double value);

	/**
	 *  Decode Apple FP unsigned fixed point fractional format
	 *
	 *  @param type  encoding type, e.g. SmcKeyTypeFp88
	 *  @param value value as it is read from SMC_DATA field
	 *
	 *  @return floating point value
	 */
	EXPORT double decodeFp(uint32_t type, uint16_t value);

	/**
	 *  Encode Apple FP unsigned fixed point fractional format
	 *
	 *  @param type  encoding type, e.g. SmcKeyTypeFp88
	 *  @param value source value
	 *
	 *  @return value as it is to be written to SMC_DATA field
	 */
	EXPORT uint16_t encodeFp(uint32_t type, double value);

	/**
	 *  Decode Apple float fractional format
	 *
	 *  @param value value as it is read from SMC_DATA field
	 *
	 *  @return floating point value
	 */
	inline float decodeFlt(uint32_t value) {
		union { uint32_t u32; float f; } v {value};
		return v.f;
	}

	/**
	 *  Encode Apple float fractional format
	 *
	 *  @param value source value
	 *
	 *  @return value as it is to be written to SMC_DATA field
	 */
	inline uint32_t encodeFlt(float value) {
		union { float f; uint32_t u32; } v {value};
		return v.u32;
	}

	/**
	 *  A convenient method for initializing flag type key value.
	 *
	 *  @param flagValue  a boolean true or false.
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithFlag(bool flagValue, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		return valueWithData(reinterpret_cast<const SMC_DATA *>(&flagValue), sizeof(bool), SmcKeyTypeFlag, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing Uint8 type key value.
	 *
	 *  @param uint8Value  an integer of 0..255 range.
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithUint8(uint8_t uint8Value, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		return valueWithData(reinterpret_cast<const SMC_DATA *>(&uint8Value), sizeof(uint8_t), SmcKeyTypeUint8, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *	A convenient method for initializing Sint16 type key value.
	 *
	 *  @param int16Value  an integer of -32767..32768 range.
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithSint16(int16_t int16Value, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		int16_t t = OSSwapHostToBigInt16(int16Value);
		return valueWithData(reinterpret_cast<const SMC_DATA *>(&t), sizeof(int16_t), SmcKeyTypeSint16, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing Uint16 type key value.
	 *
	 *  @param uint16Value 	an integer of 0..65535 range.
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithUint16(uint16_t uint16Value, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		uint16_t t = OSSwapHostToBigInt16(uint16Value);
		return valueWithData(reinterpret_cast<const SMC_DATA *>(&t), sizeof(uint16_t), SmcKeyTypeUint16, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing Sint32 type key value.
	 *
	 *  @param int32Value  an integer of –2147483648..2147483647 range.
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithSint32(int32_t int32Value, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		int32_t t = OSSwapHostToBigInt32(int32Value);
		return valueWithData(reinterpret_cast<const SMC_DATA *>(&t), sizeof(int32_t), SmcKeyTypeSint32, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing uint32_t type key value.
	 *
	 *  @param uint32Value 	an integer of 0..4294967295 range.
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithUint32(uint32_t uint32Value, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		uint32_t t = OSSwapHostToBigInt32(uint32Value);
		return valueWithData(reinterpret_cast<const SMC_DATA *>(&t), sizeof(uint32_t), SmcKeyTypeUint32, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing spXX key value
	 *
	 *  @param value  floating point value
	 *  @param type   Apple sp type (see encodeSp)
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithSp(double value, SMC_KEY_TYPE spType, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		auto e = encodeSp(spType, value);
		return valueWithData(reinterpret_cast<SMC_DATA *>(&e), sizeof(e), spType, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing fpXX key value
	 *
	 *  @param value  floating point value
	 *  @param type   Apple fp type (see encodeFp)
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithFp(double value, SMC_KEY_TYPE fpType, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		auto e = encodeFp(fpType, value);
		return valueWithData(reinterpret_cast<SMC_DATA *>(&e), sizeof(e), fpType, thisValue, smcKeyAttrs, serializeLevel);
	}

	/**
	 *  A convenient method for initializing flt key value
	 *
	 *  @param value  floating point value
	 *  @see VirtualSMCAPI::valueWithData
	 */
	inline VirtualSMCValue *valueWithFlt(float value, VirtualSMCValue *thisValue = nullptr, SMC_KEY_ATTRIBUTES smcKeyAttrs = SMC_KEY_ATTRIBUTE_READ, SerializeLevel serializeLevel = SerializeLevel::None) {
		auto e = encodeFlt(value);
		return valueWithData(reinterpret_cast<SMC_DATA *>(&e), sizeof(e), SmcKeyTypeFloat, thisValue, smcKeyAttrs, serializeLevel);
	}
}

#endif /* kern_vsmcapi_hpp */
