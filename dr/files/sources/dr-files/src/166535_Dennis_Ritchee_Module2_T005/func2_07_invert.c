
/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 100
void call_invert(){
	while(1){
		/* inputing digit for  inverting , by using position of the bit and n for number of bits to be inverted  from the inputed position number*/
		int32_t i_value,i_pos,i_nbits, inverted;
		int8_t c;
		printf("Enter positive int value -> ");
		scanf("%d",&i_value);
		printf("Enter position -> ");
                scanf("%d",&i_pos);
		printf("Enter Enter number of bits to mask -> ");
                scanf("%d",&i_nbits);
		
		/*Calling function to get the value of it*/
		inverted = invert(i_value,i_pos,i_nbits);
		
		/*if the value is -one means the either of the input is negative*/
		if( inverted == -1 ){

			printf("Error: Negative values are not allowed");
		}

		/*if n is  less or equal to position+1 */
		else if (inverted == -2){

			printf("Error: n must be less than or equal to p+1");
		}

		/*printing the inverted bit value in integer*/
		else{
			printf("%d",inverted);
		}
		/*Asking user whether thry want to quit or not*/
		printf("\nEnter q to quit:");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }
	}
}




/* Function     -> This function is to invert the n bits from position p.
 * Author       -> Om Rathod
 * Created      -> 11 febuary 2025
 * Modified     -> 11 febuary 2025
 */
int32_t invert(int32_t x,int32_t p,int32_t n){
	/*value is negative then retunr -1*/
	if(x<0 || p < 0 || n < 0){
		return -1;
		
	}
	/*if does'nt match the condition then -2*/
	if(n > (p+1)){
		return -2;
		
	}

	/*returning the inverted value*/
	else
	{
		return x ^ (~(~0 << n) << (p + 1 - n));   
		}
	return 0;
	
}
