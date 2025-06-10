/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 100

void call_itoapad(){
        int32_t n,i_width;
        int8_t c,s[MAXLINE];
        while(1){
                printf("Enter number -> ");
                scanf("%d",&n);
		printf("Enter number -> ");
                scanf("%d",&i_width);
                /*calling the function*/
                itoapad(n,s,i_width);
                printf("%s\n",s);


                printf("press 'q' to quit program(press any key to continue) ->");
                scanf(" %c", &c);
                if (c == 'q'){
                        break;
                }
        }

}


void itoapad(int32_t n, int8_t s[],int32_t w){
        int32_t i,sign;
        sign = n;
        /*storing largest negative int unsigned datatype and giving negative sign*/
        uint32_t num = (n<0) ? -((uint32_t)n) : n;
        i = 0;

        /*converting integer to string*/
        do{
                s[i++] = num % 10 + '0';
        }while((num/=10) > 0);
	/* if width is greater than the index of string then it will print spaces */
	while(w > i){
		s[i++] = ' ';
	}
        if (sign < 0){
                s[i++] = '-';
        }
        s[i] = '\0';
        reverses(s);
}
