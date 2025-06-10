/* REQUIRED HEADER FILES */

#include<stdio.h>
#include <stdint.h>
#include "main.h"
/* FUCNCTION:celcius to fahrenheit conversion */
void cel_fahr(float cel){
	float fahr;		/* Declaring variable */
	/* Formula to convert celsuis to fahrenheit */
	fahr = (9.0/5.0) * cel + 32;
	/*Printing the value of Fahr obtained from formula*/
	printf("the value in fahrenheit is : %3.2f",fahr);
	
}




/* Function to validate integer input */
int valid_input() {
    int32_t n;
    int8_t ch;

    while (1) {  /* Keep asking until valid input is entered */
        printf("Enter value: ");
        if (scanf("%d", &n) == 1) {
            return n;  /* Return the valid integer */
        } else {
            printf("Error: Please enter a valid number.\n");

            /* Clear the input buffer */
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}
