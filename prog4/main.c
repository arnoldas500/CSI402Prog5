//
//  main.c
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "structs.h"


symbolNode *symTable;
symbolNode *hashtab[HASHSIZE];
int numSym = 0;


unsigned int instructions[MAX_INST_LEN];


unsigned int locationCounter = 0; 
//line number w/ blanks and comments
int shortLineCount = 0;

//actual line number with commnets and blanks
int lineNum = 0;

int numErrors = 0;
error **errors;



//first pass loops thru the file to build the symbol table
//then rewinds and loops again thru the file to assemble the actual instructions
//with the built symbol table
//printout makes output files
int main(int argc, char *argv[]) {
  char line[MAX_LINE_LEN + 1], *strtLine, *firstToken;
  int ts = 0, ds =0;
  FILE *inFile;
  char *outFile;
    
    
    
  if (argc != REQ_ARC) {
    fprintf(stderr, "Usage: p4 inFile\n");
    exit(1);
  }

  // Open .asm file
  if ((inFile = fopen(argv[inFile_ARG], "r")) == NULL) {
    fprintf(stderr, "Unable to open %s for reading.\n", argv[inFile_ARG]);
    exit(1);
  }


 // symTable = (symbolNode **) malloc(sizeof(symbolNode *) * MIN_SYM_LEN);
  errors  = (error **) malloc(sizeof(error *) * MIN_ERR_LEN);


  outFile = strdup(basename(argv[inFile_ARG]));

  if (strrchr(outFile, '.') != NULL) {
    outFile[strlen(outFile) - strlen(strrchr(outFile, '.'))] = '\0';
  }

 //////////////// First pass////////////////////////
  while (fgets(line, MAX_LINE_LEN, inFile) != NULL) {
    lineNum++;

   
    if (!validLine(line))
      continue;

 
      
      
    preprocLine(line);

    strtLine = strdup(line);

    firstToken = strtok(line, " \t\n");

    if (firstToken[0] == '.') {
      if (strcmp(firstToken, DATA_SEGMENT) == 0) {
        ds = 1;
        ts = 0;
      } else if (strcmp(firstToken, TEXT_SEGMENT) == 0) {
        ts = 1;
        ds = 0;
      }

      continue;
    }

    locationCounter += addSymbol(strtLine, locationCounter, ds, ts, 0);
      int i =0;
      for(i=0; i < HASHSIZE; i++)
      for(symTable=hashtab[i]; symTable != NULL; symTable = symTable->next)
          
          
          //testing symtable to be populated 
        //  printf("symbol name before if is %s\n", symTable->symName);
      
    shortLineCount++;
  }
    
///////////////starting second pass//////////////////////
  rewind(inFile);
  locationCounter = 0;
  shortLineCount = 0;
  lineNum = 0;

  while (fgets(line, MAX_LINE_LEN, inFile) != NULL) {
    lineNum++;
    if (!validLine(line))
      continue;

    preprocLine(line);

    strtLine = strdup(line);

    firstToken = strtok(line, " \t\n");

    if (firstToken[0] == '.') {
      if (strcmp(firstToken, DATA_SEGMENT) == 0) {
        ds = 1;
        ts = 0;
      } else if (strcmp(firstToken, TEXT_SEGMENT) == 0) {
        ts = 1;
        ds = 0;
      }

      continue;
    }

    locationCounter += addSymbol(strtLine, locationCounter, ds, ts, 1);

    strtLine = removeLabel(strtLine);

    if (ds)
      parseDataInstruct(strtLine);
    else if (ts)
      parseTxtInstruct(strtLine);

    shortLineCount++;
  }

  // start outputing
  printOut(inFile, outFile, locationCounter);

  fclose(inFile);

  return 0;
}
