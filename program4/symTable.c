//
//  symTable.c
//  prog4
//
//  Created by arnoldas kurbanovas on 4/10/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "structs.h"


//extern symbolNode **symTable;
extern int numSym;
//static struct nlist *hashtab[HASHSIZE];
extern int shortLineCount;
//static struct symbolNode *hashtab[HASHSIZE];
extern symbolNode *hashtab[HASHSIZE];

//checks symbol table for symbol with matching name
symbolNode *hasSymb(char *symName) {
    //symbolNode * hashtab[HASHSIZE];
    printf("symbol name passed down is %s\n", symName);
    symbolNode * symTable;
    for(symTable=hashtab[hash(symName, HASHSIZE)]; symTable != NULL; symTable = symTable->next){
        printf("symbol name before if is %s\n", symTable->symName);
        if (strcmp(symName, symTable->symName)==0){
            printf("symbol name is %s\n", symTable->symName);
            return symTable;
        }
    }
    return NULL; //not found
}
/*
    if (strcmp(symTable[i]->symName, symName) == 0)
      return symTable[i];

  return NULL;
}
    for (np=hashtab[hash(symName, HASHSIZE)]; np != NULL;	np = np -> next ){
        if (strcmp(symName, np->name)== 0)
            return np; // found
    }
    return NULL;
}
*/

//chekcs for multiple defineed symbols
//adds symbol if needed, or if there is one
//returns int of how much the location counter needs to get increamented

int addSymbol(char *line, unsigned int locationCounter, unsigned int ds, unsigned int ts, short secondPass) {
    unsigned hashval;
     symbolNode * symTable;
  char *label, *val;
  char *dupline = strdup(line);

  label = strtok(dupline, " \t");

  if (label[strlen(label)-1] != ':')
    return 1;

  label[strlen(label)-1] = '\0'; // remove colon

  if (hasSymb(label) && secondPass == 0) {
    addErr(shortLineCount, 'M', label);
    // multiply defined symbol
  }
  
  else if (label != NULL && !hasSymb(label)) {
      /*
*/

      if ( (symTable=hasSymb(label))== NULL){
          //symTable = (struct symbolNode *) malloc(sizeof(*symTable));
          symTable = (struct symbolNode *) malloc(sizeof(symbolNode));
                   hashval = hash(label,HASHSIZE);
          symTable->next = hashtab[hashval];
          hashtab[hashval]= symTable;
          symTable->symName = strdup(label);
          symTable->locationCounter=locationCounter;
      }

  }

  if (ds) {
       val = strtok(NULL, " \t\n");
    if (strcmp(val, WORD_DIRECTIVE) == 0) {
      val = strtok(NULL, " \t\n");

      val = strtok(val, ":");
      val = strtok(NULL, ":");

      return atoi(val);
    } else if (strcmp(val, RESW_DIRECTIVE) == 0) {
      val = strtok(NULL, " \t\n");

      return atoi(val);
    }
  }

  return 1;
}
/*

        np = (struct nlist *) malloc(sizeof(*np));
        if ( np == NULL ||  (np->name =strDup(name)) == NULL){
            printf("Out of memory");
            return 2; // out of memory.
        }
        hashval = hash(name);
        np -> next = hashtab[hashval];
        hashtab[hashval]= np;
        np->value=v;
        return 1;  // succesfully added
    }
    else // already there
        return 0;
}
*/

////////////////////////////////////////////////////
//fucking with strings
////////////////////////////////////////////////////


//removes new line character
//function to handle inline symbols
//removs everythig after #

void preprocLine(char *line) {
    char *tmp;
    
    tmp = strchr(line, '\n');
    
    if (tmp != NULL)
        *tmp = '\0';
    
    tmp = strchr(line, '#');
    
    if (tmp != NULL)
        *tmp = '\0';
}

/*
            free(np->name);
            free(np);
            np=u;
        }
        hashtab[i]=NULL;
    }
}
*/



char *removeLabel(char *line) {
    char *tmp, *orig;
    
    preprocLine(line);
    
    // checking if lable doesnt exist
    if (strchr(line, ':') == NULL)
        return line;
    
    orig = strdup(line);
   
    tmp = strdup(line);
    
    tmp = strtok(line, " \t");
    
    if (tmp != NULL && tmp[strlen(tmp)-1] == ':') {
        return (strlen(tmp) + orig);
    }
    
    return line;
}



//checks if line is empty and returns 1
//if not empty returns 0

int empty(const char *s) {
    while (*s != '\0' && *s != '\n') {
        if (!isspace(*s))
            return 0;
        s++;
    }
    return 1;
}



//checks if line is not empty and not a comment and returns 1
int validLine(char *line) {
    return (!empty(line) && line[0] != '#');
}

