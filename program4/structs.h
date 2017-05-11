//
//  structs.h
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <ctype.h>



////////////////////////////////
//typedefs
////////////////////////////////

#define HASHSIZE 127
#define inFile_ARG 1
#define REQ_ARC 2

#define MAX_SYMBOL_LEN 65535
#define MAX_INST_LEN 65535
#define MIN_ERR_LEN 5
#define MIN_SYM_LEN 5

#define FILE_EXT_LEN 4

#define TWO_ARGS 2
#define THREE_ARGS 3

#define MAX_R_FORMAT_OPCODE 17
#define MAX_I_FORMAT_OPCODE 25

#define RE_MALLOC 2

#define MAX_LINE_LEN 80
#define DATA_SEGMENT ".data"
#define TEXT_SEGMENT ".text"
#define WORD_DIRECTIVE ".word"
#define RESW_DIRECTIVE ".resw"

#define NUM_OPCODES 36
#define R_INST__OPCODE_SHIFT 25
#define R_INST__RS1_SHIFT 20
#define R_INST__RS2_SHIFT 15
#define R_INST__RT_SHIFT 10
#define R_INST__SA_SHIFT 5

#define J_INST__OPCODE_SHIFT 25
#define J_INST__RS_SHIFT 20
#define J_INST__RT_SHIFT 15

#define I_INST__OPCODE_SHIFT 25
#define I_INST__RS_SHIFT 20
#define I_INST__RT_SHIFT 15




////////////////////////////////
//structs
////////////////////////////////

struct nlist{
    struct nlist *next;
    char *name;
    int value;
};
typedef struct symbolNode {
    char *symName;
    unsigned int locationCounter;
    struct symbolNode * next;
} symbolNode;


typedef struct opcodeNode{
    char instruction[MAX_INST_LEN];
    int opcode;
    struct opcodeNode * next;
}opcodeNode;

typedef struct error {
    int lineNO;
    char type;
    char *message;
} error;



////////////////////////////////
//function prototypes
////////////////////////////////


int  hash (char *s,  int T);


void rInstruct(unsigned int opcode, char *args);
void iInstruct(unsigned int opcode, char *args, int numOfArgs);
void jInstruct(unsigned int opcode, char *args, int numOfArgs);


void addErr(int lineNO, char type, char *message);

void * checkedMalloc(size_t s);
FILE * checkedOpen(const char * name, char * mode);
void checkpoint();


void Rinstruction(unsigned int locationCounter, unsigned int opcode, int rs1, int rs2, int rt, int sa);
void Jinstruction(unsigned int locationCounter, unsigned int opcode, int rs, int rt, int address);
void Iinstruction(unsigned int locationCounter, unsigned int opcode, int rs, int rt, int imOperand);
int opMnemonic(char *mnemonic);
char opcodeInstruct(unsigned int opcode);

void printOut(FILE *asmFile, char *outFile, int locationCounter);


int numOfArgs(char *args);
int parseDataInstruct(char *instruction);
int parseTxtInstruct(char *instruction);
int argSym(char *arg);
int argNum(char *arg);

void preprocLine(char *line);
char *removeLabel(char *line);
int empty(const char *s);
int validLine(char *line);

symbolNode *hasSymb(char *symName);
int addSymbol(char *line, unsigned int locationCounter, unsigned int ds, unsigned int ts, short secondPass);




