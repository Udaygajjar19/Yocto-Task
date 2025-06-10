/* REQUIRED HEADER FILES */
#include<stdio.h>
#include "main.h"
#include <stdint.h>

/* Function: counts blanks,tabs and newlines */
void cnt_all()
{
	int8_t c, blanks=0,tabs=0,newline=0;
	while((c=getchar()) != EOF){ 		/* Getting char till there is EOF */
		if (c == ' '){			/* Checking for Whitespaces */
			blanks++;
		}
		if( c == '\t'){			/* Checking for tabs */
			tabs++;	
		}
		if (c == '\n'){			/* Checking for newlines */
			newline++;
		}

	}

	/* printing all the counts */
	printf("number of white spaces are -> %d\n",blanks);
        printf("number of tabs are -> %d\n",tabs);
        printf("number of new lines  are -> %d\n",newline);
}
