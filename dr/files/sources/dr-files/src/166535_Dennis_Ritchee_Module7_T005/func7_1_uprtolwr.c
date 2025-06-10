/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>


#define MAX 100


void uppertolower_arg(int32_t argc,char *argv[]){
	if (argc < 2){
		printf("Usage: ./a_out <upper>|<lower>\n");
	}
	char string[MAX];
	int32_t index=0;
	printf("Enter string :");
	getchar();
	fgets(string, MAX, stdin);
	printf("User Input: %s\n",string);
	if (strcmp(argv[1],"upper") == 0){
		while(string[index] != '\0'){

			string[index] = toupper(string[index]);
			index++;
		
		}
	}
	else if (strcmp(argv[1],"lower") == 0){
		while(string[index] != '\0'){
			string[index] = tolower(string[index]);
                        index++;

                }
        }
	printf("Updated string : %s\n",string);

}
