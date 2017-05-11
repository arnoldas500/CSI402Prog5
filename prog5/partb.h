//
//  partb.h
//  prog5b
//
//  Created by arnoldas kurbanovas on 5/5/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#ifndef partb_h
#define partb_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>

//function prototypes

void cflag(int , int , const char ** );
void pflag(const char * , int fd);
void xflag(int fd);

#endif /* partb_h */
