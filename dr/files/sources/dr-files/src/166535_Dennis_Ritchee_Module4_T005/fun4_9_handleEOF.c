/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<main.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000


void handleEOF(){
        int8_t cGet;
	
                getchar();
                /*Geting char using one buffer*/
                cGet = getch();
                /*Ungeting that char in ungetch*/
                ungetch(cGet);
		/*IF returned EOf then prind EOF done*/
		if (cGet == EOF){
			printf("EOF has been occurred");
		}
		else{
                printf("%c\n",cGet);
		}
	
}
