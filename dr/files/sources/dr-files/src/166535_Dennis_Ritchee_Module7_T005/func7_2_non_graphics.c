/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#define MAX 100


void non_graphic(){
	char string[MAX],c;
	getchar();
	printf("enter string: ");
	int32_t index1=0;
	while((c = getchar()) != EOF){
		string[index1] = c;
		index1++;
	}
	int32_t index=0;
	while (string[index] != '\0'){
		if (!isprint(string[index])){
			printf("[%x %o]",string[index],string[index]);	
		}
		else{
			printf("%c",string[index]);
		
		}
		index++;
	}
	printf("\n");
}
