/* REQUIRED HEADERS */

#include<stdio.h>
#include<main.h>
#include<math.h>
#include<stdint.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000

void one_getch(){
	int8_t cGet;
		getchar();
		/*Geting char using one buffer*/
		cGet = getch();
		/*Ungeting that char in ungetch*/
		ungetch(cGet);
		printf("%c\n",cGet);
		
}
