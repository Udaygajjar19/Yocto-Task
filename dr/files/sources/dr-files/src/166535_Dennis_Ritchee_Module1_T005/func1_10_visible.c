/* REQUIRED HEADER FILES */
#include<stdio.h>
#include <stdint.h>
#include "main.h"


/* Function: replaces each tab by \t, each backspace by \b, and each backslash by \\ */
void visible(){
	int8_t c;
	/* taking single char at a time */
	while ((c = getchar()) != EOF){
		if (c  == '\b'){	/* Checking if there is backpace */
			printf("\\b");
		}
		else if ( c  == '\t' ){	/* Checking if there is tab */
			printf("\\t");
		}

		else if (c  == '\\'){	/* Checking if there is \ */
			printf("\\\\");
                }
		else{
			putchar(c); 	/* displaying output */
		}
	}
}
