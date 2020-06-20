//
//  kern_smcinfo.hpp
//  VirtualSMC
//
//  Copyright © 2017 vit9696. All rights reserved.
//

#ifndef kern_smcinfo_h
#define kern_smcinfo_h

#include <Headers/kern_util.hpp>

#include <VirtualSMCSDK/AppleSmcBridge.hpp>

class SMCInfo {
	/**
	 *  Device-specific reproducible random state
	 */
	uint64_t generatorState {};

public:

	/**
	 *  Size in bytes for SmcKeyTypeRev keys
	 */
	static constexpr SMC_DATA_SIZE RevisionSize = 6;

	/**
	 *  Size in bytes for branch keys (usually ch8*)
	 */
	static constexpr SMC_DATA_SIZE BranchSize = 8;

	/**
	 *  Size in bytes for hardware model name
	 */
	static constexpr SMC_DATA_SIZE ModelSize = 64;

	/**
	 *  Size in bytes for MAC value
	 */
	static constexpr SMC_DATA_SIZE MacSize = 6;

	/**
	 *  Size in bytes for Serial value
	 */
	static constexpr SMC_DATA_SIZE SerialSize = 16;

	/**
	 *  Size in bytes for Motherboard Serial value
	 */
	static constexpr SMC_DATA_SIZE MotherboardSerialSize = 17;

	/**
	 *  Device generation:
	 *  - V1 is Big Endian Hitachi
	 *  - V2 is Little Endian ARM
	 *  - Unspecified is used for autodetection code
	 */
	enum class Generation {
		Unspecified = 0,
		V1 = 1,
		V2 = 2,
		V3 = 3
	};

	/**
	 *  Device memory layout information
	 */
	struct Memory {
		mach_vm_address_t start;
		mach_vm_size_t size;
		vm_prot_t prot;
	};

	/**
	 *  Buffers describing device version information
	 */
	enum class Buffer {
		RevMain,
		RevFlasherBase,
		RevFlasherUpdate,
		Branch,
		Platform,
		HardwareModel,
		MacAddress,
		Serial,
		MotherboardSerial
	};

	/**
	 *  Corresponds to REV key contents
	 */
	SMC_DATA main[RevisionSize] {};

	/**
	 *  Corresponds to RVBF key contents
	 */
	SMC_DATA flasherBase[RevisionSize] {};

	/**
	 *  Corresponds to RVUF key contents
	 */
	SMC_DATA flasherUpdate[RevisionSize] {};

	/**
	 *  Corresponds to RBr key contents
	 */
	SMC_DATA branch[BranchSize] {};

	/**
	 *  Corresponds to RPlt key contents
	 */
	SMC_DATA platform[BranchSize] {};

	/**
	 *  Corresponds to SMC hardware model (aka compatible key)
	 */
	SMC_DATA hardwareModel[ModelSize] {};

	/**
	 *  Corresponds to RMAC key contents
	 */
	SMC_DATA macAddress[MacSize] {};

	/**
	 *  Corresponds to RSSN key contents
	 */
	SMC_DATA serial[SerialSize] {};

	/**
	 *  Corresponds to RSSN key contents
	 */
	SMC_DATA motherboardSerial[MotherboardSerialSize] {};

	/**
	 *  Get device generation based on obtained buffers
	 *
	 *  @return device generation
	 */
	Generation getGeneration() const {
		if (main[0] == 1)
			return Generation::V1;
		else if (main[0] == 2)
			return Generation::V2;
		else if (main[0] == 3 || main[0] == 0)
			return Generation::V3;
		DBGLOG("smcinfo", "invalid generation %X, defaulting to V2", main[0]);
		return Generation::V2;
	}
	
	/**
	 *  Initialise reproducible pseudo-random number generator with device info
	 */
	void generatorSeed() {
		union {
			uint8_t arr[8];
			uint64_t raw;
		} seed;
		
		seed.arr[0] = main[0];
		seed.arr[1] = main[1];
		seed.arr[2] = main[3];
		seed.arr[3] = main[5];
		seed.arr[4] = branch[0];
		seed.arr[5] = branch[1];
		seed.arr[6] = branch[2];
		seed.arr[7] = branch[4];
		
		generatorState = seed.raw ^ 0x106689D45497FDB5;
	}

	/**
	 *  Get next reproducible pseudo-random number based on device info
	 *  generatorSeed must be called before using this function
	 *
	 *  @return pseudo-random number
	 */
	uint64_t generatorRand() {
		uint64_t x = generatorState;
		x ^= x >> 12; // a
		x ^= x << 25; // b
		x ^= x >> 27; // c
		generatorState = x;
		return x * 0x2545F4914F6CDD1D;
	}

	/**
	 *  Get device information buffer
	 *
	 *  @param id  buffer id
	 *
	 *  @return pointer to the buffer
	 */
	SMC_DATA *getBuffer(Buffer id) {
		switch (id) {
			case Buffer::RevMain:
				return main;
			case Buffer::RevFlasherBase:
				return flasherBase;
			case Buffer::RevFlasherUpdate:
				return flasherUpdate;
			case Buffer::Branch:
				return branch;
			case Buffer::Platform:
				return platform;
			case Buffer::HardwareModel:
				return hardwareModel;
			case Buffer::MacAddress:
				return macAddress;
			case Buffer::Serial:
				return serial;
			case Buffer::MotherboardSerial:
				return motherboardSerial;
		}
	}

	/**
	 *  Get device information buffer size
	 *
	 *  @param id  buffer id
	 *
	 *  @return buffer size
	 */
	SMC_DATA_SIZE getBufferSize(Buffer id) {
		switch (id) {
			case Buffer::RevMain:
			case Buffer::RevFlasherBase:
			case Buffer::RevFlasherUpdate:
				return RevisionSize;
			case Buffer::Branch:
			case Buffer::Platform:
				return BranchSize;
			case Buffer::HardwareModel:
				return ModelSize;
			case Buffer::MacAddress:
				return MacSize;
			case Buffer::Serial:
				return SerialSize;
			case Buffer::MotherboardSerial:
				return MotherboardSerialSize;
		}
	}

	/**
	 *  Check if the necessary buffer information was supplied previously
	 *
	 *  @return true if version info is ok
	 */
	bool isValid() const {
		// Note, we do not check mac/serial validity, as they are optional!
		// Everything but platform was also removed by T2!
		return platform[0] && hardwareModel[0];
	}
};

#endif /* kern_smcinfo_h */
