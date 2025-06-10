
/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

void call_recursive_itoa(){
	/*Initializing variables*/
	int32_t iNumber;
	int8_t cItoStr[MAXLINE];
	getchar();
	/*Getting user input*/
	printf("Enter number -> ");
	scanf("%d",&iNumber);
	/*calling the function*/
	recursive_itoa(iNumber,cItoStr);
	printf("%s\n",cItoStr);
}


void recursive_itoa(int32_t n,int8_t s[]){
	static int32_t iIndex=0;
	/*if negative then store - in string*/
	if (n<0){
		s[iIndex++]= '-';
		n = -n;
	}
	/*it will run till n is divisible by 10*/
	if(n/10){
		recursive_itoa((n/10),s);
	}
	/*after failing the condition number is stored in the string*/
		s[iIndex++] = (n%10) + '0';
	
	s[iIndex]= '\0';
}
