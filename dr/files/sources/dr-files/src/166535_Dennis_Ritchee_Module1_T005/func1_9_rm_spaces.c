/* REQUIRED HEADER FILES */
#include<stdio.h>
#include <stdint.h>
#include "main.h"


/* Function: removing extra spaces */
void rm_spaces(){
	/* Initializing last variable as NULL which store previos char of c variable */
	int8_t c,last='\0';

	/* getting char at a time untill there is EOF (i.e CTRL-D) */
	while ((c=getchar()) != EOF){
		
		/* if prev char is ' ' and c is also holding ' ' then it does'nt enter into if condition */
		if ( c != ' ' || last != ' '){
		
			/* If there is tab given in input then it skips it */
			if (c == '\t'){
				printf(" ");
				continue;
			}
		
			/* displays line when there is '\n' in input by removing extra spaces */
			putchar(c);
		}
		/* storing current value in last variable */
		last=c;		
	}
}
