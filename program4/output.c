//
//  output.c
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "structs.h"

// symbolNode **symTable;
extern symbolNode *hashtab[HASHSIZE];
extern int numSym;

extern unsigned int instructions[];

extern int numErrors;
extern error **errors;



//prints output to .sym, .err or .obj file
void printOut(FILE *asmFile, char *outFile, int locationCounter) {
    symbolNode * symTable;
  int i = 0, j = 1;
  char line[MAX_LINE_LEN + 1];
  char *filename = malloc(sizeof(char) * (strlen(outFile) + FILE_EXT_LEN  + 1));
  FILE *symfile, *objfile, *errfile;

  //starting  Error file
  if (numErrors) {
    rewind(asmFile);

    sprintf(filename, "%s.err", outFile);
    errfile = fopen(filename, "w");

    while (fgets(line, MAX_LINE_LEN, asmFile) != NULL) {
      fprintf(errfile, "%2d   %s", j, line);
      j++;
    }

    fprintf(errfile, "\nErrors detected:\n\n");

    for (i=0;i<numErrors;i++) {
      if (errors[i]->type == 'I')
        fprintf(errfile, "  line %d:  %s\n", errors[i]->lineNO, errors[i]->message);
    }

    fprintf(errfile, "\nMultiply defined symbol(s):\n\n");

    for (i=0;i<numErrors;i++) {
      if (errors[i]->type == 'M')
        fprintf(errfile, "  %s\n", errors[i]->message);
    }

    fprintf(errfile, "\nUndefined symbol(s):\n\n");

    for (i=0;i<numErrors;i++)
      if (errors[i]->type == 'U')
        fprintf(errfile, "  %s\n", errors[i]->message);


    fclose(errfile);

    // Close error file and return, skipping generation of .obj and .sym files
    return;
  }

  // checking what filenames needed  for .obj and .sym files
  sprintf(filename, "%s.obj", outFile);
  objfile = fopen(filename, "w");

  sprintf(filename, "%s.sym", outFile);
  symfile = fopen(filename, "w");

  // Print objects in hex
  for (i=0;i<locationCounter;i++) {
    fprintf(objfile, "%4X\t%X\n", i, instructions[i]);
  }

    
    
    int k =0;
    for(k=0; k < HASHSIZE; k++)
        for(symTable=hashtab[k]; symTable != NULL; symTable = symTable->next){
            printf("symbol name in output file is %s %d\n", symTable->symName, symTable->locationCounter);
            fprintf(symfile, "     %-8s%5d\n", symTable->symName, symTable->locationCounter);
        }

  fclose(symfile);
  fclose(objfile);
}


//////////////////////////////////////////////
//error checking
//////////////////////////////////////////////


extern int numErrors;
extern error **errors;


//adds error to structure
void addErr(int lineNO, char type, char *message) {
    // increase size of array if necessary
    if (numErrors >= MIN_ERR_LEN) {
        errors = realloc(errors, (numErrors * RE_MALLOC) * sizeof(error *));
    }
    
    // Setup error
    errors[numErrors] = malloc(sizeof(error));
    errors[numErrors]->lineNO = lineNO;
    errors[numErrors]->type = type;
    errors[numErrors]->message = message;
    
    numErrors++;
}




