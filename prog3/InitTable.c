//  email: akurbanovas@albany.edu
//  Student ID #: AK983513
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

struct table * tableCongif(FILE * configFiles, char * tableNames){
 // puts("inside tableconfig");
    int num, totalRowBytes, i, j;
    num = totalRowBytes = i = j = 0;
    int numCols, numRows, rowSize;
    numCols=numRows=rowSize=0;

    char * dataName; //used for sprintf
    char * tableName = (char *) malloc(sizeof(char)*16);
    strcpy(tableName,tableNames); //to copy all the cahrecters of tbaleNames to tableName array
    if(configFiles == NULL) puts("ITS NULL");
    fscanf(configFiles, "%d", &num);
    struct table * tableArray = (struct table *) malloc (sizeof(struct table));
    char **columnNames = (char**) malloc (sizeof(char*)*num); 
    for(i=0; i< num; i++){
        columnNames[i] = (char*)malloc(sizeof(char)*16);
    }
    char **columnTypes = (char**) malloc (sizeof(char*)*num);//datatypes
    for(i=0; i< num; i++){
        columnTypes[i] = (char*)malloc(sizeof(char)*4);
    }
    int **calledBytes = (int**) malloc (sizeof(int*)* num);
    for(i=0; i< num; i++){
        calledBytes[i] = (int*)malloc(sizeof(int));
    }
    //fflush(stdout);
  //  puts("after all mallocs");
 //fflush(stdout);
   
    
    for(i=0; num>i ; i++){
    fscanf(configFiles, "%s %s %d", columnNames[i], columnTypes[i],calledBytes[i]);
    totalRowBytes += *(calledBytes[i]);
    }

    FILE *dataFile;
  //  fflush(stdout);
  //  puts("before running fopen");
    dataName = malloc(strlen(tableNames)+7);
    sprintf(dataName, "%s.data", tableNames);
    dataFile= fopen(dataName, "r");
    //dataFile = fopen(strcat(tableNames,".data"), "r");
 //   fflush(stdout);
   // puts("after running fopen");
    //configFiles
    fseek(dataFile,0,SEEK_END);
    numRows = (ftell(dataFile))/totalRowBytes;
    // struct row **tableRow = (struct ** row) malloc(sizeof(struct *row)*numRows);

    struct row **rowArray = (struct row**) malloc(sizeof(struct row*)*numRows); //using a double ptr to make
                                                    //an array of array 
puts("right before for loop");                                                    //or an array of row structs
    for(i=0; num>i ; i++){
  //    fflush(stdout);
  //    puts("right before rowconfig");
        rowArray[i] = rowConfig(dataFile, num, calledBytes, columnTypes, columnNames);
//	fflush(stdout);
//	puts("right after rowconfig");        
/*
        for(i=0 ; i<numCols; i++){ //nested for loop
            fread(FILE *, calledBytes[i], row->attrArray[i] );
        }
        */
    }

    tableArray->rowArray = rowArray;
    tableArray->numRows = numRows;
    tableArray->numCols = num;
    tableArray->rowSize = totalRowBytes;
    tableArray->tableName = tableName;
    
    return (struct table*) tableArray;
    
}

struct row * rowConfig(FILE * dataFile, int numCols, int ** calledBytes, char ** columnTypes, char ** columnNames){
 // fflush(stdout);
 // puts("inside rowconfig");    
 int i;

     struct row *newRow = (struct row*) malloc(sizeof(struct row));
 //    printf("%d\n",numCols);
     
     newRow->numAttributs = numCols; //sending number of cols to row struct
     struct attribute **newAttribute = (struct attribute **) malloc(sizeof(struct attribute*)*numCols);
     for(i=0; i< numCols; i++){
        newAttribute[i] = (struct attribute*)malloc(sizeof(struct attribute));
        newAttribute[i] = attConfig(*(calledBytes[i]), columnTypes[i], columnNames[i]);
        printf("%d\n", newAttribute[i]->size);
        if(strcmp(newAttribute[i]->type, "str")) //if saving it to a string
            fread(newAttribute[i]->str, *(calledBytes[i]), 1, dataFile);
        else //saving to number
            fread(&(newAttribute[i]->intData), *(calledBytes[i]), 1, dataFile);
      }
     newRow->attrArray = newAttribute;
     return (struct row *)newRow;
}

struct attribute * attConfig(int calledBytes, char *columnTypes, char *columnNames){
  fflush(stdout);
 // puts("inside attconfig");   

    struct attribute *newAtt= (struct attribute *) malloc (sizeof(struct attribute));
    strcpy(newAtt->type, columnTypes);
    newAtt->size = calledBytes;
    newAtt->name = columnNames;
    if(strcmp(newAtt->type, "str")) //if saving it to a string
        newAtt->str = malloc(sizeof(char)*calledBytes);
    return (struct attribute *)newAtt;
}
    
