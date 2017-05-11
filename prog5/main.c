//
//  main.c
//  program 5
//
//  Created by arnoldas kurbanovas on 5/1/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//


#include "partA.h"

int main (int argc, char *argv[]) {
   // struct stat fileStats;
    DIR *currDirPtr = opendir(argv[1]); //for curent dirctory
    struct  dirent *dp;
    tree_node *root = NULL;
    
    if ((currDirPtr) == NULL) {
        //      printf("hereeeeeeeeeeee");
        fflush(stdout);
        
        fprintf(stderr, "Could not open directory %s\n", argv[1]);
        exit(1);
    }
    
    //command line checking
    if(argc >= 3){
        //if 3 arguments then it must be -s flag otherwise its wrong
        if(strcmp(argv[2], "-s")==0){
            
            fflush(stdout);
            while((dp = readdir(currDirPtr)) != NULL){
                
                //checking if its just a . (current directory) or .. (previous directory)
                if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") ){
                    //do nothing with these
                }
                else{
                    
                    //check if hidden characters
                    if(dp->d_name[0] == '.'){
                        //      printf("inside hiddne files");
                        fflush(stdout);
                        char * buff = malloc(sizeof(char) * (strlen(argv[1]) + strlen(dp->d_name)+3));
                        //strcpy(buff, "./");
                        strcpy(buff, argv[1]);
                        strcat(buff, "/");
                        strcat(buff, dp->d_name);
                        //stat(buff, argv[1]);
                        
                        
                        
                        //  int fd = open(dp->d_name, O_RDONLY);
                        
                        struct stat * s = malloc(sizeof(struct stat));
                        
                        
                        //    printf("right before stat");
                        fflush(stdout);
                        //printf("%s  --  ", dp->d_name);
                        if ((stat(buff, s)) ==0){
                            //getting date modified
                            time_t t = s->st_mtime;
                            //pointer to time structure
                            struct tm *tm;
                            //time string array
                            char buf[200];
                            //getting local time and braacking it down into a format we want and understand
                            tm = localtime(&t);
                            // format time by month day year
                            strftime(buf, sizeof(buf), "%b %d %Y ", tm);
                            //printf("%s\n", buf);
                            //    printf("%s\t%d\n",__FILE__,__LINE__);
                            fflush(stdout);
                            
                            
                            if(root == NULL){
                                root = malloc(sizeof(tree_node));
                                root->byteSize = s->st_size;
                                root->dateModified = malloc(sizeof(char) * (strlen(buf)+1));
                                root->fileNames = malloc(sizeof(char) * (strlen(dp->d_name)+1));
                                root->right = NULL;
                                root->left = NULL;
                                strcpy( root->dateModified, buf);
                                strcpy(root->fileNames, dp->d_name);
                                //    printf("%s\t%d\n",__FILE__,__LINE__);
                                fflush(stdout);
                                
                                
                            }else{
                                
                                //  printf("right before insert function");
                                fflush(stdout);
                                insert(dp->d_name, s->st_size, buf, root);
                                
                            }
                            
                        }
                        else{
                            printf("stat failed for this file!\n");
                            
                        }//closing else if stat failed
                        
                    }//closing hidden file if
                    
                }//closing else after checking . and ..
                
            }//closing while
            //printing all info
            if(root != NULL)
                treeprint(root);

            
            
        }else{ //print errors if incorect info for -s flag
            printf("Wrong number of arguments or incorreect flag specified!\n");
            fprintf(stderr, "Usage: %s dirname\n", argv[2]); exit(1);
        }
            
    }else if(argc == 2){
        fflush(stdout);
        while((dp = readdir(currDirPtr)) != NULL){
            
            //checking if its just a . (current directory) or .. (previous directory)
            if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") ){
                //do nothing with these
            }
            else{
                
                //check if hidden characters
                if(dp->d_name[0] == '.'){
                    //      printf("inside hiddne files");
                    fflush(stdout);
                    char * buff = malloc(sizeof(char) * (strlen(argv[1]) + strlen(dp->d_name)+3));
                    //strcpy(buff, "./");
                    strcpy(buff, argv[1]);
                    strcat(buff, "/");
                    strcat(buff, dp->d_name);
                    //stat(buff, argv[1]);
                    
                    
                    
                    //  int fd = open(dp->d_name, O_RDONLY);
                    
                    struct stat * s = malloc(sizeof(struct stat));
                    
                    
                    //    printf("right before stat");
                    fflush(stdout);
                    //printf("%s  --  ", dp->d_name);
                    if ((stat(buff, s)) ==0){
                        
                        //getting date modified
                        time_t t = s->st_mtime;
                        //pointer to time structure
                        struct tm *tm;
                        //time string array
                        char buf[200];
                        //getting local time and braacking it down into a format we want and understand
                        tm = localtime(&t);
                        // format time by month day year
                        strftime(buf, sizeof(buf), "%b %d %Y ", tm);
                        //printf("%s\n", buf);
                        //    printf("%s\t%d\n",__FILE__,__LINE__);
                        fflush(stdout);
                        
                        
                        if(root == NULL){
                            root = malloc(sizeof(tree_node));
                            root->byteSize = s->st_size;
                            root->dateModified = malloc(sizeof(char) * (strlen(buf)+1));
                            root->fileNames = malloc(sizeof(char) * (strlen(dp->d_name)+1));
                            root->right = NULL;
                            root->left = NULL;
                            strcpy( root->dateModified, buf);
                            strcpy(root->fileNames, dp->d_name);
                            //    printf("%s\t%d\n",__FILE__,__LINE__);
                            fflush(stdout);
                            
                            
                        }else{
                            
                            //  printf("right before insert function");
                            fflush(stdout);
                            insert(dp->d_name, s->st_size, buf, root);
                            
                        }
                        
                    }
                    else{
                        printf("stat failed for this file!\n");
                        
                    }//closing else if stat failed
                    
                }//closing hidden file if
                
            }//closing else after checking . and ..
            
        }//closing while
        //printing all info
        if(root != NULL)
            treeprint(root);

    }else{
        printf("Wrong number of arguments or wrong flag specified!\n");
        fprintf(stderr, "Usage: %s dirname\n", argv[1]); exit(1);
    }
    
    
    //close directory
    closedir(currDirPtr);
    return 0;
} //end main


