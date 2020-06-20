#
#  entry32.S
#  Lilu
#
#  Copyright © 2018 vit9696. All rights reserved.
#

.text
.global _main
_main:
  push  %ebp
  mov   %esp, %ebp
  # ensure 16-byte alignment
  and   $0xfffffff0, %esp
  # int main(int argc, const char* argv[], const char* envp[], const char* apple[]);
  push  20(%ebp)
  push  16(%ebp)
  push  12(%ebp)
  push  8(%ebp)
  call  get_booter
# entrypoint-compatible wrapper
booter:
  .word 0xFFFF
  .word 0xFFFF
get_booter:
  pop   %edx
  mov   (%edx), %edx
  call  *%edx
  xor   %eax, %eax
  mov   %ebp, %esp
  pop   %ebp
  call  get_entrypoint
# original entrypoint (main)
entrypoint:
  .word 0xFFFF
  .word 0xFFFF
get_entrypoint:
  pop   %edx
  mov   (%edx), %edx
  jmp   *%edx
_end:
