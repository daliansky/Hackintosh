#
#  entry64.S
#  Lilu
#
#  Copyright © 2018 vit9696. All rights reserved.
#

.text
.global _main
_main:
  push  %rbp
  mov   %rsp, %rbp
  # ensure 16-byte alignment
  and   $0xfffffffffffffff0, %rsp
  # int main(int argc, const char* argv[], const char* envp[], const char* apple[]);
  push  %rdi
  push  %rsi
  push  %rdx
  push  %rcx
  call  *booter(%rip)
  xor   %eax, %eax
  pop   %rcx
  pop   %rdx
  pop   %rsi
  pop   %rdi
  mov   %rbp, %rsp
  pop   %rbp
  jmp   *entrypoint(%rip)
# original entrypoint (main)
entrypoint:
  .word 0xFFFF
  .word 0xFFFF
  .word 0xFFFF
  .word 0xFFFF
# entrypoint-compatible wrapper
booter:
  .word 0xFFFF
  .word 0xFFFF
  .word 0xFFFF
  .word 0xFFFF
_end:
