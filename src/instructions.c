// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#include <stdbool.h>
#include <stdint.h>
#include "core.h"
#include "instructions.h"

char format_memory[64];

#define get_word_bits(instruction, start, end) \
    ((instruction >> start) & (((uint32_t) ~0) >> (32 + start - end)))


R_INSTRUCTION as_r_instruction(uint32_t instruction) {
    R_INSTRUCTION d = {
        .op0 = (
            // <TotalBits=4>
            // <Start=0> <End=3> <Length=4> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 0, 3) << 0)
            |
            // Unsigned
            0
        ),
        .rd = (
            // <TotalBits=7>
            // <Start=4> <End=10> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 4, 10) << 0)
            |
            // Unsigned
            0
        ),
        .rs1 = (
            // <TotalBits=7>
            // <Start=11> <End=17> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 11, 17) << 0)
            |
            // Unsigned
            0
        ),
        .rs2 = (
            // <TotalBits=7>
            // <Start=18> <End=24> <Length=7> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 18, 24) << 0)
            |
            // Unsigned
            0
        ),
        .op1 = (
            // <TotalBits=3>
            // <Start=25> <End=27> <Length=3> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 25, 27) << 0)
            |
            // Unsigned
            0
        ),
        .op2 = (
            // <TotalBits=2>
            // <Start=28> <End=29> <Length=2> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 28, 29) << 0)
            |
            // Unsigned
            0
        ),
        .type = (
            // <TotalBits=2>
            // <Start=30> <End=31> <Length=2> <Offset=0> <Zero=false>
            (get_word_bits(instruction, 30, 31) << 0)
            |
            // Unsigned
            0
        )
    };
    if (d.op0 > (1 << 4))
        FAIL("R_INSTRUCTION.op0 decode error: size %d", d.op0);
    if (d.rd > (1 << 7))
        FAIL("R_INSTRUCTION.rd decode error: size %d", d.rd);
    if (d.rs1 > (1 << 7))
        FAIL("R_INSTRUCTION.rs1 decode error: size %d", d.rs1);
    if (d.rs2 > (1 << 7))
        FAIL("R_INSTRUCTION.rs2 decode error: size %d", d.rs2);
    if (d.op1 > (1 << 3))
        FAIL("R_INSTRUCTION.op1 decode error: size %d", d.op1);
    if (d.op2 > (1 << 2))
        FAIL("R_INSTRUCTION.op2 decode error: size %d", d.op2);
    if (d.type > (1 << 2))
        FAIL("R_INSTRUCTION.type decode error: size %d", d.type);
    return d;
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

bool is_slt_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_slt_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b011) return false;
    if (decoded_instruction->op2 != 0b00) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

int count_all_instruction_matches(uint32_t encoded_instruction) {
    int count = 0;
    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    // I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    // S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    // U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    // B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    // J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);
    // count += is_add_instruction(&r_instruction);
    // count += is_sub_instruction(&r_instruction);
    // count += is_sll_instruction(&r_instruction);
    count += is_slt_instruction(&r_instruction);
    // count += is_sltu_instruction(&r_instruction);
    // count += is_xor_instruction(&r_instruction);
    // count += is_srl_instruction(&r_instruction);
    // count += is_sra_instruction(&r_instruction);
    // count += is_or_instruction(&r_instruction);
    // count += is_and_instruction(&r_instruction);
    // count += is_addi_instruction(&i_instruction);
    // count += is_slti_instruction(&i_instruction);
    // count += is_sltiu_instruction(&i_instruction);
    // count += is_xori_instruction(&i_instruction);
    // count += is_ori_instruction(&i_instruction);
    // count += is_andi_instruction(&i_instruction);
    // count += is_slli_instruction(&i_instruction);
    // count += is_srli_instruction(&i_instruction);
    // count += is_srai_instruction(&i_instruction);
    // count += is_beq_instruction(&b_instruction);
    // count += is_bne_instruction(&b_instruction);
    // count += is_blt_instruction(&b_instruction);
    // count += is_bge_instruction(&b_instruction);
    // count += is_bltu_instruction(&b_instruction);
    // count += is_bgeu_instruction(&b_instruction);
    // count += is_lui_instruction(&u_instruction);
    // count += is_auipc_instruction(&u_instruction);
    // count += is_jal_instruction(&j_instruction);
    // count += is_jalr_instruction(&i_instruction);
    // count += is_lb_instruction(&i_instruction);
    // count += is_lh_instruction(&i_instruction);
    // count += is_lw_instruction(&i_instruction);
    // count += is_lbu_instruction(&i_instruction);
    // count += is_lhu_instruction(&i_instruction);
    // count += is_sb_instruction(&s_instruction);
    // count += is_sh_instruction(&s_instruction);
    // count += is_sw_instruction(&s_instruction);
    // count += is_sbu_instruction(&s_instruction);
    // count += is_shu_instruction(&s_instruction);
    return count;
}


char* format_instruction(uint32_t encoded_instruction) {
    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    // I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    // S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    // U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    // B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    // J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);

    if (is_slt_instruction(&r_instruction)) return format_slt_operation(&r_instruction);
    return NULL;
}


char* format_slt_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_slt_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLT <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
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
