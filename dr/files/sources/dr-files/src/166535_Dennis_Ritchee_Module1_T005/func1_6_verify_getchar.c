/* REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdint.h>
#include "main.h"
void verify_getchar(){                                                  
	int8_t c;                                                          
	c = (getchar() != EOF);
	printf("%d",c);
}
