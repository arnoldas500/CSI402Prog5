//  email: akurbanovas@albany.edu
//  Student ID #: AK983513
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
/* 
 * File:   main.c
 * Author: arnoldas
 *
 * Created on March 3, 2016, 1:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

//void queryHandler(FILE *, struct data*);
/*
 * 
 */
int main(int argc, const char * argv[]) {

   if(argc != 3){
        printf(" not enough god dam files ");
        fprintf(stderr, "Usage: %s file\n", argv[0]); exit(1);
    }


    FILE * configFile = checkedOpen(argv[1], "r");
    FILE * queryFile = checkedOpen(argv[2], "r");
    

    puts("about to run dataconfig");
    //    dataConfig(configFile);
    struct dataBase * dataBase = dataConfig(configFile);
    queryPrint(dataBase, queryFile);
    
    

    return (EXIT_SUCCESS);
}

