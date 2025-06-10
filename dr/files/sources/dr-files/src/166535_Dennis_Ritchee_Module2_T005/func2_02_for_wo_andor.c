/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 10

void for_wo_andor(){
	uint16_t i;
	int16_t c;
	int8_t s[MAXLINE];
	printf("Enter string:");
	/*getting char*/
	for(i=0;(c=getchar()) != '\n';++i){
		/*if there is end of file*/
		if(c != EOF){
			/*if its within the range*/
			if(i < MAXLINE-1){
				s[i]=c;
			}	
	}
	}
	/*print the value of string*/
	printf("%s\n",s);
}
