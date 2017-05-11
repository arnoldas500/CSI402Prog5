//
//  instruct.c
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//


#include "structs.h"

extern unsigned int instructions[];


//makes unsinged int instruction for r type
void Rinstruction(unsigned int locationCounter, unsigned int opcode, int rs1, int rs2, int rt, int sa) {
  instructions[locationCounter] = opcode;
  instructions[locationCounter] <<= R_INST__OPCODE_SHIFT;

  instructions[locationCounter] |= (rs1 << R_INST__RS1_SHIFT);
  instructions[locationCounter] |= (rs2 << R_INST__RS2_SHIFT);
  instructions[locationCounter] |= (rt  << R_INST__RT_SHIFT);
  instructions[locationCounter] |= (sa  << R_INST__SA_SHIFT);

  instructions[locationCounter] <<= 1;
}

//makes unsinged int instruction for j type

void Jinstruction(unsigned int locationCounter, unsigned int opcode, int rs, int rt, int address) {
  instructions[locationCounter] = opcode;
  instructions[locationCounter] <<= J_INST__OPCODE_SHIFT;

  instructions[locationCounter] |= (rs << J_INST__RS_SHIFT);
  instructions[locationCounter] |= (rt << J_INST__RT_SHIFT);

  instructions[locationCounter] <<= 1;

  instructions[locationCounter] |= address;
}

//makes unsinged int instruction for i type

void Iinstruction(unsigned int locationCounter, unsigned int opcode, int rs, int rt, int imOperand) {
  instructions[locationCounter] = opcode;
  instructions[locationCounter] <<= I_INST__OPCODE_SHIFT;

  instructions[locationCounter] |= (rs << I_INST__RS_SHIFT);
  instructions[locationCounter] |= (rt << I_INST__RT_SHIFT);

  instructions[locationCounter] <<= 1;

  instructions[locationCounter] |= imOperand;
}



//opcode table

static char *mot[NUM_OPCODES] = { "hlt",
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "move",
    "and",
    "or",
    "xor",
    "com",
    "sll",
    "srl",
    "sra",
    "jr",
    "rdr",
    "prr",
    "prh",
    "li",
    "addi",
    "subi",
    "muli",
    "divi",
    "modi",
    "lwb",
    "swb",
    "lwa",
    "swa",
    "j",
    "jal",
    "jeq",
    "jne",
    "jlt",
    "jle",
    "jgt",
    "jge" };

int opMnemonic(char *mnemonic) {
    int i;
    
    for (i=0;i<NUM_OPCODES;i++)
        if (strcmp(mnemonic, mot[i]) == 0)
            return i;
    
    return -1;
}

char opcodeInstruct(unsigned int opcode) {
    return (opcode <= MAX_R_FORMAT_OPCODE ? 'R' : ((opcode <= MAX_I_FORMAT_OPCODE) ? 'I' : 'J'));
}
