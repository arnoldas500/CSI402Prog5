//  email: akurbanovas@albany.edu 
//  Student ID #: AK983513
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


int checkTable(struct dataBase *dataBase, char * tableNames){
  //  checkPoint(stdout);
 // printf("%s\t%d\n",__FILE__,__LINE__);
 // fflush(stdout);   
 if(dataBase==NULL)
        printf("dataBase doesnt exist\n");
    if((dataBase->tableArray) == NULL)
        printf("tableArray doesnt exist\n");
    int i, numTables;
    i = numTables = 0;
    numTables = dataBase->numTables;
    for(i=0; i<numTables; i++){
        if((strcmp((dataBase->tableArray[i])->tableName, tableNames)==0))
            return 1; //table got populated correctly
    }
    return 0; //failed exit
}

int checkColNames(struct dataBase *dataBase, char * tableNames, char * colNames){
  // checkPoint(stdout);
  //  printf("colnames pased in **********    %s\n", colNames);
 // printf("%s\t%d\n",__FILE__,__LINE__);
 // fflush(stdout); 
 if(dataBase==NULL)
        printf("dataBase doesnt exist\n");
    if((dataBase->tableArray) == NULL)
        printf("tableArray doesnt exist\n");
    int i, j, numTables, numCols;
    i = j = numTables = numCols = 0;
    //numRows = dataBase->tableArray->numRows;
    numTables = dataBase->numTables;
    //numCols = dataBase->tableArray->numCols;
  //  printf("%s\t%d\n",__FILE__,__LINE__);
 // fflush(stdout); 
 // printf("num tables: %d\n", numTables);
    for(i=0; i<numTables; i++){
        if((strcmp((dataBase->tableArray[i])->tableName, tableNames)==0)){
            
          //  printf("%s\t%d\n",__FILE__,__LINE__);
         //   fflush(stdout); 
            numCols = dataBase->tableArray[i]->numCols;
          //  printf("num cols: %d\n", numCols);
            for(j=0; j<numCols; j++){
          //      printf("%s\t%d\n",__FILE__,__LINE__);
            //    fflush(stdout); 
            //    printf("name %s\n", dataBase->tableArray[i]->rowArray[0]->attrArray[j]->name);
                if((strcmp((dataBase->tableArray[i]->rowArray[0]->attrArray[j]->name), colNames)==0)){
                    printf("%s\t%d\n",__FILE__,__LINE__);
                fflush(stdout); 
                
                return 1; //table got populated correctly
                }
                
            }//ends inner for loop
            return 0;
        }//ends if statement
    }//ends outter for loop
    return 0; //failed exit
}

void queryPrint(struct dataBase *dataBase, FILE *queryFile){
  // checkPoint(stdout);   
 // printf("%s\t%d\n",__FILE__,__LINE__);
 // fflush(stdout);
 char str[101];
 const char s[2] = " "; //for the token
 char * token;
 
 int offset = 0;
 //for(offset = 0; offset < 102; ++offset)
   //temp[offset] = '\0';
    while(fgets((str), 100, queryFile)!=NULL){
      //offset = 0;
    //  printf("%s\n", str);
    //  printf("%s\t%d\n",__FILE__,__LINE__);
      fflush(stdout);
        char *strPtr[5];
        char strTemp[101];
        token = strtok(str,s); //prime the first token
        int i =0;
    //    printf("after priming %s\n", str);
    //  printf("%s\t%d\n",__FILE__,__LINE__);
    //  fflush(stdout);
            while(token != NULL){ //going thru all tokens
       //      printf("%s\n", token);
              //token = strtok(NULL,s);
        //      printf("%s\n", token);
        //      printf("%s\t%d\n",__FILE__,__LINE__);
              strPtr[i] = malloc((strlen(token)+1) *sizeof(char));
              strcpy(strPtr[i], token);
              
              i++;
              token = strtok(NULL,s);
             }
        //printf("%s\n", strPtr);
  //    printf("%s\t%d\n",__FILE__,__LINE__);
 //     fflush(stdout);
	//for(offset = 0; offset < 102; ++offset)
	  //strTemp[offset] = '\0';
	//offset = 0;
        //int i=0;
	//int j=0;
	//        while((sscanf((temp+offset), "%s", strTemp))!=NULL){
	//  for(j=0;(temp[j] != '\n');j++){
	//    printf("%hhu ", temp[j]);
	//  }
	///  printf("\n\n");
	  //	  while(temp[offset] == ' ' || temp[offset] == '\0' || temp[offset] == '\t'){
	  // offset++;
	    //	  }
	//fscanf(queryFile, "%s", str);
        
        /*
	while(temp[i]!= '\n' && temp[i] != NULL){
	  while(temp[i] == ' ' || temp[i] == '\t'){
	    i++;
	  }
	  j=i;
	  while(temp[j]!= '\n' && temp[j] != NULL && temp[j] != ' ' && temp[j] != '\t'){
	    j++;
	  }
	  strPtr[offset] = (char*)malloc((j-i+1)* sizeof(char));

  printf("%s\t%d\n",__FILE__,__LINE__);
	  fflush(stdout);
	  printf("%s\n",strTemp);
            strPtr[i] = malloc((strlen(strTemp)+1) *sizeof(char));
            strcpy(strPtr[i], strTemp);
	    strPtr[strlen(strTemp) + 1] = '\0';
	    printf("%s\n", strPtr[i]);
	    //for(j=0;(temp[j] != '\n');j++){
	    //printf("%hhu ", temp[j]);
            //} 
	    offset+=strlen(strPtr[i]);
	    for(j=0;(temp[j] != '\n');j++){
	     printf("%hhu ", temp[j]);
	    }
       
	    i++;
	    printf("%s\n",(temp+offset));
        }
        */
      //  printf("before switch\n");
        switch(strPtr[0][0]){
            
            case 'p':
        //        printf("in case p");
        //        printf("%d\n", dataBase->numTables);
        //        printf("about to run         *************************           project   ***** \n");
                strPtr[2][(strlen(strPtr[2])-1)]='\0';
                if(strcmp(strPtr[0], "project")==0){
                    //project(dataBase, strPtr);
                if(checkTable(dataBase,strPtr[1]) && checkColNames(dataBase, strPtr[1], strPtr[2])){
                      //  project(dataBase, strPtr);
                    }else{
                        if(checkTable(dataBase,strPtr[1])){
                            if(checkColNames(dataBase, strPtr[1], strPtr[2])){
                                printf("unknow error!\n");//this should never actually run
                            }else
                                printf("Column does not exist when running project!\n");
                        }
                        else{
                            printf("Table does not exist when running project!\n");
                        
                        }
                    }
                }
                break;
                
            case 'c':
                printf("in case c");
                strPtr[2][(strlen(strPtr[2])-1)]='\0';
                if(strcmp(strPtr[0], "colStat")==0){
                    colStat(dataBase, strPtr);
                }
                else
                    printf("error using c\n");
                break;
                
            case 'r':
                printf("in case r");
                strPtr[1][(strlen(strPtr[1])-1)]='\0';
                if(strcmp(strPtr[0], "rowStat")==0){
                    rowStat(dataBase, strPtr);
                }
                else
                    printf("error using r\n");
                break;
                
            case 'n':
                printf("in case n");
                strPtr[1][(strlen(strPtr[1])-1)]='\0';
                if(strcmp(strPtr[0], "numRows")==0){
                    numRow(dataBase, strPtr);
                }
                else if(strcmp(strPtr[0], "numCols")==0){
                    numCol(dataBase, strPtr);
                }
                else
                    printf("error using n\n");
                break;
                
            case 's':
      //          printf("jgkejkejh                     %s", strPtr[0]);
                if(strcmp(strPtr[0], "select")==0){
                    if(checkTable(dataBase,strPtr[1]) && checkColNames(dataBase, strPtr[1], strPtr[2])){
                              printf("%s\n", str);
      printf("%s\t%d\n",__FILE__,__LINE__);
      printf("bout to run select\n");
                     //   select(dataBase, strPtr);
                    }else{
                        if(checkTable(dataBase,strPtr[1])){
                            if(checkColNames(dataBase, strPtr[1], strPtr[2])){
                                printf("unknow error!\n");//this should never actually run
                            }else
                                printf("Column does not exist when running select!\n");
                                  printf("%s\n", str);
      printf("%s\t%d\n",__FILE__,__LINE__);
                        }
                        else{
                            printf("Table does not exist when running select!\n");
                                  printf("%s\n", str);
      printf("%s\t%d\n",__FILE__,__LINE__);
                        
                        }
                    }
                }
                else if(strcmp(strPtr[0], "stop\n")==0){
                    printf("bout to run stop\n");
                    exit(1);
                    //call stop function
                }
                else
                    printf("error using s\n");
                break;
                    
                
            default:
                printf("error! default case hit");
                break;
        }//ends switch statement
    }//ends while loop for fgets
}

void project(struct dataBase *dataBase, char ** strPtr){
    printf("%d\n", dataBase->numTables);
  // checkPoint(stdout);  
  printf("%s\t%d\n",__FILE__,__LINE__);
  fflush(stdout); 
 int colIndex, i, j, k;
    colIndex = 0;
    struct rowMarker * rowMarker = NULL;
    struct rowMarker * currentMarker = NULL;
    printf("before database\n");
    if(dataBase==NULL)
        printf("very bad");
    printf("%d\n", dataBase->numTables);
    //numTables = dataBase->numTables;
    printf("after row markers");
    for(i=0; i<(dataBase->numTables); i++){
        //numCols = (dataBase->tableArray[i]->numCols);
        for(k=0; k<(dataBase->tableArray[i]->numCols); k++){
            //numRows = (dataBase->tableArray[i]->numRows);
            colIndex = k;
            for(j=0; j<(dataBase->tableArray[i]->numRows); j++){
                //break; // ???
                printf("before while");
                
                while(1){ //keep looping, will exit at one of the breaks;
                    if(currentMarker == NULL){
                        if(rowMarker == NULL){
                            rowMarker = (struct rowMarker*) malloc(sizeof(struct rowMarker));
                            rowMarker->mark = dataBase->tableArray[i]->rowArray[j];
                            break;
                        }
                    }  
                    //currentMarker = rowMarker->mark->attrArray[k];
                    if(strcmp(currentMarker->mark->attrArray[k]->str, dataBase->tableArray[i]->rowArray[j]->attrArray[k]->str) == 0) //if its a string
                        break;
                    
                    if(currentMarker->next != NULL)
                        currentMarker = currentMarker->next;
                    else{
                        currentMarker->next = (struct rowMarker*) malloc(sizeof(struct rowMarker));
                        currentMarker->next->mark = dataBase->tableArray[i]->rowArray[j];
                        break;
                            } 
                }
                currentMarker = rowMarker;// closing while loop
                //currentMarker = headRowMarker;
            }
        }
    } //closing most outer for loop
    while(currentMarker!= NULL){
        if(strcmp(currentMarker->mark->attrArray[colIndex]->type, "str") == 0) //if its a string
            printf("projecting: %s", currentMarker->mark->attrArray[colIndex]->str); //print for if its a string 
        else
            printf("projecting: %d", currentMarker->mark->attrArray[colIndex]->intData); //printing for if its an int
    }
    
}//closing project function

void printRow(struct row* r){
  // checkPoint(stdout);  
  printf("%s\t%d\n",__FILE__,__LINE__);
  fflush(stdout); 
 int numCols, i;
    numCols = i = 0;
    numCols= r->numAttributs;
    for(i=0;i<numCols;i++){
        if(strcmp(r->attrArray[i]->type, "str")==0) //for string part
            printf("%s", r->attrArray[i]->str);
        else //for integer part
            printf("%d", r->attrArray[i]->intData);
        
    }
}

void select(struct dataBase *dataBase, char ** strPtr){
  // checkPoint(stdout);  
  printf("%s\t%d\n",__FILE__,__LINE__);
  fflush(stdout); 
 int i, j, k, numCols, numRows, numTables;
    i = j = k = numCols = numRows = numTables = 0;
    numTables = (dataBase->numTables);
    for(i=0; i<numTables ; i++){
        numCols = (dataBase->tableArray[i])->numCols;
        for(k=0; k<numCols ; k++){
            numRows = (dataBase->tableArray[i])->numRows;
            printf("I got here\n");
            if(strcmp((strPtr[2]), (((dataBase->tableArray[i])->rowArray[0])->attrArray[k])->name)==0 ){
            for(j=0; j<numRows ; j++){
                if(strlen(strPtr[3])<2){
                    if(strcmp(dataBase->tableArray[i]->rowArray[j]->attrArray[k]->type, "str")==0){
                        printf("Error its a string!");
                        return;
                    }else{
                        if(strPtr[3][0]=='<'){
                            if((dataBase->tableArray[i]->rowArray[j]->attrArray[k]->intData) < atoi(strPtr[4])){ //if less than
                                printRow(dataBase->tableArray[i]->rowArray[j]);
                            }
                            
                        }
                        if(strPtr[3][0] == '>'){
                                if((dataBase->tableArray[i]->rowArray[j]->attrArray[k]->intData) > atoi(strPtr[4])){ // if greater than
                                printRow(dataBase->tableArray[i]->rowArray[j]);
                            }
                        }
                        
                    }
                }
                else if(strlen(strPtr[3])==2){
                    if(strPtr[3][1] == '='){
                        if(strPtr[3][0] == '>'){ //for =>
                            if(strcmp(dataBase->tableArray[i]->rowArray[j]->attrArray[k]->type, "str")==0){
                            printf("Error its a string!");
                            return;
                            }
                            else{
                                if((dataBase->tableArray[i]->rowArray[j]->attrArray[k]->intData) >= atoi(strPtr[4])){ //if greater than or equal
                                    printRow(dataBase->tableArray[i]->rowArray[j]);
                                }
                            }
                            
                        }else if(strPtr[3][0] == '<'){ //for =<
                            if(strcmp(dataBase->tableArray[i]->rowArray[j]->attrArray[k]->type, "str")==0){
                            printf("Error its a string!");
                            return;
                            }
                            else{
                                if((dataBase->tableArray[i]->rowArray[j]->attrArray[k]->intData) <= atoi(strPtr[4])){ //if less than or equal
                                    printRow(dataBase->tableArray[i]->rowArray[j]);
                                }
                            }
                        }
                    }else if(strPtr[3][0] == '='){//for ==
                        if(strcmp(dataBase->tableArray[i]->rowArray[j]->attrArray[k]->type, "str")==0){
                            char * temp = (char *) malloc(sizeof(char)*(strlen(strPtr[4])));
                            strcpy(temp, strPtr[4]);
                            strtok(temp, "\"");
                            
                            if(strcmp(temp, dataBase->tableArray[i]->rowArray[j]->attrArray[k]->str)==0){
                                printRow(dataBase->tableArray[i]->rowArray[j]);
                            }
                            
                            }
                        else{ //in case it is an integer type
                                if((dataBase->tableArray[i]->rowArray[j]->attrArray[k]->intData) == atoi(strPtr[4])){ //if less than or equal
                                    printRow(dataBase->tableArray[i]->rowArray[j]);
                                }
                            }
                        
                    }else if(strPtr[3][0] == '!'){//for !=
                        if(strcmp(dataBase->tableArray[i]->rowArray[j]->attrArray[k]->type, "str")==0){
                            char * temp = (char *) malloc(sizeof(char)*(strlen(strPtr[4])));
                            strcpy(temp, strPtr[4]);
                            strtok(temp, "\"");
                            
                            if(strcmp(temp, dataBase->tableArray[i]->rowArray[j]->attrArray[k]->str)!=0){
                                printRow(dataBase->tableArray[i]->rowArray[j]);
                            }
                            
                            }
                        else{ //in case it is an integer type
                                if((dataBase->tableArray[i]->rowArray[j]->attrArray[k]->intData) != atoi(strPtr[4])){ //if less than or equal
                                    printRow(dataBase->tableArray[i]->rowArray[j]);
                                }
                            }
                        
                    }
                }else//in case non of the above
                    printf("Error! non of the above cases for select!");
            }
            }//closing new if statement
        }
    }
}

void numRow(struct dataBase *dataBase, char ** strPtr){
    int numRows, numTables, numCols, i, j, k;
    numRows = numTables = numCols = i= j = k = 0;
    numTables = dataBase->numTables;
    
    for(i=0; i<numTables ; i++){
        if(strcmp(strPtr[1], dataBase->tableArray[i]->tableName)==0);
            printf("The number of rows: %d \n",dataBase->tableArray[i]->numRows);
    }
}


void numCol(struct dataBase *dataBase, char ** strPtr){
    int numRows, numTables, numCols, i, j, k;
    numRows = numTables = numCols = i= j = k = 0;
    numTables = dataBase->numTables;
    
    for(i=0; i<numTables ; i++){
        if(strcmp(strPtr[1], dataBase->tableArray[i]->tableName)==0);
            printf("The number of columns: %d \n",dataBase->tableArray[i]->numCols);
    }
}

void colStat(struct dataBase *dataBase, char ** strPtr){
  int numRows, numTables, numCols, i, j, k;
    numRows = numTables = numCols = i= j = k = 0;
    numTables = dataBase->numTables;
    
    for(i=0; i<numTables ; i++){
        numCols = dataBase->tableArray[i]->numCols;
        if(strcmp(strPtr[1], dataBase->tableArray[i]->tableName)==0){
            for(j=0; j<numCols; j++){
                if(strcmp(strPtr[2], dataBase->tableArray[i]->rowArray[0]->attrArray[j]->name)==0);
                    printf("The size in bytes of each column line %d\n",dataBase->tableArray[i]->rowArray[0]->attrArray[j]->size);
        }
        }
    }
}

void rowStat(struct dataBase *dataBase, char ** strPtr){
    int numRows, numTables, numCols, i, j, k;
    numRows = numTables = numCols = i= j = k = 0;
    numTables = dataBase->numTables;
    
    for(i=0; i<numTables ; i++){
        if(strcmp(strPtr[1], dataBase->tableArray[i]->tableName)==0);
            printf("The size in bytes of each row line %d\n",dataBase->tableArray[i]->rowSize);
    }
}



