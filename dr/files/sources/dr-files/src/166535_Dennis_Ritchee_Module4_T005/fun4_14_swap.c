/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

/*defining marco to perform swap*/
#define SWAP(t,x,y) {t temp; temp = y; y = x; x = temp;}
void call_swap(){
	char iSwap1,iSwap2;
	/*getting user input*/
	printf("enter char:");
	getchar();
	scanf("%c",&iSwap1);
	printf("enter char:");
	scanf(" %c",&iSwap2);
	/*calling marco to swap the variable and passing type of argument*/
	SWAP(char,iSwap1,iSwap2);
	/*displaying the dersired output*/
	printf("swapped: value 1 = %c and value 2 = %c\n",iSwap1,iSwap2);
}
