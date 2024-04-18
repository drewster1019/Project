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
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

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
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

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

