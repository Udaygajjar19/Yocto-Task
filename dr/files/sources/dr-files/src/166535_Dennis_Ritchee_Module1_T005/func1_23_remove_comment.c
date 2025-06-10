
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000



void open_file(){

	/* opening one file to remove comments from it and creating another file to write code without comments*/
	FILE *file = fopen("/home/bhavik_23/test.c","r");
	FILE *file_copy = fopen("/home/bhavik_23/output.c","w");

	/* Error handling */
	if(file == NULL || file_copy == NULL){
		printf("Error: file is not opening");
	}
	
	uint8_t FLAG=0;
	uint16_t i;
	char line[MAXLINE];
	while (fgets(line,MAXLINE,file) != NULL){
	/* reading char by char to compare it with comment syntax*/
	for (i=0;line[i] !='\0';i++){

		/*if flag is 0 and there is / *  then it will make flag 1 */
		if (!FLAG && line[i] == '/' && line[i+1] == '*' ){
			FLAG=1;
			i++;
                        continue;

		}

		/*if flag is 1 then it will check for end of the multiline comment */
		if (FLAG && line[i] == '*' && line[i+1] == '/'){
			FLAG=0;
			i++;
                        continue;
		
		}

		/* skips all the content within multiline comment*/
		if(FLAG){
			continue;
		}

		/* if there is single line comment then it will skip thatv line*/
		if (line[i] == '/' && line[i+1] == '/'){
                       	i++;
			break;
                }
		fputc(line[i],file_copy);
	}
	}
	printf("removed comments and stored it into output.c");
	
	/* closing both the files*/
	fclose(file);
	fclose(file_copy);
}
