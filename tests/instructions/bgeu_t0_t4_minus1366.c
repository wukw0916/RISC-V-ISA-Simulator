#include "test_main.h"
int main() {
    // BGEU t0, t4, -1366
   //B_INSTRUCTION decoded = as_b_instruction(0xABD2F5E3);
   //printf("op:0x%02X\nfunct3:0x%01X\nrs1:x%d\nrs2:x%d\nimm:%d\n",decoded.opcode,decoded.func3,decoded.rs1,decoded.rs2,decoded.imm);
   //return is_bgeu_instruction(&decoded);
   return !(IS_INSTRUCTION(0xABD2F5E3, b, bgeu));
}

