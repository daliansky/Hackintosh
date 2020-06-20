//
//  kern_disasm.hpp
//  Lilu
//
//  Copyright © 2016-2017 vit9696. All rights reserved.
//

#ifndef kern_disasm_hpp
#define kern_disasm_hpp

#include <Headers/kern_config.hpp>
#include <Headers/hde64.h>
#include <Headers/kern_util.hpp>

#ifdef LILU_ADVANCED_DISASSEMBLY
#ifndef CAPSTONE_HAS_OSXKERNEL
#define CAPSTONE_HAS_OSXKERNEL 1
#endif
#include <Headers/capstone/capstone.h>
#endif /* LILU_ADVANCED_DISASSEMBLY */

#include <sys/types.h>
#include <mach/vm_types.h>

class Disassembler {
#ifdef LILU_ADVANCED_DISASSEMBLY
	/**
	 *  Because captsone handle can be 0
	 */
	bool initialised {false};

	/**
	 *  Internal capstone handle
	 */
	size_t handle {};
#endif

	/**
	 *  Max instruction size
	 */
	static constexpr size_t MaxInstruction {15};
public:

	/**
	 *  Return the real instruction size contained within min bytes
	 *  Unlike instructionSize this uses HDE engine and at the cost of reduced compatibility it is much faster
	 *  Note: instruction pointer should point to at least min + 32 valid bytes.
	 *
	 *  @param ptr instruction pointer
	 *  @param min minimal possible size
	 *
	 *  @return instruction size >= min on success or 0
	 */
	EXPORT static size_t quickInstructionSize(mach_vm_address_t ptr, size_t min);

	/* Note, code should point to at least 32 valid bytes. */
	EXPORT static size_t hdeDisasm(mach_vm_address_t code, hde64s *hs);
#ifdef LILU_ADVANCED_DISASSEMBLY

	/**
	 *  Initialise advanced dissassembling framework
	 *
	 *  @param detailed  debugging output necessity
	 *
	 *  @return true on success
	 */
	EXPORT bool init(bool detailed=false);

	/**
	 *  Deinitialise advanced dissassembling framework, must be called regardless of the init error
	 */
	EXPORT void deinit();

	/**
	 *  Reads size bytes from addr and disassembles them.
	 *
	 *  @param addr        Address to read from
	 *  @param size        Size of buffer to read
	 *  @param result      Disassembled instructions array. You must free it
	 *
	 *  @return size of result
	 */
	EXPORT size_t disasmBuf(mach_vm_address_t addr, size_t size, cs_insn **result);

	/**
	 *  Return the real instruction size contained within min bytes
	 *
	 *  @param ptr instruction pointer
	 *  @param min minimal possible size
	 *
	 *  @return instruction size >= min on success or 0
	 */
	EXPORT size_t instructionSize(mach_vm_address_t ptr, size_t min);

	/**
	 *  Reads lookup_size bytes from addr and disassembles them.
	 *  After disassembling, tries to find num-th entry with call instruction, which argument is an immediate value (some address).
	 *
	 *  @param addr        Address to read from
	 *  @param num         Number of call instruction to search for
	 *  @param lookup_size Number of bytes to read
	 *
	 *  @note It is assumed that the operand contains a positive relative address.
	 *
	 *  @return direct address of num-th call instruction on success, else 0
	 */
	EXPORT mach_vm_address_t disasmNthSub(mach_vm_address_t addr, size_t num, size_t lookup_size);

	/**
	 *  @brief  Reads lookup_size bytes from addr and disassembles them.
	 *
	 *  After disassembling, tries to find num-th entry with jmp instruction, which argument is an immediate value (some address).
	 *
	 *  @param addr        Address to read from
	 *  @param num         Number of jmp instruction to search for
	 *  @param lookup_size Number of bytes to read
	 *
	 *  @note It is assumed that the operand contains a positive relative address.
	 *
	 *  @return direct address of num-th jmp instruction on success, else 0
	 */
	EXPORT mach_vm_address_t disasmNthJmp(mach_vm_address_t addr, size_t num, size_t lookup_size);

	/**
	 *  Reads lookup_size bytes from addr and disassembles them.
	 *  After disassembling, tries to find num-th entry of inst instruction.
	 *
	 *  @param addr        Addres to read from
	 *  @param ins         Instruction code
	 *  @param num         Number of ins instruction to search for
	 *  @param lookup_size Number of bytes to read
	 *
	 *  @return address of found instruction on success, else 0
	 */
	EXPORT mach_vm_address_t disasmNthIns(mach_vm_address_t addr, x86_insn ins, size_t num, size_t lookup_size);

	/**
	 *  Disassembly matching structure
	 */
	struct DisasmSig {
		x86_insn ins;       // instruction
		bool sub;           // relevant only for X86_INS_CALL, if its arg is X86_OP_IMM
		bool addr;          // if you want to return the address of exact inst in sig

		static DisasmSig *create() { return new DisasmSig; }
		static void deleter(DisasmSig *sig NONNULL) { delete sig; }
	};

	/**
	 *  Reads lookup_size bytes from addr and disassembles them.
	 *  After disassembling, tries to find num-th entry of sig instruction pattern.
	 *
	 *  @param addr        Address to read from
	 *  @param sig         Instruction pattern
	 *  @param num         Order of pattern to search for
	 *  @param lookup_size Number of bytes to read
	 *
	 *  @return direct address of pattern start on success, else 0
	 */
	EXPORT mach_vm_address_t disasmSig(mach_vm_address_t addr, evector<DisasmSig *, DisasmSig::deleter> &sig, size_t num, size_t lookup_size);

#endif /* LILU_ADVANCED_DISASSEMBLY */
};

#endif /* kern_disasm_hpp */
