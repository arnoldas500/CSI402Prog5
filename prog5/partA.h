//
//  partA.h
//  program 5
//
//  Created by arnoldas kurbanovas on 5/1/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#ifndef partA_h
#define partA_h
#define MAXLEN 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>


#endif /* partA_h */


//pointers to left and right children

typedef struct tree_node{

    char *fileNames;
    long long byteSize;
    char *dateModified;
    
    struct tree_node *left;
    struct tree_node *right;
}tree_node;

//prototypes


void insert(char *, long long, char *, tree_node *);
void treeprint( tree_node * );

