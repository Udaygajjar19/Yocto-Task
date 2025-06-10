
/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"
#include <ctype.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000

void call_strcat(){
	char string_1[MAXLINE],string_2[MAXLINE];
	/*taking user input*/
	printf("Enter string 1 -> ");
	scanf(" %[^\n]",string_1);
	printf("Enter string 2 -> ");
	scanf(" %[^\n]",string_2);
	/*concating the two string*/
	Strcat(string_1,string_2);
	printf("%s\n",string_1);
}




void Strcat(char *s,char *t){
	/*first loop will traverse untill it becomes 0*/
	while(*s){
		s++;
	}
	/*after reaching at the end of string append 2nd string to it untill the secont string becomes 0*/
	while(((*s++) = (*t++))){
		
	}
}

