//
//  parsing.c
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "structs.h"

extern unsigned int instructions[];
extern unsigned int locationCounter;

extern int shortLineCount;
extern int lineNum;

// opcodeNode *instructions;

//gets number of argumets in a string
int numOfArgs(char *args) {
  int i = 0;
  char *tmp;

  if (!args)
    return 0;

  tmp = strdup(args);
  tmp = strtok(tmp, ",");

  while (strtok(NULL, ",") != NULL)
    i++;

  return i+1;
}



//parses data instructions
int parseDataInstruct(char *instruction) {
  char *directive, *args, *arg;
  int i = 0, value = 0, words = 0;
  directive = strtok(instruction, " \t");
  args = strtok(NULL, " \t");

  if (strcmp(directive, WORD_DIRECTIVE) == 0) {
    value = atoi(strtok(args, ":"));
    arg = strtok(NULL, ":");
    words = atoi(arg);
    for (i=words;i>0;i--) {
      instructions[locationCounter-i] = value;
    }
  }


  return 1;
}



//parses text instructions
//checks if illegal opcode
//checks what type of instruction passed and sends it to assemble function
int parseTxtInstruct(char *instruction) {
  char *opcode, *args;
  int opValue, numArgs;

  instruction = strtok(instruction, " \t\n");

  opcode = strdup(instruction);

  opValue = opMnemonic(opcode);

  if (opValue == -1) {
    addErr(lineNum, 'I', "Illegal opcode.");
  }

  args = strtok(NULL, " \t\n");

  numArgs = numOfArgs(args);

  switch (opcodeInstruct((unsigned int) opValue)) {
    case 'R':
      rInstruct((unsigned int) opValue, args);
      break;

    case 'I':
      iInstruct((unsigned int) opValue, args, numArgs);
      break;

    case 'J':
      jInstruct((unsigned int) opValue, args, numArgs);
      break;
  }

  return 1;
}


 // checking if an argument is a symbol
 //needs to start with a letter and checks
 //to make sure it has the right format too

 
int argSym(char *arg) {
  char *tmp = strdup(arg);
  int i = 0;
  if (!isalpha(tmp[i]))
    return 0;

  for (i=0;i<strlen(tmp);i++)
    if (!isalnum(tmp[i]) && tmp[i] != '_')
      return 0;

  return 1;
}

//gets argument value and
//checks if register or immediate
int argNum(char *arg) {
  int i, isNum=1;

  // if its just a register
  if (arg[0] == '$') {
    return atoi(++arg);
  }

  for (i=0;i<strlen(arg);i++) {
    //if its negative
    if (i == 0 && arg[0] == '-')
      continue;

    if (!isdigit(arg[i])) {
      isNum = 0;
      break;
    }
  }

  // if its an immediate value
  if (isNum)
    return atoi(arg);

  return 0;
}
