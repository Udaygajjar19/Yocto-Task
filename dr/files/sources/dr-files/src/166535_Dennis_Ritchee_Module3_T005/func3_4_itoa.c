/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

void call_itoa(){
	int32_t n;
	int8_t c,s[MAXLINE];
	getchar();
	//getchar();
	while(1){
		printf("Enter number -> ");
                scanf("%d",&n);
		/*calling the function*/
		itoa(n,s);
		printf("%s\n",s);


		printf("press 'q' to quit program(press any key to continue) ->");
		scanf(" %c", &c);
		if (c == 'q'){
			break;
		}
	}

}


void itoa(int32_t n, int8_t *s){
	int32_t i,sign;
	sign = n;

	/*storing largest negative int unsigned datatype and giving negative sign*/
	uint32_t num = (n<0) ? -((uint32_t)n) : n;
	i = 0;
	/*converting integer to string*/
	do{
		*(s+i) = num % 10 + '0';
		i++;
	}while((num/=10) > 0);
	if (sign < 0){
		*(s+i) = '-';
		i++;
	}
	*(s+i) = '\0';
	reverses(s);
}
