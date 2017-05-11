//
//  mainb.c
//  prog5b
//
//  Created by arnoldas kurbanovas on 5/5/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "partb.h"

int main(int argc, const char * argv[]) {
    
    int archive = 0;
    int fd = 0;
    int fd2= 0;
    
    //if the flag is not equal to any of the flags that we need, -c, -x, -p flag then exit the whole program
    if(strcmp(argv[1], "-c")!=0 && strcmp(argv[1], "-x") !=0 && strcmp(argv[1], "-p")!=0){
        printf("Invalid flag specified\n");
        fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
    }
    //if its an -c flag
    
    else if (strcmp(argv[1], "-c")==0) {
        //then check to make sure arguments are at least 4
        if (argc >= 4) {
            //if arguments are correct then make sure that open didnt fail
            if((archive = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0764)) == -1){
                printf("failed to open archive file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[2]); exit(1);
            }
            //if everthing is correct run function
            cflag(archive, argc, argv);
        } else {
            printf("Wrong number of arguments for the -c flag\n");
            fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
        }
    }
    //if its a -x flag
    
    else if(strcmp(argv[1], "-x")==0){
        //and arguments are correct for the -x flag
        if (argc == 3) {
            //if arguments are correct then make sure open didnt fail
            if((fd = open(argv[2], O_RDONLY)) == -1){
                printf("failed to open input file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[2]); exit(1);
            }
            //if everything is correct the run the actual function
            xflag(fd);
        } else {
            printf("Wrong number of arguments for the -x flag\n");
            fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
        }
    }
    //if its a -p flag
    
    else if(strcmp(argv[1], "-p")==0){
        if (argc == 4) {
            //if arguments are correct then make sure that open didnt fail

            if((fd2 = open(argv[3], O_RDONLY)) == -1){
                printf("failed to open input file\n");
                fprintf(stderr, "Could not open file: %s\n", argv[3]); exit(1);
            }
            
            //if everything is correct the run the actual function
            pflag(argv[2], fd2);
        } else {
            printf("Wrong number of arguments for the -t flag\n");
            fprintf(stderr, "Usage: %s file\n", argv[1]); exit(1);
        }
    }

        
    /*
     //-c flag
     archive = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
     cflag(archive, argc, argv);
     
     //-x flag
     fd = open(argv[2], O_RDONLY);
     xflag(fd);
     
     //-p flag
     fd2 = open(argv[3], O_RDONLY);
     pflag(argv[2], fd2);
     */
    
    
    
    return 0;
}
