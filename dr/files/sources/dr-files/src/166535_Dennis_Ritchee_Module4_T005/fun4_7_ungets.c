/* REQUIRED HEADERS */
#define MAXLINE 1000

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "main.h"

void call_ungets(){
	int8_t cInput,sGetstr[MAXLINE];
	int32_t iIndex=0;
	/*Getting user input*/
	while((cInput=getchar()) != EOF ){
		sGetstr[iIndex++] = cInput;
	
	}
	/*terminatining the string*/
	sGetstr[iIndex++] = '\0';
	/*Calling the ungets func*/
	ungets(sGetstr);
	/*printing the pushed */
	printf("%s",sGetstr);
}


void ungets(int8_t s[]){
	/*geting string length*/
	int32_t iLength = strlen((char *)s);
	/*ungetingch till length is 0*/
	while(iLength >0){
		ungetch(s[--iLength]);
	}
	
}
