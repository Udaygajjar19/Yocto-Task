/* REQUIRED HEADER FILES */
#include<stdio.h>
#include "main.h"
#include <stdint.h>

/* Function: Prints line word by word*/

void print_word(){
        /* Initializing variables */
	int8_t c,last=0;
	
	while((c = getchar()) != EOF){
		if ( (c == ' ') || (c == '\t') ){
			if ( ( last != ' ' ) && ( last != '\t' )){
				putchar('\n'); /* Print a newline when transitioning from a word to a space */
			}
			
		}
		else{
			putchar(c);		/* Prints only the word */
		}
		last=c;				/* Stores the last valueof c variable*/
	}
	
}
