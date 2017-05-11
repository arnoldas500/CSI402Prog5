//
//  insert.c
//  program 1
//
//  Created by arnoldas kurbanovas on 2/2/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "constants.h"

//function that creats space in memory for characters
//that will be read in from a file and when function
//is called it inserts those characters by using 
//strcpy to compare them to see if they will be
//inserted to the left or to the right depending on
//if they are greater or less then zero.
//function also first checks that left and right nodes
//being inserted to make sure they are not null 
//and contain characters
tree_node * insert(tree_node *node, char str[MAXLEN]){
   
    if(node == NULL){
        node = (tree_node *)malloc(sizeof(tree_node));
        strncpy(node -> string, str, MAXLEN);
        node -> left = NULL;
        node -> right = NULL;
    //    printToFile( node->string );
        
    }
    // printToFile( node->string );
    
    else if(strcmp(node->string, str)<0){
        node -> right = insert(node->right, str);
        node->rightsubtree++;
    }
    else if(strcmp(node->string, str)>0){
        node -> left = insert(node->left, str);
        node->leftsubtree++;
    }
    
    return node;
}


