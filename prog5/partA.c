//
//  partA.c
//  program 5
//
//  Created by arnoldas kurbanovas on 5/1/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "partA.h"

//insert function: checks root is null, if null inserts head, if not it compares numbers and inserts them appropriately

void insert(char * fileNames, long long byteSize, char * dateModified, tree_node *root){
    //puts("in insert function\n");
    fflush(stdout);
    tree_node * newNode = malloc(sizeof(tree_node));
    
    if(root == NULL){
        //should never get here
        return;
    }
    
    newNode->byteSize = byteSize;
    newNode->dateModified = malloc(sizeof(char) * (strlen(dateModified)+1));
    newNode->fileNames = malloc(sizeof(char) * (strlen(fileNames)+1));
    newNode->right = NULL;
    newNode->left = NULL;
    strcpy( newNode->dateModified, dateModified);
    strcpy(newNode->fileNames, fileNames);
    
    
    while(1){
    // printToFile( node->string );
    //insert at the right if byteSize is larger than previous byteSize
    if((newNode->byteSize) > (root->byteSize)){
        if(root->right == NULL){
            root->right = newNode;
            return;
        }else{//keep looping thru tree
            root = root->right;
        }
    }

    //insert at the left if byteSize is smaller than previous byteSize
    else if((newNode->byteSize) < (root->byteSize)){
            if(root->left == NULL){
                root->left = newNode;
                return;
            }else{//keep looping thru tree
                root = root->left;
            }
    }
    //because needs to be printed in non-decreasing order then
    //doesnt matter if it gets inserted at the right of left
    //of the tree if they are equal
    else{
        
        if(root->right == NULL){
            
            root->right = newNode;
            
            return;
            
        }else{//keep looping thru tree
            
            root = root->right;
        }
    }//closes else
    }//closes while
}//closes insert function



//printTree function prints left subtree, root, and right sub tree
void treeprint( tree_node *root){
    if ( root != NULL){
        treeprint(root->left);
        printf("%s        ", root->fileNames);
        printf("%u bytes      ", (unsigned int)root->byteSize);
        printf("%s\n", root->dateModified);
        treeprint(root->right);
    }else{
        //printf("Done pritning tree!\n");
    }
}

