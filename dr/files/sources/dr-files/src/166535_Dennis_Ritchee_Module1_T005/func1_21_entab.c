/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define TAB 8


void remove_space2tab(){
	int8_t c;
	uint8_t i_position=0,i_space=0;

	while((c=getchar()) != EOF ){
		i_position++;
		if (c == ' '){
			i_space++;
			if (i_position % TAB == 0){
				putchar('\t');
				i_space=0;
			}
		}
		else {
			while(i_space>0){
				putchar(' ');
				i_space--;
			}
			if ( c == '\n'){
				i_position=0;
			}
			putchar(c);
		}
	}
}
