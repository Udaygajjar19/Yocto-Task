
/* REQUIRED HEADER FILES */
#include<stdio.h>
#include "main.h"
#include <stdint.h>

/* REQUIRED MARCOS DELCLARATION */
#define IN 1	/* inside a word */
#define OUT 0	/* outside a word */

/* Function: Counts words, lines and char */

void cnt_word(){
	/* Initializing variables */
	uint8_t state,nl,nw,nc;
	int8_t c;
	/* Initializing state with 0 */
	state = OUT;
	nl=nw=nc=0;
	/* getting char from user untill CTRL+D */
	while((c = getchar() ) != EOF ){
		
		/* Counting char */
		nc++;
		if (c == '\n'){

			/*Counting lines*/
			nl++;
		}
		if ( (c == '\n') | (c == '\t') | (c == ' ') ){

			state = OUT;
		}
		/* if there is \n or \t or space then state is asigned to 0 and wordis counted */
		else if ( state == OUT ){
			/*Changing 0 to 1 ,to count the next word*/
			state = IN;
			/*Counting words*/
			nw++;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
