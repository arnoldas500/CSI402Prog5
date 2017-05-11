//
//  helpfun.c
//  program2
//
//  email: akurbanovas@albany.edu
//  Created by arnoldas kurbanovas on 2/24/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include <stdio.h>

void die(char * message){ //for fatal errors
    fprintf(stderr, "%s\n", message);
    fflush(stderr);
    exit(1);
}

void debug(char * message){ //for non-fatal errors
    printf("%s\n", message);
    fflush(stdout);
}

void * checkedMalloc(size_t size){ //make sure malloc worked and had enough spaces
    void * ptr= malloc(size);
    if (ptr == NULL) {
        die("Malloc failed");
    }
    return ptr;
}