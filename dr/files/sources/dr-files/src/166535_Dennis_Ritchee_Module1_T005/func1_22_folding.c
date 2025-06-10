/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000
#define WIDTH 10


void remove_space(int8_t s[],int8_t s1[]);
void folding() {
	int8_t sFold[MAXLINE], sTrim[MAXLINE];
    	int32_t c, index = 0, last_space = -1, start = 0;

    	getchar();  /* Consume any leftover newline*/
    	printf("Enter string -> \n");

    	/* Read input until newline (manual line input)*/
    	while ((c = getchar()) != '\n') {
        	sFold[index++] = c;
    	}
    	sFold[index] = '\0';

    	remove_space(sFold, sTrim);  /* Remove extra spaces*/

    	for (index = 0; sTrim[index] != '\0'; index++) {
        	if (sTrim[index] == ' ') {
        		last_space = index; /*Track the last space*/
        	}

        	/* If width limit is reached*/
        	if ((index - start) >= WIDTH) {
       			if (last_space != -1) {
                		sTrim[last_space] = '\n';  /* Replace space with newline*/
                		start = last_space + 1;    /* Move start index8*/
                		last_space = -1;           /* Reset space tracker*/
            		} 
			else {
                		sTrim[index] = '\n';  /*Forcefully break the word*/
                		start = index + 1;
            		}
        	}
    	}

    	printf("\nFolded Output:\n%s\n", sTrim);
}

void remove_space(int8_t s[],int8_t s1[]){
	int32_t i,j;
	_Bool flag=0;
	for(i=0,j=0;s[i] != '\0';i++){
		if (s[i] == ' ' || s[i] == '\t'){
			if(!flag){
				s1[j++] = ' ';
				flag=1;
			}
		}else{
			s1[j++]= s[i];
			flag=0;
	 	}
	}
	s1[j] = '\0';
}
