// Team-21
// Andrew Patrascoiu
// Elianis Roman
// Keyana Brown

#include "spimcore.h"

/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    switch(ALUControl)
    {
        case 0: // Z = A + B
            *ALUresult = A + B;
            break;
        case 1: // Z = A - B
            *ALUresult = A - B;
            break;
        case 2: // if A < B, Z = 1; otherwise, Z = 0 (A and B are unsigned integers)
            *ALUresult = A < B ? 1 : 0;
            break;
        case 3: // The table shows the same operation not sure if typo?
            *ALUresult = A < B ? 1 : 0;
            break;
        case 4: // Z = A AND B
            *ALUresult = A & B;
            break;
        case 5: // Z = A OR B
            *ALUresult = A | B;
            break;
        case 6: // Z = Shift B left by 16 bits
            *ALUresult = B << 16;
            break;
        case 7: // Z = NOT A
            *ALUresult = ~A;
            break;
        default:
            printf("Invalid ALU Control Code\n");
            exit(1); // Exit the program if ALUControl is out of range
    }

    // Set Zero to 1 if the result is 0; otherwise, set to 0.
    *Zero = (*ALUresult == 0) ? 1 : 0;
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction)
{
    // Check if PC is within the bounds
    if ((PC >> 2) >= MEMSIZE) {
        // PC is out of bounds
        return 1;
    }

    // Check if PC is word-aligned
    if (PC % 4 != 0) {
        // PC is not word-aligned
        return 1;
    }

    // Fetch the instruction from memory
    *instruction = Mem[PC >> 2];

    return 0;
}

/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1, unsigned *r2, unsigned *r3, unsigned *shamt, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // Opcode is the first 6 bits of the instruction
    *op = (instruction >> 26) & 0x3F;
    
    // source register 1 is the next 5 bits
    *r1 = (instruction >> 21) & 0x1F;
    
    // source register 2 is the next 5 bits
    *r2 = (instruction >> 16) & 0x1F;
    
    // destination register is the next 5 bits
    *r3 = (instruction >> 11) & 0x1F;
    
    // shift amount is the next 5 bits
    *shamt = (instruction >> 6) & 0x1F;
    
    // funct is the last 6 bits
    *funct = instruction & 0x3F;
    
    // offset is the last 16 bits
    *offset = instruction & 0xFFFF;
    
    // jsec is the last 26 bits
    *jsec = instruction & 0x3FFFFFF;
}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op, struct_controls *controls) {
  
    // Set all controls to 0 (deasserted) by default
    controls->RegDst = 0;
    controls->Jump = 0;
    controls->Branch = 0;
    controls->MemRead = 0;
    controls->MemtoReg = 0;
    controls->ALUOp = 0;
    controls->MemWrite = 0;
    controls->ALUSrc = 0;
    controls->RegWrite = 0;

    switch (op) {
        // R-type instructions
        case 0x00:
            controls->RegDst = 1;
            controls->ALUOp = 7; 
            controls->RegWrite = 1;
            break;

        // Jump
        case 0x02:
            controls->Jump = 1;
            break;

        // Branch on Equal
        case 0x04:
            controls->Branch = 1;
            break;

        // Add Immediate 
        case 0x08:
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // Set Less Than Immediate
        case 0x0A:
            controls->ALUOp = 2; 
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // Set Less Than Immediate Unsigned 
        case 0x0B:
            controls->ALUOp = 3; 
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // Load Upper Immediate 
        case 0x0F:
            controls->ALUOp = 6; 
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // Load Word
        case 0x23:
            controls->MemRead = 1;
            controls->MemtoReg = 1;
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // Store Word
        case 0x2B:
            controls->MemWrite = 1;
            controls->ALUSrc = 1;
            break;
        
        default:
            return 1; 
    }

    return 0; 
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem) {

    if (MemWrite == 1) {
        if ((ALUresult % 4) == 0)
            Mem[ALUresult >> 2] = data2;
        else
            return 1;
    }

    if (MemRead == 1) {
        if ((ALUresult % 4) == 0)
            *memdata = Mem[ALUresult >> 2];
        else
            return 1;
    }

    return 0;
}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

