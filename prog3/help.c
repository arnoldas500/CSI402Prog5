//  email: akurbanovas@albany.edu
//  Student ID #: AK983513
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void * checkedMalloc(size_t s){
    void * p = malloc(s);
    if(p == NULL){
        fprintf(stderr, "Error mallocing!\n");
        exit(1);
    }else
        return p;
}

FILE * checkedOpen(const char * name, char * mode){
    FILE *file=fopen(name,mode);
    if(file==NULL){
        printf("failed to open input file");
        fprintf(stderr, "Could not open file: %s\n", name); exit(1);
    }else
        return file;
}

//debug tool
void checkpoint(){
    printf("%s\t%d\n",__FILE__,__LINE__);
    fflush(stdout);
}
