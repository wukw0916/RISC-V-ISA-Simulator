// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#include <stdbool.h>
#include <stdint.h>
#include "core.h"
#include "instructions.h"

R_INSTRUCTION as_r_instruction(uint32_t instruction) {
    return (R_INSTRUCTION) {
        .op0 = (
            // <TotalBits=3>
            // <Start=0> <End=3> <Length=3> <Offset=0> <Zero=false>
            ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 3)) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=6>
            // <Start=4> <End=10> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 4) & (0xFFFFFFFF >> (32 + 4 - 10)) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=6>
            // <Start=11> <End=17> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 11) & (0xFFFFFFFF >> (32 + 11 - 17)) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=6>
            // <Start=18> <End=24> <Length=6> <Offset=0> <Zero=false>
            ((instruction << 18) & (0xFFFFFFFF >> (32 + 18 - 24)) << 0)
            |
            // Unsigned
            0
        ),
        .op1 = (
            // <TotalBits=2>
            // <Start=25> <End=27> <Length=3> <Offset=0> <Zero=false>
            ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 27)) << 0)
            |
            // Unsigned
            0
        ),
        .op2 = (
            // <TotalBits=1>
            // <Start=28> <End=29> <Length=1> <Offset=0> <Zero=false>
            ((instruction << 28) & (0xFFFFFFFF >> (32 + 28 - 29)) << 0)
            |
            // Unsigned
            0
        ),
        .rnd = (
            // <TotalBits=1>
            // <Start=30> <End=31> <Length=1> <Offset=0> <Zero=false>
            ((instruction << 30) & (0xFFFFFFFF >> (32 + 30 - 31)) << 0)
            |
            // Unsigned
            0
        )
    };
}

// I_INSTRUCTION as_i_instruction(uint32_t instruction) {
//     return (I_INSTRUCTION) {
//         .opcode = (
//             // <TotalBits=7>
//             // <Start=0> <End=7> <Length=7> <Offset=0> <Zero=false>
//             ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 7)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .rd = (
//             // <TotalBits=5>
//             // <Start=6> <End=11> <Length=5> <Offset=0> <Zero=false>
//             ((instruction << 6) & (0xFFFFFFFF >> (32 + 6 - 11)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .func3 = (
//             // <TotalBits=2>
//             // <Start=12> <End=14> <Length=2> <Offset=0> <Zero=false>
//             ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 14)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .rs1 = (
//             // <TotalBits=4>
//             // <Start=15> <End=19> <Length=4> <Offset=0> <Zero=false>
//             ((instruction << 15) & (0xFFFFFFFF >> (32 + 15 - 19)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .imm = (
//             // <TotalBits=7>
//             // <Start=null> <End=null> <Length=1> <Offset=0> <Zero=true>
//             0
//             |
//             // <Start=25> <End=31> <Length=6> <Offset=1> <Zero=false>
//             ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 31)) << 1)
//             |
//             // Signed <Bits=7>
//             ((instruction >> (7 - 1)) == 0 ? 0 : (0xFFFFFFFF << 7))
//         )
//     };
// }

// S_INSTRUCTION as_s_instruction(uint32_t instruction) {
//     return (S_INSTRUCTION) {
//         .opcode = (
//             // <TotalBits=6>
//             // <Start=0> <End=6> <Length=6> <Offset=0> <Zero=false>
//             ((instruction << 0) & (0xFFFFFFFF >> (32 + 0 - 6)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .func3 = (
//             // <TotalBits=2>
//             // <Start=12> <End=14> <Length=2> <Offset=0> <Zero=false>
//             ((instruction << 12) & (0xFFFFFFFF >> (32 + 12 - 14)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .rs1 = (
//             // <TotalBits=4>
//             // <Start=15> <End=19> <Length=4> <Offset=0> <Zero=false>
//             ((instruction << 15) & (0xFFFFFFFF >> (32 + 15 - 19)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .rs2 = (
//             // <TotalBits=4>
//             // <Start=20> <End=24> <Length=4> <Offset=0> <Zero=false>
//             ((instruction << 20) & (0xFFFFFFFF >> (32 + 20 - 24)) << 0)
//             |
//             // Unsigned
//             0
//         ),
//         .imm = (
//             // <TotalBits=10>
//             // <Start=7> <End=11> <Length=4> <Offset=0> <Zero=false>
//             ((instruction << 7) & (0xFFFFFFFF >> (32 + 7 - 11)) << 0)
//             |
//             // <Start=25> <End=31> <Length=6> <Offset=4> <Zero=false>
//             ((instruction << 25) & (0xFFFFFFFF >> (32 + 25 - 31)) << 4)
//             |
//             // Unsigned
//             0
//         )
//     };
// }

bool is_fadd_instruction(uint32_t instruction, R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b0111) return false;
    if (decoded_instruction->op2 != 0b00) return false;
    if (decoded_instruction->rnd != 0b00) return false;
    return true;
}

// bool is_sub_instruction(uint32_t instruction, R_INSTRUCTION* decoded_instruction) {
//     if (decoded_instruction->opcode != 0b0110011) return false;
//     if (decoded_instruction->func3 != 0b000) return false;
//     if (decoded_instruction->func7 != 0b0100000) return false;
//     return true;
// }

// bool is_lw_instruction(uint32_t instruction, I_INSTRUCTION* decoded_instruction) {
//     if (decoded_instruction->opcode != 0b0000011) return false;
//     if (decoded_instruction->func3 != 0b010) return false;
//     return true;
// }
