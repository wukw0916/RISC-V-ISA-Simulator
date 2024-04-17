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
    uint8_t rnd;
} R_INSTRUCTION;
R_INSTRUCTION as_r_instruction(uint32_t instruction);

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

#define OP0_FADD = 0b0000;
#define OP1_FADD = 0b111;
#define OP2_FADD = 0b00;
#define RND_FADD = 0b00;
bool is_fadd_instruction(uint32_t instruction, const R_INSTRUCTION* decoded_instruction);

// const uint8_t OPCODE_SUB = 0b0110011;
// const uint8_t FUNC3_SUB = 0b000;
// const uint8_t FUNC7_SUB = 0b0100000;
// bool is_sub_instruction(uint32_t instruction, R_INSTRUCTION* decoded_instruction);

// const uint8_t OPCODE_LW = 0b0000011;
// const uint8_t FUNC3_LW = 0b010;
// bool is_lw_instruction(uint32_t instruction, I_INSTRUCTION* decoded_instruction);

#endif