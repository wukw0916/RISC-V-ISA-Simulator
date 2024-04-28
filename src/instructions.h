// This file has been generated using `tools/opcode_generator`
// DO NOT EDIT BY HAND

#ifndef INSTRUCTIONS_H

#define INSTRUCTIONS_H

#include <stdbool.h>

#include <stdint.h>

#include "simulator.h"

typedef struct {
    // <TotalBits=4>
    uint8_t op0;
    // <TotalBits=7>
    REGISTER rd;
    // <TotalBits=7>
    REGISTER rs1;
    // <TotalBits=7>
    REGISTER rs2;
    // <TotalBits=3>
    uint8_t op1;
    // <TotalBits=2>
    uint8_t op2;
    // <TotalBits=2>
    uint8_t type;
} R_INSTRUCTION;
R_INSTRUCTION as_r_instruction(uint32_t instruction);
// typedef struct {
//     // <TotalBits=4>
//     uint8_t op0;
//     // <TotalBits=7>
//     REGISTER rd;
//     // <TotalBits=7>
//     REGISTER rs1;
//     // <TotalBits=7>
//     REGISTER rs2;
//     // <TotalBits=3>
//     uint8_t op1;
//     // <TotalBits=2>
//     uint8_t op2;
//     // <TotalBits=2>
//     uint8_t rnd;
// } R_RND_INSTRUCTION;
// R_RND_INSTRUCTION as_r_instruction(uint32_t instruction);

// typedef struct {
//     // <TotalBits=7>
//     uint8_t opcode;
//     // <TotalBits=5>
//     uint8_t rd;
//     // <TotalBits=2>
//     uint8_t func3;
//     // <TotalBits=4>
//     uint8_t rs1;
//     // <TotalBits=7>
//     int8_t imm;
// } I_INSTRUCTION;
// I_INSTRUCTION as_i_instruction(uint32_t instruction);

// typedef struct {
//     // <TotalBits=6>
//     uint8_t opcode;
//     // <TotalBits=2>
//     uint8_t func3;
//     // <TotalBits=4>
//     uint8_t rs1;
//     // <TotalBits=4>
//     uint8_t rs2;
//     // <TotalBits=10>
//     uint16_t imm;
// } S_INSTRUCTION;
// S_INSTRUCTION as_s_instruction(uint32_t instruction);

#define OP0_SLL = 0b0000;
#define OP1_SLL = 0b000;
#define OP2_SLL = 0b01;
#define TYPE_SLL = 0b00;
bool is_sll_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_SLR = 0b0000;
#define OP1_SLR = 0b000;
#define OP2_SLR = 0b10;
#define TYPE_SLR = 0b00;
bool is_slr_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_AND = 0b0000;
#define OP1_AND = 0b000;
#define OP2_AND = 0b11;
#define TYPE_AND = 0b00;
bool is_and_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_OR = 0b0000;
#define OP1_OR = 0b000;
#define OP2_OR =  0b11;
#define TYPE_OR = 0b01;
bool is_or_instruction(const R_INSTRUCTION* decoded_instruction);

// #define OP0_NOT = 0b0000;
// #define OP1_NOT = 0b000;
// #define OP2_NOT =  0b11;
// #define TYPE_NOT = 0b10;
// bool is_and_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_XOR = 0b0000;
#define OP1_XOR = 0b000;
#define OP2_XOR =  0b11;
#define TYPE_XOR = 0b11;
bool is_xor_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_ADD = 0b0000;
#define OP1_ADD = 0b010;
#define OP2_ADD =  0b00;
#define TYPE_ADD = 0b00;
bool is_add_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_SUB = 0b0000;
#define OP1_SUB = 0b010;
#define OP2_SUB =  0b01;
#define TYPE_SUB = 0b00;
bool is_sub_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_MUL = 0b0000;
#define OP1_MUL = 0b010;
#define OP2_MUL =  0b10;
#define TYPE_MUL = 0b00;
bool is_mul_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_DIV = 0b0000;
#define OP1_DIV = 0b010;
#define OP2_DIV =  0b11;
#define TYPE_DIV = 0b00;
bool is_div_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_SLT = 0b0000;
#define OP1_SLT = 0b011;
#define OP2_SLT = 0b00;
#define TYPE_SLT = 0b00;
bool is_slt_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_SLE = 0b0000;
#define OP1_SLE = 0b011;
#define OP2_SLE = 0b01;
#define TYPE_SLE = 0b00;
bool is_sle_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_SEQ = 0b0000;
#define OP1_SEQ = 0b011;
#define OP2_SEQ = 0b10;
#define TYPE_SEQ = 0b00;
bool is_seq_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_SNE = 0b0000;
#define OP1_SNE = 0b011;
#define OP2_SNE = 0b11;
#define TYPE_SNE = 0b00;
bool is_sne_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_MIN = 0b0000;
#define OP1_MIN = 0b100;
#define OP2_MIN = 0b00;
#define TYPE_MIN = 0b00;
bool is_min_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_MAX = 0b0000;
#define OP1_MAX = 0b100;
#define OP2_MAX = 0b01;
#define TYPE_MAX = 0b00;
bool is_max_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_REM = 0b0000;
#define OP1_REM = 0b100;
#define OP2_REM = 0b10;
#define TYPE_REM = 0b00;
bool is_rem_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_MOD = 0b0000;
#define OP1_MOD = 0b100;
#define OP2_MOD = 0b11;
#define TYPE_MOD = 0b00;
bool is_mod_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_FADD = 0b0000;
#define OP1_FADD = 0b100;
#define OP2_FADD = 0b00;
#define TYPE_FADD = 0b00;
bool is_fadd_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_FSUB = 0b0000;
#define OP1_FSUB = 0b100;
#define OP2_FSUB = 0b01;
#define TYPE_FSUB = 0b00;
bool is_fsub_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_FMUL = 0b0000;
#define OP1_FMUL = 0b100;
#define OP2_FMUL = 0b10;
#define TYPE_FMUL = 0b00;
bool is_fmul_instruction(const R_INSTRUCTION* decoded_instruction);

#define OP0_FDIV = 0b0000;
#define OP1_FDIV = 0b100;
#define OP2_FDIV = 0b10;
#define TYPE_FDIV = 0b00;
bool is_fdiv_instruction(const R_INSTRUCTION* decoded_instruction);

int count_all_instruction_matches(uint32_t encoded_instruction);

char* format_instruction(uint32_t encoded_instruction);
char* format_shl_operation(R_INSTRUCTION* decoded_instruction);
char* format_shr_operation(R_INSTRUCTION* decoded_instruction);
char* format_and_operation(R_INSTRUCTION* decoded_instruction);
char* format_or_operation(R_INSTRUCTION* decoded_instruction);
char* format_xor_operation(R_INSTRUCTION* decoded_instruction);
char* format_add_operation(R_INSTRUCTION* decoded_instruction);
char* format_sub_operation(R_INSTRUCTION* decoded_instruction);
char* format_mul_operation(R_INSTRUCTION* decoded_instruction);
char* format_div_operation(R_INSTRUCTION* decoded_instruction);
char* format_slt_operation(R_INSTRUCTION* decoded_instruction);
char* format_sle_operation(R_INSTRUCTION* decoded_instruction);
char* format_seq_operation(R_INSTRUCTION* decoded_instruction);
char* format_sne_operation(R_INSTRUCTION* decoded_instruction);
char* format_min_operation(R_INSTRUCTION* decoded_instruction);
char* format_max_operation(R_INSTRUCTION* decoded_instruction);
char* format_rem_operation(R_INSTRUCTION* decoded_instruction);
char* format_mod_operation(R_INSTRUCTION* decoded_instruction);
char* format_fadd_operation(R_INSTRUCTION* decoded_instruction);
char* format_fsub_operation(R_INSTRUCTION* decoded_instruction);
char* format_fmul_operation(R_INSTRUCTION* decoded_instruction);
char* format_fdiv_operation(R_INSTRUCTION* decoded_instruction);

// const uint8_t OPCODE_SUB = 0b0110011;
// const uint8_t FUNC3_SUB = 0b000;
// const uint8_t FUNC7_SUB = 0b0100000;
// bool is_sub_instruction(uint32_t instruction, R_INSTRUCTION* decoded_instruction);

// const uint8_t OPCODE_LW = 0b0000011;
// const uint8_t FUNC3_LW = 0b010;
// bool is_lw_instruction(uint32_t instruction, I_INSTRUCTION* decoded_instruction);

#endif