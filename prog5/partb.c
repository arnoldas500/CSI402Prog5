//
//  partb.c
//  prog5b
//
//  Created by arnoldas kurbanovas on 5/5/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "partb.h"

//starting -c flag
void cflag(int archive, int argc, const char ** argv){
    unsigned int offset = 0;
    unsigned char numArgs = argc - 3; //for the for loop
    int fd =0;
//    int archive = 0;
  //  unsigned int size = 0;
    unsigned char a;
    int i =0;
    write(archive, &numArgs, sizeof(unsigned char));
    for(i=3; i<argc; i++){
        a = (unsigned char) strlen(argv[i]);
        fd = open(argv[i], O_RDONLY);
        offset = (unsigned int)lseek(fd, 0, SEEK_END);
        write(archive, &a, sizeof(unsigned char)); //writes a into archive
        write(archive, argv[i], strlen(argv[i])); //writes the string into archive
        //lseek(archive, -1, SEEK_CUR);
        write(archive, &offset, sizeof(unsigned int)); //size for particular file
        
        close(fd);
        
    }//closing for loop
    
    //second pass
    for(i =3; i<argc; i++){
        fd= open(argv[i], O_RDONLY);
        while(read(fd, &a, sizeof(unsigned char))>0){
            //printf("before write\n");
            write(archive, &a, sizeof(unsigned char));
            
        }//closing while
        close(fd);
    }//closing second for
    
    close(archive);
}//closing -c flag function


//starting p flag
void pflag(const char * argv, int fd){
    //fd is the archive passed in
    unsigned char numStr, strLen;
    unsigned int byteSize = 0;
    int trueCounter = 0; //counter for checking if there are no matching files
    //variables for loops
    int i, j;
    i = j = 0;
    //reading in the number of characters
    read(fd, &numStr, sizeof(unsigned char));
    for(i=0; i<numStr; i++){
        int flag = 1; //going to be used for checking if need to skip a prefix or not
        //getting first char
        read(fd, &strLen, sizeof(unsigned char));
        
        unsigned char * inputStr = malloc((strLen)* sizeof(unsigned char));
        read(fd, inputStr, strLen * sizeof(unsigned char));
        inputStr[strLen] = '\0';
        if(strlen((char *)inputStr) >= strlen(argv)){
            //starting second for loop
            for(j=0 ; j<strlen(argv) ; j++){
                if(inputStr[j] != argv[j]){
                    flag = 0; //testing value to skip over prefix if zero for later check
                    break; //exit from second for loop
                }
            }//closing second for loop
            
            if(flag == 1){
                //move to pointer of intiger part
                //lseek(fd, (strLen-j), SEEK_CUR);
                read(fd, &byteSize, sizeof(unsigned int));
                printf("Name : %s , Byte Size: %u\n", inputStr, byteSize);
                trueCounter++;
            }else{ //if invalid flag
                //skip over by 4 bytes to next prefix
                lseek(fd, sizeof(unsigned int), SEEK_CUR);
                //seeking over that prefix because it doesnt match
            }
        }//closing if
        
    }//closing first for loop
    
    //check for if no matching files were found
    if(trueCounter == 0){
        printf("No matching files found!\n");
    }
    
}//closing pflag function



//starting -x flag
void xflag(int fd){
    //fd is the archive thats getting passed in
    unsigned char numFiles, fileLen;
    int i, j;
    i = j = 0;
    read(fd, &numFiles, sizeof(char));
    //making string of size of the number of files
    unsigned char * str[numFiles];
    //making integer with size of number of files
    unsigned int num[numFiles];
    //for loop for info section
    for(i=0; i<numFiles; i++){
        read(fd, &fileLen, sizeof(unsigned char));
        str[i] = malloc((fileLen+1) * sizeof(unsigned char));
        read(fd, str[i], fileLen * sizeof(unsigned char));
        str[i][fileLen] = '\0';
        read(fd, &num[i], sizeof(unsigned int));
        
    }//closing for loop for info section
    
    //for loop for data section
    for(i=0; i<numFiles; i++){
        unsigned char temp;
        unsigned int fd2 = open((char *)str[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        //nested for loop
        for(j=0; j<num[i]; j++){
            read(fd, &temp, sizeof(unsigned char));
            write(fd2, &temp, sizeof(unsigned char));
            
        }//closing nested for loop
        close(fd2);
    }//closing for loop for data section
    close(fd); //closing archive
}//closing xflag


