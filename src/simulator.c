#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "core.h"
#include "simulator.h"
#include "instructions.h"

void simulator_init(simulator* s, uint32_t mem_bytes) {
    memset(s, 0, sizeof(*s));
    s->memory = malloc(mem_bytes);
    s->mem_bytes = mem_bytes;
}

void simulator_destroy(simulator* s) {
    free(s->memory);
}

#define out_of_bounds_check(s, addr, data_type) (addr > (((int64_t) s->mem_bytes) - sizeof(data_type)))

void display_memory(simulator* s, uint32_t start_addr, uint32_t length) {
    // Check if address is out of bounds
    if (out_of_bounds_check(s, start_addr, uint32_t)) {
        WARN("Out of bounds memory display: %08X", start_addr);
        return;
    }

    // Ensure the length is in bounds
    uint32_t actual_len = length;
    if (start_addr + length > s->mem_bytes)
        actual_len = start_addr - s->mem_bytes;

    // Pretty table formatting
    const char* line = "|---------------------|";
    printf("%s\n", line);
    printf("| %-8s | %-8s |\n", "Address", "Length");
    printf("%s\n", line);

    // Print all values
    uint32_t addr = start_addr;
    while (actual_len-- > 0) {
        printf("| %08X | %08X | \n", addr, read_word(s, addr));
        addr += 4;
    }

    printf("%s\n", line);
}

int read_file_to_memory(simulator* s, FILE *f) {
    // Parse the file
    int line_no = 0;
    char line[255];
    while (fgets(line, sizeof(line), f) != NULL) {

        // Split the string into 
        char* addr_ptr = line;
        char* value_ptr;
        if ((value_ptr = strchr(addr_ptr, ':')) != NULL) {
            value_ptr[0] = 0;
            value_ptr++;
        } else
            FAIL("Invalid line: %s", line);

        // Parse address
        uint32_t addr;
        if (sscanf(addr_ptr, "%X", &addr) != 1)
            FAIL("Invalid line: %s", line);

        // Parse value
        uint32_t value;
        if (sscanf(value_ptr, "%X", &value) != 1)
            FAIL("Invalid line: %s", line);

        // Write the word into memory
        write_word(s, addr, value);

        line_no++;
    }
    return line_no;
}

// Disable pointer math warnings only for mem access functions
#pragma GCC diagnostic ignored "-Wpointer-arith"

// Generic write memory function
// Use write_word, write_hword, write_byte instead
#define write_memory(s, addr, data, data_type) {\
    if (out_of_bounds_check(s, addr, data_type)) {\
        WARN("Out of bounds memory write access: %08X", addr);\
        return;\
    }\
    if (addr % sizeof(data_type) != 0) {\
        WARN("Unaligned memory write access: %08X", addr);\
    }\
    *((data_type*) (s->memory + addr)) = data;\
}

void write_word(simulator* s, uint32_t addr, uint32_t data) write_memory(s, addr, data, uint32_t)
void write_hword(simulator* s, uint32_t addr, uint16_t data) write_memory(s, addr, data, uint16_t)
void write_byte(simulator* s, uint32_t addr, uint8_t data) write_memory(s, addr, data, uint8_t)

// Generic read memory function
// Use read_word, read_hword, read_byte instead
#define read_memory(s, addr, data_type) {\
    if (out_of_bounds_check(s, addr, data_type)) {\
        WARN("Out of bounds memory read access: %08X", addr);\
        return (data_type) 0;\
    }\
    if (addr % sizeof(data_type) != 0)\
        WARN("Unaligned memory read access: %08X", addr);\
    return *((data_type*) (s->memory + addr));\
}
uint32_t read_word(simulator* s, uint32_t addr) read_memory(s, addr, uint32_t)
uint16_t read_hword(simulator* s, uint32_t addr) read_memory(s, addr, uint16_t)
uint8_t read_byte(simulator* s, uint32_t addr) read_memory(s, addr, uint8_t)
int32_t read_sword(simulator* s, uint32_t addr) read_memory(s, addr, int32_t)
int16_t read_shword(simulator* s, uint32_t addr) read_memory(s, addr, int16_t)
int8_t read_sbyte(simulator* s, uint32_t addr) read_memory(s, addr, int8_t)

// Enable warnings for any other pointer math
#pragma GCC diagnostic warning "-Wpointer-arith"

uint32_t read_register(simulator* s, REGISTER reg) {
    if (reg == REG_ZERO)
        return 0;
    int reg_reduced = reg - 1;      // REG_ZERO is not real
    if (reg_reduced > length(s->reg))
        FAIL("Invalid register read: %d", reg);
    return s->reg[reg_reduced];
}
int32_t read_register_signed(simulator* s, REGISTER reg) {
    uint32_t value = read_register(s, reg);
    return *(int32_t*) (&value);
}
void write_register(simulator* s, REGISTER reg, uint32_t data) {
    if (reg == REG_ZERO)
        return;
    int reg_reduced = reg - 1;      // REG_ZERO is not real
    if (reg_reduced > length(s->reg))
        FAIL("Invalid register write: %d", reg);
    s->reg[reg_reduced] = data;
}
void write_register_signed(simulator* s, REGISTER reg, int32_t data) {
    write_register(s, reg, *(uint32_t*) (&data));
}

// Make GCC refuse to compile if we use the wrong instruction type
#pragma GCC diagnostic error "-Wincompatible-pointer-types"
bool execute_simulation_step(simulator* s) {
    uint32_t pc = s->pc;
    s->pc += 4;
    
    // No need to check OOB, read_word returns 0 on invalid memory
    uint32_t encoded_instruction = read_word(s, pc);
    if (encoded_instruction == 0) {
        INFO("Execution halted at PC: %08X", pc);
        return false;
    }

    R_INSTRUCTION r_instruction = as_r_instruction(encoded_instruction);
    I_INSTRUCTION i_instruction = as_i_instruction(encoded_instruction);
    S_INSTRUCTION s_instruction = as_s_instruction(encoded_instruction);
    U_INSTRUCTION u_instruction = as_u_instruction(encoded_instruction);
    B_INSTRUCTION b_instruction = as_b_instruction(encoded_instruction);
    J_INSTRUCTION j_instruction = as_j_instruction(encoded_instruction);
    if (is_add_instruction(&r_instruction)) {
        INFO("Instruction: ADD %d %d %d", r_instruction.rd, r_instruction.rs1, r_instruction.rs2);
        write_register(s, r_instruction.rd, 
            (read_register(s, r_instruction.rs1) + r_instruction.rs2)
        );  
        return true;
    }
    if (is_sub_instruction(&r_instruction)) {
        INFO("Instruction: SUB %d %d %d", r_instruction.rd, r_instruction.rs1, r_instruction.rs2);
        write_register(s, r_instruction.rd, 
            (read_register(s, r_instruction.rs1)^ r_instruction.rs2)
        );  
        return true;
    }
    if (is_sll_instruction(&r_instruction)) {
        WARN("Unimplemented operation: SLL");
        return true;
    }
    if (is_slt_instruction(&r_instruction)) {
        WARN("Unimplemented operation: SLT");
        return true;
    }
    if (is_sltu_instruction(&r_instruction)) {
        WARN("Unimplemented operation: SLTU");
        return true;
    }
    if (is_xor_instruction(&r_instruction)) {
        INFO("Instruction: XOR %d %d %d", r_instruction.rd, r_instruction.rs1, r_instruction.rs2);
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1)^ r_instruction.rs2
        );
        return true;
    }
    if (is_srl_instruction(&r_instruction)) {
        WARN("Unimplemented operation: SRL");
        return true;
    }
    if (is_sra_instruction(&r_instruction)) {
        WARN("Unimplemented operation: SRA");
        return true;
    }
    if (is_or_instruction(&r_instruction)) {
        INFO("Instruction: OR %d %d %d", r_instruction.rd, r_instruction.rs1, r_instruction.rs2);
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1) | r_instruction.rs2
        );
        return true;
    }
    if (is_and_instruction(&r_instruction)) {
        INFO("Instruction: AND %d %d %d", r_instruction.rd, r_instruction.rs1, r_instruction.rs2);
        write_register(s, r_instruction.rd, 
            read_register(s, r_instruction.rs1) & r_instruction.rs2
        );
        return true;
    }
    if (is_addi_instruction(&i_instruction)) {
        INFO("Instruction: ADDI %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd,
            (read_register(s, i_instruction.rs1) + i_instruction.imm_s)
        );
        return true;
    }
    if (is_slti_instruction(&i_instruction)) {
        INFO("Instruction: SLTI %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        if(read_register_signed(s, i_instruction.rs1) < read_register_signed(s, i_instruction.imm_s)) {
            write_register(s, i_instruction.rd, 1);
        }        
        else {
            write_register(s, i_instruction.rd, 0);
        }
        return true;
    }
    if (is_sltiu_instruction(&i_instruction)) {
        INFO("Instruction: SLTIU %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        if(read_register(s, i_instruction.rs1) < i_instruction.imm_u) { 
            write_register(s, i_instruction.rd, 1);                                            
        }        
        else {
            write_register(s, i_instruction.rd, 0);
        }
        return true;
    }
    if (is_xori_instruction(&i_instruction)) {
        INFO("Instruction: XORI %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd, 
            read_register(s, i_instruction.rs1)^ ((int32_t)i_instruction.imm_s)
        );
        return true;
    }
    if (is_ori_instruction(&i_instruction)) {
        INFO("Instruction: ORI %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd, 
            read_register(s, i_instruction.rs1)|((int32_t)i_instruction.imm_s)
        );
        return true;
    }
    if (is_andi_instruction(&i_instruction)) {
        INFO("Instruction: ANDI %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd, 
            read_register(s, i_instruction.rs1)&((int32_t)i_instruction.imm_s)
        );
        return true;
    }
    if (is_slli_instruction(&i_instruction)) {
        WARN("Unimplemented operation: SLLI");
        return true;
    }
    if (is_srli_instruction(&i_instruction)) {
        WARN("Unimplemented operation: SRLI");
        return true;
    }
    if (is_srai_instruction(&i_instruction)) {
        WARN("Unimplemented operation: SRAI");
        return true;
    }
    if (is_beq_instruction(&b_instruction)) {
        INFO("Instruction: BEQ %d %d %d", b_instruction.rs1, b_instruction.rs2, b_instruction.imm_s);
        if(read_register(s, b_instruction.rs1) == read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bne_instruction(&b_instruction)) {
        INFO("Instruction: BNE %d %d %d", b_instruction.rs1, b_instruction.rs2, b_instruction.imm_s);
        if(read_register(s, b_instruction.rs1) != read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_blt_instruction(&b_instruction)) {
        INFO("Instruction: BLT %d %d %d", b_instruction.rs1, b_instruction.rs2, b_instruction.imm_s);
        if(read_register_signed(s, b_instruction.rs1) < read_register_signed(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bge_instruction(&b_instruction)) {
        INFO("Instruction: BGE %d %d %d", b_instruction.rs1, b_instruction.rs2, b_instruction.imm_s);
        if(read_register_signed(s, b_instruction.rs1) >= read_register_signed(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bltu_instruction(&b_instruction)) {
        INFO("Instruction: BLTU %d %d %d", b_instruction.rs1, b_instruction.rs2, b_instruction.imm_s);
        if(read_register(s, b_instruction.rs1) < read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_bgeu_instruction(&b_instruction)) {
        INFO("Instruction: BGEU %d %d %d", b_instruction.rs1, b_instruction.rs2, b_instruction.imm_s);
        if(read_register(s, b_instruction.rs1) >= read_register(s, b_instruction.rs2)){
            s->pc = pc + (b_instruction.imm_s);
        }
        return true;
    }
    if (is_lui_instruction(&u_instruction)) {
        WARN("Unimplemented operation: LUI");
        return true;
    }
    if (is_auipc_instruction(&u_instruction)) {
        WARN("Unimplemented operation: AUIPC");
        return true;
    }
    if (is_jal_instruction(&j_instruction)) {
        WARN("Unimplemented operation: JAL");
        return true;
    }
    if (is_jalr_instruction(&i_instruction)) {
        WARN("Unimplemented operation: JALR");
        return true;
    }
    if (is_lb_instruction(&i_instruction)) {
        INFO("Instruction: LB %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd,
            read_sbyte(s, read_register(s, i_instruction.rs1) + i_instruction.imm_s)
        );
        return true;
    }
    if (is_lh_instruction(&i_instruction)) {
        INFO("Instruction: LH %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd,
            read_shword(s, read_register(s, i_instruction.rs1) + i_instruction.imm_s)
        );
        return true;
    }
    if (is_lw_instruction(&i_instruction)) {
        INFO("Instruction: LW %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_s);
        write_register(s, i_instruction.rd,
            read_sword(s,(read_register(s, i_instruction.rs1) + i_instruction.imm_s))
        );
        return true;
    }
    if (is_lbu_instruction(&i_instruction)) {
        INFO("Instruction: LBU %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_u);
        write_register(s, i_instruction.rd,
            read_byte(s, read_register(s, i_instruction.rs1) + i_instruction.imm_u)
        );
        return true;
    }
    if (is_lhu_instruction(&i_instruction)) {
        INFO("Instruction: LHU %d %d %d", i_instruction.rd, i_instruction.rs1, i_instruction.imm_u);
        write_register(s, i_instruction.rd,
            read_hword(s, read_register(s, i_instruction.rs1) + i_instruction.imm_u)
        );
        return true;
    }
    if (is_sb_instruction(&s_instruction)) {
        WARN("Unimplemented operation: SB");
        return true;
    }
    if (is_sh_instruction(&s_instruction)) {
        WARN("Unimplemented operation: SH");
        return true;
    }
    if (is_sw_instruction(&s_instruction)) {
        WARN("Unimplemented operation: SW");
        return true;
    }
    if (is_sbu_instruction(&s_instruction)) {
        WARN("Unimplemented operation: SBU");
        return true;
    }
    if (is_shu_instruction(&s_instruction)) {
        WARN("Unimplemented operation: SHU");
        return true;
    }

    WARN("Unknown operation: %08X", encoded_instruction);
    return true;
}
