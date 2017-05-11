//
//  asem.c
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "structs.h"

extern unsigned int instructions[];
extern unsigned int locationCounter;
extern int shortLineCount;


//bitmasking for R instructios
void rInstruct(unsigned int opcode, char *args) {
  int rt = 0, rs1 = 0, rs2 = 0, sa = 0, argVal = 0, i = 0;
  short SaFlag = 0;
  char *arg;
  symbolNode *tmp;

  // These 3 commands use the shift amount value
  if (opcode == opMnemonic("sll") ||
      opcode == opMnemonic("srl") ||
      opcode == opMnemonic("sra"))
    SaFlag = 1;

  arg = strtok(args, ",");

  while (arg != NULL) {


    // Add an error if the symbol is undefined,
    // or just get the argNum (immediate or register)
    if (argSym(arg) && (tmp = hasSymb(arg))) {
      argVal = tmp->locationCounter;
    } else if (argSym(arg)) {
      addErr(shortLineCount, 'U', arg);
    } else {
      argVal = argNum(arg);
    }

    if (i == 0)
      rt = argVal;
    else if (i == 1)
      rs1 = argVal;
    else if (i == TWO_ARGS && SaFlag == 1)
      sa = argVal;
    else if (i == TWO_ARGS)
      rs2 = argVal;

    arg = strtok(NULL, ",");
    i++;
  }

  Rinstruction(shortLineCount, opcode, rs1, rs2, rt, sa);
}

//bitmasking for I instructios
void iInstruct(unsigned int opcode, char *args, int numOfArgs) {
  int rt = 0, rs = 0, imOperand = 0,  i = 0;
  int argVal = 0;
  char *arg, *tmparg = NULL;
  symbolNode *tmp;

  arg = strtok(args, ",");

  if (numOfArgs == THREE_ARGS) {
    while (arg != NULL) {
      if (argSym(arg) && (tmp = hasSymb(arg))) {
        argVal = tmp->locationCounter;
      } else if (argSym(arg)) {
        addErr(shortLineCount, 'U', arg);
      } else {
        argVal = argNum(arg);
      }

      if (i == 0)
        rt = (int) argVal;
      else if (i == 1)
        rs = (int) argVal;
      else if (i == TWO_ARGS)
        imOperand = (int) argVal;

      arg = strtok(NULL, ",");
      i++;
    }
  } else if (numOfArgs == TWO_ARGS) {
    rt = (int) (argSym(arg) && (tmp = hasSymb(arg))) ? tmp->locationCounter : argNum(arg);
    arg = strtok(NULL, ",");

    if (strchr(arg, '(') == NULL) {
      if (hasSymb(arg) || arg[0] == '$') {
        rs = (int) (argSym(arg) && (tmp = hasSymb(arg))) ? tmp->locationCounter : argNum(arg);
      } else {
        if (argSym(arg) && !hasSymb(arg)) {
          addErr(shortLineCount, 'U', arg);
        }

        imOperand = (int) (argSym(arg) && (tmp = hasSymb(arg))) ? tmp->locationCounter : argNum(arg);
      }
    } else {
  
        
      ///
      tmparg = strtok(arg, "()");
      imOperand = atoi(tmparg);

      tmparg = strtok(NULL, "()");
      //
        //for dollar sin
      rs = atoi(++tmparg);
    }
  }

  Iinstruction(shortLineCount, opcode, rs, rt, imOperand);
}

//bitmasking for J instructios
void jInstruct(unsigned int opcode, char *args, int numOfArgs) {
  int rt = 0, rs = 0, argVal = 0, i = 0, address = 0;
  char *arg;
  symbolNode *tmpsym;

  arg = strtok(args, ",");

  while (arg != NULL) {
    if (argSym(arg) && (tmpsym = hasSymb(arg))) {
      argVal = tmpsym->locationCounter;
    } else if (argSym(arg)) {
      addErr(shortLineCount, 'U', arg);
    } else {
      argVal = argNum(arg);
    }

    if (numOfArgs == THREE_ARGS) {
      if (i == 0)
        rt = (int) argVal;
      else if (i == 1)
        rs = (int) argVal;
      else if (i == TWO_ARGS)
        address = (int) argVal;
    } else if (numOfArgs == TWO_ARGS) {
      if (i == 0)
        rt = (int) argVal;
      else if (i == 1)
        address = (int) argVal;
    } else if (numOfArgs == 1) {
      address = (int) argVal;
    }

    arg = strtok(NULL, ",");
    i++;
  }

  Jinstruction(shortLineCount, opcode, rs, rt, address);
}
