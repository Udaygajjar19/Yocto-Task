
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000


void test_ptr_function(){
	int8_t string[MAXLINE];
	printf("Enter string -> ");
	int32_t Length;
	getchar();
	Length = my_getline(string,MAXLINE);
	
	reverses(string);

	printf("%s\n",string);
	//printf("length is %d",Length);
	
	int32_t n;
	printf("Enter number -> ");
	scanf(" %d",&n);
	/*calling the function*/
	itoa(n,string);
	printf("%s\n",string);


}
