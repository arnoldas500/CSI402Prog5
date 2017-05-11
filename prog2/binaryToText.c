//
//  binaryToText.c
//  program2
//
//  email: akurbanovas@albany.edu
//  Created by arnoldas kurbanovas on 2/24/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXLEN 255

void binaryToText(FILE * input_File, FILE * output_File){
    
    char strIn[MAXLEN+1];
    unsigned char length;
    unsigned int num_str = 0;
//    unsigned int minLen ;
//    unsigned int maxLen = 0;
//    unsigned int maxInt = 0;
//    unsigned int minInt ;
    
      while(fread(&length, (size_t) 1, (size_t)1, input_File) ==1){
        
      fread(&strIn, (size_t)length, (size_t)1, input_File);
      fread(&num_str, (size_t)(sizeof(unsigned int)), (size_t)1, input_File);
        
      strIn[length] = '\0'; //adding null cahracter in the end of string array
      
      //      printf("%s \t %d", strIn, num_str);
      //using ftell and if statement to check if the file
      //is empty and if were at the start
      //if so then print first line without a new line
      //in the front and the rest with a new line
      if(ftell(output_File) == 0){
	fprintf(output_File, "%s\t%d", strIn, num_str);
      }else{
        fprintf(output_File, "\n%s\t%d", strIn, num_str);
      }
      }    
}
