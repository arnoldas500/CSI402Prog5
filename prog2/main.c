//
//  main.c
//  program2
//
//  email: akurbanovas@albany.edu
//  Created by arnoldas kurbanovas on 2/17/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "printToStd.c"
//#include "binaryToText.c"
//#include "textToBinary.c"
#define MAXLEN 255

int main(int argc, const char * argv[]) {
    FILE *input_File;
    FILE *output_File;

    
    //if the flag is not equal to any of the flags that we need, b, s, t, then exit the whole program
    if(strcmp(argv[1], "-b")!=0 && strcmp(argv[1], "-t") !=0 && strcmp(argv[1], "-s")!=0){
        printf("Invalid flag specified\n");
        fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
    }
    //if its an -s flag
    //then converting binary to standard output
    else if (strcmp(argv[1], "-s")==0) {
        //then check to make sure arguments are correct
        if (argc == 3) {
            //if arguments are correct then make sure the input file is in the correct spot
            if((input_File = fopen(argv[2], "r")) == NULL){
                printf("failed to open input file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[2]); exit(1);
            }
            //if everthing is correct run function
            printToStd(input_File);
        } else {
            printf("Wrong number of arguments for the -s flag\n");
            fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
        }
    }
    //if its a -b flag
    //converting binary to text
    else if(strcmp(argv[1], "-b")==0){
        //and arguments are correct for the b flag
        if (argc == 4) {
            //if arguments are correct then make sure the input file is in the correct spot
            if((input_File = fopen(argv[2], "r")) == NULL){
                printf("failed to open input file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[2]); exit(1);
            }
            //if arguments are correct then make sure the output file is in the correct spot
            if((output_File = fopen(argv[3], "w")) == NULL){
                printf("failed to open output file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[3]); exit(1);
            }
            //if everything is correct the run the actual function
            binaryToText(input_File, output_File);
        } else {
            printf("Wrong number of arguments for the -b flag\n");
            fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
        }
    }
    //if its a -t flag
    //then converting text to binary
    else if(strcmp(argv[1], "-t")==0){
        if (argc == 4) {
            //if arguments are correct then make sure the input file is in the correct spot
            if((input_File = fopen(argv[2], "r")) == NULL){
                printf("failed to open input file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[2]); exit(1);
            }
            //if arguments are correct then make sure the output file is in the correct spot
            if((output_File = fopen(argv[3], "w")) == NULL){
                printf("failed to open output file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[3]); exit(1);
            }
            //if everything is correct the run the actual function
            textToBinary(input_File, output_File);
        } else {
            printf("Wrong number of arguments for the -t flag\n");
            fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
        }
    }

    //closing files after done using them
    fclose(input_File);
    fclose(output_File);

    return 0;
}

