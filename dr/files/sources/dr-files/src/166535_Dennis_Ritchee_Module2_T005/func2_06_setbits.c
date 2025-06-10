/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 100

void call_setbits(){
	while(1){
                /* inputing digit for  seting bit , by using position of the bit and n for number of bits */
                int16_t i_value1,i_value,i_pos,i_nbits, setbit;
                int8_t c;
                printf("Enter positive int value 1-> ");
                scanf("%hd",&i_value);
		printf("Enter positive int value 2-> ");
                scanf("%hd",&i_value1);
                printf("Enter position -> ");
                scanf("%hd",&i_pos);
                printf("Enter Enter number of bits to mask -> ");
                scanf("%hd",&i_nbits);

                /*Calling function to get the value of it*/
                setbit = setbits(i_value,i_pos,i_nbits,i_value1);

                /*if the value is -one means the either of the input is negative*/
                if( setbit == -1 ){

                        printf("Error: Negative values are not allowed");
                }

                /*if n is  less or equal to position+1 */
                else if (setbit == -2){

                        printf("Error: n must be less than or equal to p+1");
                }

                /*printing the setbit bit value in integer*/
                else{
                        printf("%d",setbit);
                }
                /*Asking user whether thry want to quit or not*/
                printf("\nEnter q to quit(press any key to continue):");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }
        }	
}



int32_t setbits(int16_t x,int16_t p,int16_t n,int16_t y){
	/*value is negative then retunr -1*/
        if(x<0 || p < 0 || n < 0 || y < 0 ){
                return -1;

        }
        /*if does'nt match the condition then -2*/
        if(n > (p+1)){
                return -2;

        }

        /* return the set value of x */
        else
	{
		int16_t clr,extract;
		/* clearing the n bits in x at postion p */
		clr = x &  ~(~(~0 << n) <<  (p+1-n));
		/* Extracting the rightmost n bits from y and placing at p*/
		extract=  (y & ~(~0 << n)) <<  (p+1-n);      		
		return (clr | extract);
                }
        return 0;	
}



















