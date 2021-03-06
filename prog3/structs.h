//  email: akurbanovas@albany.edu
//  Student ID #: AK983513
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.

/* 
 * File:   structs.h
 * Author: arnoldas
 *
 * Created on March 3, 2016, 1:20 PM
 */

#ifndef STRUCTS_H
#define STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

//prototyes for all functions
void checkPoint();
FILE * checkedOpen(const char *, char *);
void * checkedMalloc(size_t);
struct dataBase * dataConfig(FILE *);
struct row * rowConfig(FILE *, int, int **, char **, char **);
struct attribute * attConfig(int , char *, char *);
struct table * tableCongif(FILE *, char *);
int checkTable(struct dataBase *, char * );
int checkColNames(struct dataBase *, char * , char * );
void queryPrint(struct dataBase *, FILE *);
void project(struct dataBase *, char ** );
void select(struct dataBase *, char ** );
void printRow(struct row* );


void colStat(struct dataBase *, char ** );
void numCol(struct dataBase *, char ** );
void rowStat(struct dataBase *, char ** );
void numRow(struct dataBase *, char ** );
 


    
struct dataBase{
    int numTables;
    struct table **tableArray;

};

struct table{
    int numRows;
    int numCols;
    int rowSize;
    char * tableName;
    struct row **rowArray;
};

struct row{
    int size; //total number of bytes that it takes
              //that row to sotre in a binary file
    int numAttributs; // number of columns
    struct attribute ** attrArray; //array of attibutes
};

struct attribute{
    unsigned char * str;
    char *name;
    char type[4];
    int size;
    int intData;
    char *startingData;
  //    union dataBase value;//this is how you create an instance of it (like an object in java)
};

struct rowMarker{ //for linked list in query project function 
    struct row* mark;
    struct rowMarker* next;
};

  /*
union dataBase{ //allows you to allocate memory for either a string or an integer
//only one of the below can be used at a time
    char *str;
    int integer;
};
  */



#ifdef __cplusplus
}
#endif

#endif /* STRUCTS_H */

