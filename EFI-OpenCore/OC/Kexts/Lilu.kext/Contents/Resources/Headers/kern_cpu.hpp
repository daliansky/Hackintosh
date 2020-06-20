//
//  kern_cpu.hpp
//  Lilu
//
//  Copyright © 2018 vit9696. All rights reserved.
//

#ifndef kern_cpu_h
#define kern_cpu_h

#include <Headers/kern_config.hpp>
#include <Headers/kern_iokit.hpp>
#include <Headers/kern_util.hpp>

#include <Library/LegacyIOService.h>

/**
 *  XNU CPU-related exports missing from headers
 */
extern "C" {
	int cpu_number(void);
	void mp_rendezvous_no_intrs(void (*action_func)(void *), void *arg);
};

namespace CPUInfo {
	/**
	 *  Keep this in sync to XNU MAX_CPUS from osfmk/i386/mp.h
	 */
	static constexpr size_t MaxCpus {64};

	/**
	 *  Contents of CPUID(1) eax register contents describing model version
	 */
	struct CpuVersion {
		uint32_t stepping       : 4;
		uint32_t model          : 4;
		uint32_t family         : 4;
		uint32_t type           : 2;
		uint32_t reserved1      : 2;
		uint32_t extendedModel  : 4;
		uint32_t extendedFamily : 8;
		uint32_t reserved2      : 4;
	};

	static_assert(sizeof(CpuVersion) == sizeof(uint32_t), "CpuVersion size mismatch!");

	/**
	 *  Intel CPU models as returned by CPUID
	 *  The list is synchronised and updated with XNU source code (osfmk/i386/cpuid.h).
	 *  Names are altered to avoid conflicts just in case.
	 *  Last update: xnu-4903.221.2
	 *  Some details could be found on http://instlatx64.atw.hu and https://en.wikichip.org/wiki/64-bit_architecture#x86
	 *  Also: https://www.intel.com/content/dam/www/public/us/en/documents/sa00115-microcode-update-guidance.pdf
	 */
	enum CpuModel {
		CPU_MODEL_UNKNOWN        =  0x00,
		CPU_MODEL_PENRYN         =  0x17,
		CPU_MODEL_NEHALEM        =  0x1A,
		CPU_MODEL_FIELDS         =  0x1E, /* Lynnfield, Clarksfield */
		CPU_MODEL_DALES          =  0x1F, /* Havendale, Auburndale */
		CPU_MODEL_NEHALEM_EX     =  0x2E,
		CPU_MODEL_DALES_32NM     =  0x25, /* Clarkdale, Arrandale */
		CPU_MODEL_WESTMERE       =  0x2C, /* Gulftown, Westmere-EP/-WS */
		CPU_MODEL_WESTMERE_EX    =  0x2F,
		CPU_MODEL_SANDYBRIDGE    =  0x2A,
		CPU_MODEL_JAKETOWN       =  0x2D,
		CPU_MODEL_IVYBRIDGE      =  0x3A,
		CPU_MODEL_IVYBRIDGE_EP   =  0x3E,
		CPU_MODEL_CRYSTALWELL    =  0x46,
		CPU_MODEL_HASWELL        =  0x3C,
		CPU_MODEL_HASWELL_EP     =  0x3F,
		CPU_MODEL_HASWELL_ULT    =  0x45,
		CPU_MODEL_BROADWELL      =  0x3D,
		CPU_MODEL_BROADWELL_ULX  =  0x3D,
		CPU_MODEL_BROADWELL_ULT  =  0x3D,
		CPU_MODEL_BRYSTALWELL    =  0x47,
		CPU_MODEL_SKYLAKE        =  0x4E,
		CPU_MODEL_SKYLAKE_ULT    =  0x4E,
		CPU_MODEL_SKYLAKE_ULX    =  0x4E,
		CPU_MODEL_SKYLAKE_DT     =  0x5E,
		CPU_MODEL_SKYLAKE_W      =  0x55,
		CPU_MODEL_KABYLAKE       =  0x8E,
		CPU_MODEL_KABYLAKE_ULT   =  0x8E,
		CPU_MODEL_KABYLAKE_ULX   =  0x8E,
		CPU_MODEL_KABYLAKE_DT    =  0x9E,
		CPU_MODEL_CANNONLAKE     =  0x66,
		CPU_MODEL_ICELAKE_Y      =  0x7D,
		CPU_MODEL_ICELAKE_U      =  0x7E,
		CPU_MODEL_ICELAKE_SP     =  0x9F, /* Some variation of Ice Lake */
		CPU_MODEL_COMETLAKE_S    =  0xA5, /* desktop CometLake */
		CPU_MODEL_COMETLAKE_Y    =  0xA5, /* aka 10th generation Amber Lake Y */
		CPU_MODEL_COMETLAKE_U    =  0xA6,
	};

	/**
	 *  Known CPU vendors
	 */
	enum class CpuVendor {
		Unknown,
		AMD,
		Intel
		/* Add more processors here if needed */
	};

	/**
	 *  Intel CPU generations (starting from 0)
	 */
	enum class CpuGeneration {
		Unknown,
		Penryn,
		Nehalem,
		Westmere,
		SandyBridge,
		IvyBridge,
		Haswell,
		Broadwell,
		Skylake,
		KabyLake,
		CoffeeLake,
		CannonLake,
		IceLake,
		CometLake,
		MaxGeneration
	};

	/* Responses identification request with %eax 0 */
	/* AMD:     "AuthenticAMD" */
	static constexpr uint32_t signature_AMD_ebx = 0x68747541;
	static constexpr uint32_t signature_AMD_edx = 0x69746e65;
	static constexpr uint32_t signature_AMD_ecx = 0x444d4163;
	/* CENTAUR: "CentaurHauls" */
	static constexpr uint32_t signature_CENTAUR_ebx = 0x746e6543;
	static constexpr uint32_t signature_CENTAUR_edx = 0x48727561;
	static constexpr uint32_t signature_CENTAUR_ecx = 0x736c7561;
	/* CYRIX:   "CyrixInstead" */
	static constexpr uint32_t signature_CYRIX_ebx = 0x69727943;
	static constexpr uint32_t signature_CYRIX_edx = 0x736e4978;
	static constexpr uint32_t signature_CYRIX_ecx = 0x64616574;
	/* INTEL:   "GenuineIntel" */
	static constexpr uint32_t signature_INTEL_ebx = 0x756e6547;
	static constexpr uint32_t signature_INTEL_edx = 0x49656e69;
	static constexpr uint32_t signature_INTEL_ecx = 0x6c65746e;
	/* TM1:     "TransmetaCPU" */
	static constexpr uint32_t signature_TM1_ebx = 0x6e617254;
	static constexpr uint32_t signature_TM1_edx = 0x74656d73;
	static constexpr uint32_t signature_TM1_ecx = 0x55504361;
	/* TM2:     "GenuineTMx86" */
	static constexpr uint32_t signature_TM2_ebx = 0x756e6547;
	static constexpr uint32_t signature_TM2_edx = 0x54656e69;
	static constexpr uint32_t signature_TM2_ecx = 0x3638784d;
	/* NSC:     "Geode by NSC" */
	static constexpr uint32_t signature_NSC_ebx = 0x646f6547;
	static constexpr uint32_t signature_NSC_edx = 0x43534e20;
	static constexpr uint32_t signature_NSC_ecx = 0x79622065;
	/* NEXGEN:  "NexGenDriven" */
	static constexpr uint32_t signature_NEXGEN_ebx = 0x4778654e;
	static constexpr uint32_t signature_NEXGEN_edx = 0x72446e65;
	static constexpr uint32_t signature_NEXGEN_ecx = 0x6e657669;
	/* RISE:    "RiseRiseRise" */
	static constexpr uint32_t signature_RISE_ebx = 0x65736952;
	static constexpr uint32_t signature_RISE_edx = 0x65736952;
	static constexpr uint32_t signature_RISE_ecx = 0x65736952;
	/* SIS:     "SiS SiS SiS " */
	static constexpr uint32_t signature_SIS_ebx = 0x20536953;
	static constexpr uint32_t signature_SIS_edx = 0x20536953;
	static constexpr uint32_t signature_SIS_ecx = 0x20536953;
	/* UMC:     "UMC UMC UMC " */
	static constexpr uint32_t signature_UMC_ebx = 0x20434d55;
	static constexpr uint32_t signature_UMC_edx = 0x20434d55;
	static constexpr uint32_t signature_UMC_ecx = 0x20434d55;
	/* VIA:     "VIA VIA VIA " */
	static constexpr uint32_t signature_VIA_ebx = 0x20414956;
	static constexpr uint32_t signature_VIA_edx = 0x20414956;
	static constexpr uint32_t signature_VIA_ecx = 0x20414956;
	/* VORTEX:  "Vortex86 SoC" */
	static constexpr uint32_t signature_VORTEX_ebx = 0x74726f56;
	static constexpr uint32_t signature_VORTEX_edx = 0x36387865;
	static constexpr uint32_t signature_VORTEX_ecx = 0x436f5320;

	/* Features in %ecx for leaf 1 */
	static constexpr uint32_t bit_SSE3        = 0x00000001;
	static constexpr uint32_t bit_PCLMULQDQ   = 0x00000002;
	static constexpr uint32_t bit_DTES64      = 0x00000004;
	static constexpr uint32_t bit_MONITOR     = 0x00000008;
	static constexpr uint32_t bit_DSCPL       = 0x00000010;
	static constexpr uint32_t bit_VMX         = 0x00000020;
	static constexpr uint32_t bit_SMX         = 0x00000040;
	static constexpr uint32_t bit_EIST        = 0x00000080;
	static constexpr uint32_t bit_TM2         = 0x00000100;
	static constexpr uint32_t bit_SSSE3       = 0x00000200;
	static constexpr uint32_t bit_CNXTID      = 0x00000400;
	static constexpr uint32_t bit_FMA         = 0x00001000;
	static constexpr uint32_t bit_CMPXCHG16B  = 0x00002000;
	static constexpr uint32_t bit_xTPR        = 0x00004000;
	static constexpr uint32_t bit_PDCM        = 0x00008000;
	static constexpr uint32_t bit_PCID        = 0x00020000;
	static constexpr uint32_t bit_DCA         = 0x00040000;
	static constexpr uint32_t bit_SSE41       = 0x00080000;
	static constexpr uint32_t bit_SSE42       = 0x00100000;
	static constexpr uint32_t bit_x2APIC      = 0x00200000;
	static constexpr uint32_t bit_MOVBE       = 0x00400000;
	static constexpr uint32_t bit_POPCNT      = 0x00800000;
	static constexpr uint32_t bit_TSCDeadline = 0x01000000;
	static constexpr uint32_t bit_AESNI       = 0x02000000;
	static constexpr uint32_t bit_XSAVE       = 0x04000000;
	static constexpr uint32_t bit_OSXSAVE     = 0x08000000;
	static constexpr uint32_t bit_AVX         = 0x10000000;
	static constexpr uint32_t bit_F16C        = 0x20000000;
	static constexpr uint32_t bit_RDRND       = 0x40000000;

	/* Features in %edx for leaf 1 */
	static constexpr uint32_t bit_FPU         = 0x00000001;
	static constexpr uint32_t bit_VME         = 0x00000002;
	static constexpr uint32_t bit_DE          = 0x00000004;
	static constexpr uint32_t bit_PSE         = 0x00000008;
	static constexpr uint32_t bit_TSC         = 0x00000010;
	static constexpr uint32_t bit_MSR         = 0x00000020;
	static constexpr uint32_t bit_PAE         = 0x00000040;
	static constexpr uint32_t bit_MCE         = 0x00000080;
	static constexpr uint32_t bit_CX8         = 0x00000100;
	static constexpr uint32_t bit_APIC        = 0x00000200;
	static constexpr uint32_t bit_SEP         = 0x00000800;
	static constexpr uint32_t bit_MTRR        = 0x00001000;
	static constexpr uint32_t bit_PGE         = 0x00002000;
	static constexpr uint32_t bit_MCA         = 0x00004000;
	static constexpr uint32_t bit_CMOV        = 0x00008000;
	static constexpr uint32_t bit_PAT         = 0x00010000;
	static constexpr uint32_t bit_PSE36       = 0x00020000;
	static constexpr uint32_t bit_PSN         = 0x00040000;
	static constexpr uint32_t bit_CLFSH       = 0x00080000;
	static constexpr uint32_t bit_DS          = 0x00200000;
	static constexpr uint32_t bit_ACPI        = 0x00400000;
	static constexpr uint32_t bit_MMX         = 0x00800000;
	static constexpr uint32_t bit_FXSR        = 0x01000000;
	static constexpr uint32_t bit_SSE         = 0x02000000;
	static constexpr uint32_t bit_SSE2        = 0x04000000;
	static constexpr uint32_t bit_SS          = 0x08000000;
	static constexpr uint32_t bit_HTT         = 0x10000000;
	static constexpr uint32_t bit_TM          = 0x20000000;
	static constexpr uint32_t bit_PBE         = 0x80000000;

	/* Features in %ebx for leaf 7 sub-leaf 0 */
	static constexpr uint32_t bit_FSGSBASE    = 0x00000001;
	static constexpr uint32_t bit_SGX         = 0x00000004;
	static constexpr uint32_t bit_BMI         = 0x00000008;
	static constexpr uint32_t bit_HLE         = 0x00000010;
	static constexpr uint32_t bit_AVX2        = 0x00000020;
	static constexpr uint32_t bit_SMEP        = 0x00000080;
	static constexpr uint32_t bit_BMI2        = 0x00000100;
	static constexpr uint32_t bit_ENH_MOVSB   = 0x00000200;
	static constexpr uint32_t bit_RTM         = 0x00000800;
	static constexpr uint32_t bit_MPX         = 0x00004000;
	static constexpr uint32_t bit_AVX512F     = 0x00010000;
	static constexpr uint32_t bit_AVX512DQ    = 0x00020000;
	static constexpr uint32_t bit_RDSEED      = 0x00040000;
	static constexpr uint32_t bit_ADX         = 0x00080000;
	static constexpr uint32_t bit_AVX512IFMA  = 0x00200000;
	static constexpr uint32_t bit_CLFLUSHOPT  = 0x00800000;
	static constexpr uint32_t bit_CLWB        = 0x01000000;
	static constexpr uint32_t bit_AVX512PF    = 0x04000000;
	static constexpr uint32_t bit_AVX51SER    = 0x08000000;
	static constexpr uint32_t bit_AVX512CD    = 0x10000000;
	static constexpr uint32_t bit_SHA         = 0x20000000;
	static constexpr uint32_t bit_AVX512BW    = 0x40000000;
	static constexpr uint32_t bit_AVX512VL    = 0x80000000;

	/* Features in %ecx for leaf 7 sub-leaf 0 */
	static constexpr uint32_t bit_PREFTCHWT1  = 0x00000001;
	static constexpr uint32_t bit_AVX512VBMI  = 0x00000002;
	static constexpr uint32_t bit_PKU         = 0x00000004;
	static constexpr uint32_t bit_OSPKE       = 0x00000010;
	static constexpr uint32_t bit_AVX512VPOPCNTDQ  = 0x00004000;
	static constexpr uint32_t bit_RDPID       = 0x00400000;

	/* Features in %edx for leaf 7 sub-leaf 0 */
	static constexpr uint32_t bit_AVX5124VNNIW  = 0x00000004;
	static constexpr uint32_t bit_AVX5124FMAPS  = 0x00000008;

	/* Features in %eax for leaf 13 sub-leaf 1 */
	static constexpr uint32_t bit_XSAVEOPT    = 0x00000001;
	static constexpr uint32_t bit_XSAVEC      = 0x00000002;
	static constexpr uint32_t bit_XSAVES      = 0x00000008;

	/* Features in %ecx for leaf = 0x80000001 */;
	static constexpr uint32_t bit_LAHF_LM     = 0x00000001;
	static constexpr uint32_t bit_ABM         = 0x00000020;
	static constexpr uint32_t bit_SSE4a       = 0x00000040;
	static constexpr uint32_t bit_PRFCHW      = 0x00000100;
	static constexpr uint32_t bit_XOP         = 0x00000800;
	static constexpr uint32_t bit_LWP         = 0x00008000;
	static constexpr uint32_t bit_FMA4        = 0x00010000;
	static constexpr uint32_t bit_TBM         = 0x00200000;
	static constexpr uint32_t bit_MWAITX      = 0x20000000;

	/* Features in %edx for leaf = 0x80000001 */;
	static constexpr uint32_t bit_MMXEXT      = 0x00400000;
	static constexpr uint32_t bit_LM          = 0x20000000;
	static constexpr uint32_t bit_3DNOWP      = 0x40000000;
	static constexpr uint32_t bit_3DNOW       = 0x80000000;

	/* Features in %ebx for leaf = 0x80000001 */;
	static constexpr uint32_t bit_CLZERO      = 0x00000001;

	/**
	 *  Reads CPU information and other data.
	 */
	void init();

	/**
	 *  Installed CPU information mapping
	 */
	struct CpuTopology {
		/**
		 *  Number of physical processors installed
		 */
		uint8_t packageCount {0};

		/**
		 *  Number of physical cores per package
		 */
		uint8_t physicalCount[MaxCpus] {};

		/**
		 *  Number of logical cores per package
		 */
		uint8_t logicalCount[MaxCpus] {};

		/**
		 *  Total number of physical cores
		 */
		inline uint8_t totalPhysical() {
			uint8_t count = physicalCount[0];
			for (uint8_t i = 1; i < packageCount; i++)
				count += physicalCount[i];
			return count;
		}

		/**
		 *  Total number of logical cores
		 */
		inline uint8_t totalLogical() {
			uint8_t count = logicalCount[0];
			for (uint8_t i = 1; i < packageCount; i++)
				count += logicalCount[i];
			return count;
		}

		/**
		 *  Mapping of cpu_number() to CPU package from 0 to packageCount
		 */
		uint8_t numberToPackage[MaxCpus] {};

		/**
		 *  Mapping of cpu_number() to physical core from 0 to physicalCount in package
		 */
		uint8_t numberToPhysical[MaxCpus] {};

		/**
		 *  Mapping of cpu_number() to physical cores from 0 to totalPhysical.
		 */
		inline uint8_t numberToPhysicalUnique(uint8_t i) {
			uint8_t num = 0;
			uint8_t package = numberToPackage[i];
			for (uint8_t i = 0; i < package; i++)
				num += physicalCount[i];
			return num + numberToPhysical[i];
		}

		/**
		 *  Mapping of cpu_number() to logical thread from 0 to logicalCount in package
		 *  Note, that the list is sorted, and the first physicalCount logical threads
		 *  correspond to their corresponding physical cores.
		 */
		uint8_t numberToLogical[MaxCpus] {};
	};

	/**
	 *  Get running CPU generation.
	 *
	 *  @param ofamily    a pointer to store CPU family in
	 *  @param omodel     a pointer to store CPU model in
	 *  @param ostepping  a pointer to store CPU stepping in
	 *
	 *  @return detected Intel CPU generation
	 */
	EXPORT CpuGeneration getGeneration(uint32_t *ofamily=nullptr, uint32_t *omodel=nullptr, uint32_t *ostepping=nullptr)  DEPRECATE("Use BaseDeviceInfo");;

	/**
	 *  Obtain CPU topology.
	 *
	 *  @param topology  parsed cpu topology, must be passed zeroed.
	 *
	 *  @return true on success
	 */
	EXPORT bool getCpuTopology(CpuTopology &topology);

	/**
	 *  Obtain cpuid registers
	 *
	 *  @param no     cpuid number
	 *  @param count  cpuid count
	 *  @param a      eax output pointer (optional)
	 *  @param b      ebx output pointer (optional)
	 *  @param c      ecx output pointer (optional)
	 *  @param d      edx output pointer (optional)
	 *
	 *  @return true if supported
	 */
	EXPORT bool getCpuid(uint32_t no, uint32_t count, uint32_t *a, uint32_t *b=nullptr, uint32_t *c=nullptr, uint32_t *d=nullptr);
}

#endif /* kern_cpu_h */
