//
//  printToStd.c
//  program2
//
//  email: akurbanovas@albany.edu
//  Created by arnoldas kurbanovas on 2/25/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXLEN 255

void printToStd(FILE * input_File){
    
    
    char strIn[MAXLEN+1];
    unsigned char length;
    unsigned int num_str = 0;
    unsigned int minLen = 0;
    unsigned int maxLen = 0;
    unsigned int maxInt = 0;
    unsigned int minInt = 0;
    
    fread(&length, (size_t) 1, (size_t)1, input_File);
    fread(&strIn, (size_t)length, (size_t)1, input_File);
    fread(&num_str, (size_t)(sizeof(int)), (size_t)1, input_File);
    
    minInt = num_str;
    minLen = length;

    puts("before while");
          while(fread(&length, (size_t) 1, (size_t)1, input_File) ==1){
	    puts("inside while");
          fread(&strIn, (size_t)length, (size_t)1, input_File);
          fread(&num_str, (size_t)(sizeof(int)), (size_t)1, input_File);
        
        
        if (length <= minLen) {
            minLen = length;
        }
        if (length >= maxLen) {
            maxLen = length;
        }
        if (num_str <= minInt) {
            minInt = num_str;
        }
        if (num_str >= maxInt) {
            maxInt = num_str;
        }
    }
    printf("Length of shortest string = %u\n", minLen);
    fflush(stdout);
    printf("Length of longest string = %u\n", maxLen);
    fflush(stdout);
    printf("Value of maximum integer = %u\n", maxInt);
    fflush(stdout);
    printf("Value of minimum integrer = %u\n", minInt);
    fflush(stdout);
    
}
