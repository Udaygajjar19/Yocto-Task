/* REQUIRED HEADERS */
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/* REQUIRED MACROS */
#define MAXLINE 1000


void Dir_table(){
	char sub_dirname[MAXLINE];
        char dirname[MAXLINE] = "/home/omrathod";
       
        printf("Enter dir path: ");
        scanf(" %s", sub_dirname);
        strcat(dirname,sub_dirname);
        /*opens the search dir*/
        DIR *dirp = opendir(dirname);
        if (dirp == NULL) {
                /*if there is no file searched for*/
                printf("Error: Unable to open directory\n");
                closedir(dirp);
                return;
        }

        /* getting dir struct and then reading from opended dirname*/
        struct dirent *dir;
	printf("\tDirectory Name\t | \tDirectory Type\t |\n");
	printf("--------------------------------------------------------------------\n");
        while ((dir = readdir(dirp) ) != NULL){
		/*it will read the dir or file in an dir and display its name ne file type in octal value*/
		char type[256];
		if(dir->d_type == DT_DIR){
                	strcpy(type,"Directory");
        	}
        	else if(dir->d_type == DT_REG){
                	strcpy(type,"File");
        	}
        	else{
        		strcpy(type, "Other");
		}
		printf("%-30s  %-30s \n", dir->d_name,type);
	}
	closedir(dirp);
	
}

/*
const char *Dir_type(int32_t type){
	if(type == DT_DIR){
		return "Directory";
	}
	else if(type == DT_REG){
		return "File";
	}
	else{
		return "Other";
	}
}
*/

