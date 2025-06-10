/* REQUIRED HEADER FILES */
#include<stdio.h>
#include <stdint.h>
#include "main.h"

/* DECLARATION OF MARCOS */
#define CHAR_NR 128

/* FUNCTION: This function is to print a freq histogram */

void histogram_f(){
        /* Initializing variables */
	int8_t c;
	uint8_t i;
	uint16_t freq[CHAR_NR] = {0};
	int32_t irow=0,imax_freq=0;
	/* Taking char from user */
	printf("Enter string: \n");
	getchar();
	while((c = getchar()) != EOF){
		if (c >= 0 && c < CHAR_NR){
			/* If its within the ASCII char it counts and increased */

			++freq[c];	
		}
	}
	
	
	printf("----------------horizontal-------------------\n");
		for (i=0;i<CHAR_NR;i++){
		if (freq[i]> 0){ /* IF appeared in input */
			if (i >= 33 && i<=126){
				/* if char is printable */
                		printf(" %c ", i);
			}
			else if (i == '\t') {
                		printf("\\t ");  

            		}
			else if (i == '\n') {
                                printf("\\n ");
                        }
			else if (i == ' ') {
                                printf("\\s ");
                        }
			/*Else it will print ASCII number*/
			else {
			printf("ASCII %d ",i);	
			}
		int j;
		for (j=0; j<freq[i];j++){
			printf("*"); /* prints repeated chars*/
		}
		printf("\n");
		}
        }
	printf("------------------vertical-------------------------\n");
	for (i=0;i< CHAR_NR;i++){
		if(freq[i] > imax_freq){
			imax_freq = freq[i];
		}
	}	
	for(irow = imax_freq;irow>0;irow--){
		for(i=0;i<CHAR_NR;i++){
			if(freq[i] > 0){
				if (freq[i] >= irow) {
					printf(" * ");
				} else {
					printf("   ");
			}
			}
		}
		printf("\n");
	}
	

	for (i=0;i<CHAR_NR;i++){
                if (freq[i]> 0){ /* IF appeared in input */
                        if (i >= 33 && i<=126){
                                /* if char is printable */
                                printf(" %c ", i);
                        }
                        else if (i == '\t') {
                                printf("\\t ");

                        }
                        else if (i == '\n') {
                                printf("\\n ");
                        }
                        else if (i == ' ') {
                                printf("\\s ");
                        }
                        /*Else it will print ASCII number*/
                        else {	
                        printf(" %d ",i);
                        }
			}
			
	}
        
       	printf("\n");
}

