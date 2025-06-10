/* REQUIRED HEADER FILES */
#include<stdio.h>
#include <stdint.h>
#include "main.h"

/* FUCNCTION:celcius to fahrenheit conversion */
void cel_fahr1(){
        float fahr;             /* Declaring variable */
	uint16_t i;
	printf("CELSIUS\t|\tFAHRENHEIT\n");     /* Giving header to the table */
        printf("-----------------------------------\n");
	for(i=300;i>=0;i-=20){
        /* Formula to convert celsuis to fahrenheit */
        fahr = (9.0/5.0) * i + 32;
	/*Printing the value of Fahr obtained from formula*/
        printf("%3.2d \t|\t %3.2f\n",i,fahr);
	
	}
}


