/* REQUIRED HEADER FILES */

#include<stdio.h>
#include <stdint.h>
#include "main.h"


/* DECLARING MARCOS */
#define MAXLINE 1000

//int my_getline(char s[], int lim);
//void copy(char to[], char from[]);

/* MAIN PROGRAM */
void longest(){
        /* Declaring variables */
        uint16_t ulen;
        uint16_t umax=0;
        int8_t line[MAXLINE];
        int8_t longest[MAXLINE];
        printf("Enter line (press CTRL+D to exit): ");

        /* Its true if the length of the function getline is greater then 0 */
        while((ulen = my_getline(line,MAXLINE))>0){
                /* if lenght id greater than the max lenght then enters in if nest */
                if (ulen > umax){
                        umax = ulen;
                        /* copies to the longest string */
                        copy(longest,line);
                }
        }
        if (umax>0){
                /* printing maximum length line */
                printf("Longest line length: %d\n", umax);
                printf("%s\n",longest);
        }

}
/*----------------------------------------------------------------------------*/


/*
 * Description  -> Function for getting line to return length of it
 * Author       -> Om Rathod
 * Created      -> 1 febuary 2025
 * Modified     -> 1 febuary 2025
 */

/* REQUIRED HEADER FILES */
#include<stdio.h>
#include "main.h"

/* FUCNCTION: Reads line to get length of it */
int32_t my_getline(int8_t *s, int32_t lim){

	int32_t c,i;
	/* Checks if its within lim and gets char till its not equal to \n */
	for(i=0;i < lim-1 &&  (c=getchar()) != EOF && c != '\n'; i++ )
		/*Store the char in the string*/
		*(s+i)=c;
	
	if( c == '\n' ){
		/* stores string with newline */
		*(s+i) = c;
		++i;
	}
	/* ending string with null */
	*(s+i) = '\0';
	return i;
}

/*-----------------------------------------------------------------------------*/


void copy(int8_t to[], int8_t from[]){
	int8_t i=0;
	/* Copies till there is null in string */
	while ((to[i]=from[i]) != '\0' ){
		++i;
	}
	to[i] = '\0';
}
