//
//  struct_def.h
//  program 1
//
//  Created by arnoldas kurbanovas on 2/2/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//
#include "constants.h"

#ifndef struct_def_h
#define struct_def_h
#define MAXLEN 15


//pointers to left and right children
//initilization of rightsubtree and left used for getting 
//left and right string count 
typedef struct tree_node{

    char string[MAXLEN+1];
    int rightsubtree;
    int leftsubtree;    
    struct tree_node *left;
    struct tree_node *right;

}tree_node;




#endif /* struct_def_h */
