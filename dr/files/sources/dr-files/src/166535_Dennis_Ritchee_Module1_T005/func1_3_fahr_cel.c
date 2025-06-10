/* REQUIRED HEADER FILES */
#include<stdio.h>
#include "main.h"

/* FUCNCTION */
void fahr_cel(){
	float fahr,cel;		/* Initializing variables */
	float low,up,step;
	up=300;			/* Upper limit */
	low=0;			/* lower limit of temperatuire scale */
	step=20;		/*Step Size*/
	fahr=low;
	/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version */
	printf("FAHRENHEIT\t|\tCELSIUS\n");	/* Giving header to the table */
	printf("-----------------------------------\n");
	while (fahr <= up){
		/* Formula to convert fahrenheit to celsius */
		cel = (5.0/9.0) * (fahr-32.0);
		printf("| %3.0f \t\t|\t %6.2f |\n",fahr,cel);
		/*Increamenting stepwise*/
		fahr += step;
	}
}
