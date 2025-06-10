
/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define BIT 32
void call_rightrot(){
	while(1){
		
		/* inputing interger for rotatomg , by n for number of bits to be rotated*/
                uint32_t i_nbits,result;
                int32_t i_value;
		int8_t c;
                printf("Enter positive int value -> ");
                scanf("%d",&i_value);
                printf("Enter Enter number of bits to mask -> ");
                scanf("%d",&i_nbits);

                /*Calling function to get the value of it*/
                result = rightrot(i_value,i_nbits);

                /*if the value is -one means the either of the input is negative*/
                if( result == -1 ){

                        printf("Error: Negative values are not allowed");
                }
                /*printing the rotated bit value in integer*/
                else{
                        printf("%u",result);
                }
                /*Asking user whether they want to quit or not*/
                printf("\nEnter q to quit:");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }
        }	
}


uint32_t rightrot(int32_t x, uint32_t n){
	/*if input is negative then return -1*/ 
	if(x<0){
		return -1;
		}
	else{
		/* lhs => shifting the x to right side
		 * rhs => shifting the x to left side to get the rotated bit at msb
		 * and then simply adding both the bits  */
		return (x >> n) | (x  << (BIT - n));
	}	

}
