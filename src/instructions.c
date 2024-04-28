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

bool is_shl_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_shl_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b000) return false;
    if (decoded_instruction->op2 != 0b01) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_shr_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_shr_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b000) return false;
    if (decoded_instruction->op2 != 0b10) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_and_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_and_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b000) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_or_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_or_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b000) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b01) return false;
    return true;
}

bool is_not_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_not_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b000) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b10) return false;
    return true;
}

bool is_xor_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_xor_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b000) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b11) return false;
    return true;
}

bool is_add_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_add_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b010) return false;
    if (decoded_instruction->op2 != 0b00) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_sub_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_add_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b010) return false;
    if (decoded_instruction->op2 != 0b01) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_mul_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_mul_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b010) return false;
    if (decoded_instruction->op2 != 0b10) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_div_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_div_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b010) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_slt_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_slt_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b011) return false;
    if (decoded_instruction->op2 != 0b00) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_sle_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sle_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b011) return false;
    if (decoded_instruction->op2 != 0b01) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_seq_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_seq_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b011) return false;
    if (decoded_instruction->op2 != 0b10) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_sne_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_sne_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b011) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_min_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_min_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b100) return false;
    if (decoded_instruction->op2 != 0b00) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_max_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_min_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b100) return false;
    if (decoded_instruction->op2 != 0b01) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_rem_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_rem_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b100) return false;
    if (decoded_instruction->op2 != 0b10) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_mod_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_mod_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b100) return false;
    if (decoded_instruction->op2 != 0b11) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

// # R-rnd
bool is_fadd_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_fadd_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b111) return false;
    if (decoded_instruction->op2 != 0b00) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_fsub_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_fsub_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b111) return false;
    if (decoded_instruction->op2 != 0b01) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_fmul_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_fmul_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b111) return false;
    if (decoded_instruction->op2 != 0b10) return false;
    if (decoded_instruction->type != 0b00) return false;
    return true;
}

bool is_fdiv_instruction(const R_INSTRUCTION* decoded_instruction) {
    if (decoded_instruction == NULL) FAIL("Received NULL pointer on is_fdiv_instruction");
    if (decoded_instruction->op0 != 0b0000) return false;
    if (decoded_instruction->op1 != 0b111) return false;
    if (decoded_instruction->op2 != 0b11) return false;
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
    count += is_shl_instruction(&r_instruction);
    count += is_shr_instruction(&r_instruction);
    count += is_and_instruction(&r_instruction);
    count += is_or_instruction(&r_instruction);
    count += is_not_instruction(&r_instruction);
    count += is_xor_instruction(&r_instruction);
    count += is_add_instruction(&r_instruction);
    count += is_sub_instruction(&r_instruction);
    count += is_mul_instruction(&r_instruction);
    count += is_div_instruction(&r_instruction);
    count += is_slt_instruction(&r_instruction);
    count += is_sle_instruction(&r_instruction);
    count += is_seq_instruction(&r_instruction);
    count += is_sne_instruction(&r_instruction);
    count += is_min_instruction(&r_instruction);
    count += is_max_instruction(&r_instruction);
    count += is_rem_instruction(&r_instruction);
    count += is_mod_instruction(&r_instruction);
    count += is_fadd_instruction(&r_instruction);
    count += is_fsub_instruction(&r_instruction);
    count += is_fmul_instruction(&r_instruction);
    count += is_fdiv_instruction(&r_instruction);
    return count;
}


char* format_instruction(uint32_t encoded_instruction) {
    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    // I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    // S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    // U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    // B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    // J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);
    if (is_shl_instruction(&r_instruction)) return format_shl_operation(&r_instruction);
    if (is_shr_instruction(&r_instruction)) return format_shr_operation(&r_instruction);
    if (is_and_instruction(&r_instruction)) return format_and_operation(&r_instruction);
    if (is_or_instruction(&r_instruction)) return format_or_operation(&r_instruction);
    // if (is_not_instruction(&r_instruction)) return format_not_operation(&r_instruction);
    if (is_xor_instruction(&r_instruction)) return format_xor_operation(&r_instruction);
    if (is_add_instruction(&r_instruction)) return format_add_operation(&r_instruction);
    if (is_sub_instruction(&r_instruction)) return format_sub_operation(&r_instruction);
    if (is_mul_instruction(&r_instruction)) return format_mul_operation(&r_instruction);
    if (is_div_instruction(&r_instruction)) return format_div_operation(&r_instruction);
    if (is_slt_instruction(&r_instruction)) return format_slt_operation(&r_instruction);
    if (is_sle_instruction(&r_instruction)) return format_sle_operation(&r_instruction);
    if (is_seq_instruction(&r_instruction)) return format_seq_operation(&r_instruction);
    if (is_sne_instruction(&r_instruction)) return format_sne_operation(&r_instruction);
    if (is_min_instruction(&r_instruction)) return format_min_operation(&r_instruction);
    if (is_max_instruction(&r_instruction)) return format_max_operation(&r_instruction);
    if (is_rem_instruction(&r_instruction)) return format_rem_operation(&r_instruction);
    if (is_mod_instruction(&r_instruction)) return format_mod_operation(&r_instruction);
    if (is_fadd_instruction(&r_instruction)) return format_fadd_operation(&r_instruction);
    if (is_fsub_instruction(&r_instruction)) return format_fsub_operation(&r_instruction);
    if (is_fmul_instruction(&r_instruction)) return format_fmul_operation(&r_instruction);
    if (is_fdiv_instruction(&r_instruction)) return format_fdiv_operation(&r_instruction);
    return NULL;
}

char* format_shl_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_shl_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SHL <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_shr_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_shr_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SHR <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_and_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_and_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "AND <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_or_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_or_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "OR <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

// char* format_not_operation(R_INSTRUCTION* decoded_instruction) {
//     if (!is_not_instruction(decoded_instruction)) return NULL;
//     sprintf(format_memory, "NOT <rd=%s> <rs1=%s> <rs2=%s>",
//         register_to_name(decoded_instruction->rd),
//         register_to_name(decoded_instruction->rs1),
//         register_to_name(decoded_instruction->rs2)
//     );
//     return format_memory;
// }

char* format_xor_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_xor_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "XOR <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_add_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_add_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "ADD <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_sub_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sub_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SUB <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_mul_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_mul_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MUL <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_div_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_div_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "DIV <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
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

char* format_sle_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sle_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SLE <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_seq_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_seq_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SEQ <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_sne_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_sne_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "SNE <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_min_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_min_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MIN <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_max_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_max_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MAX <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_rem_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_rem_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "REM <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_mod_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_mod_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "MOD <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_fadd_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_fadd_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "FADD <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_fsub_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_fsub_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "FSUB <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_fmul_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_fmul_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "FMUL <rd=%s> <rs1=%s> <rs2=%s>",
        register_to_name(decoded_instruction->rd),
        register_to_name(decoded_instruction->rs1),
        register_to_name(decoded_instruction->rs2)
    );
    return format_memory;
}

char* format_fdiv_operation(R_INSTRUCTION* decoded_instruction) {
    if (!is_fdiv_instruction(decoded_instruction)) return NULL;
    sprintf(format_memory, "FDIV <rd=%s> <rs1=%s> <rs2=%s>",
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
