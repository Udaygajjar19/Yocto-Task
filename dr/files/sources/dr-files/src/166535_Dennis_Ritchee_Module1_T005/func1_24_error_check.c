/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

void error_check(){
	char line[MAXLINE];
	int16_t i_paren=0,i_brack=0,i_brace=0;
	uint16_t i;
	
	/*Opening the .c file to check for errors*/	
	FILE *file = fopen("/home/bhavik_23/example.c","r");
	/*storing the file content in string*/
	while(fgets(line,MAXLINE,file) != NULL)
	{
		/* reading string char by char */
		for (i=0;line[i]!='\0';i++){

			/*Condition for paretheses*/
			if (line[i] == '('){
				i_paren++;
			}
			if (line[i] == ')' ){
				i_paren--;
			}

			/*Condition for square bracket*/
			if (line[i] == '[' ){
                                i_brack++;
                        }
			if (line[i] == ']' ){
                                i_brack--;
                        }

			/*Condition for braces*/
			if (line[i] == '{'){
				i_brace++;
			}
			if (line[i] == '}'){
                                i_brace--;
                        }

		}
	}

	/* Showcasing different error */	
	if( i_paren != 0 ){
		printf("Error: parenthisis missing\n");
	}
	if ( i_brack != 0 ){
		printf("Error: bracket missing\n");
	}
	if (i_brace != 0){
		printf("Error: brace missing\n");
	}
	if (i_brack == 0 && i_paren == 0 && i_brace == 0){
		printf("NO errors!\n");
	}
}
