/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
void call_bitcnt(){
	while(1){
		int8_t c;
		int32_t i_result;
		uint32_t i_num;
		printf("Enter number -> ");
		scanf("%u",&i_num);
		i_result = bitcnt(i_num);
		printf("bit counts: %d\n",i_result);
		/*Asking user whether thry want to quit or not*/
                printf("\nEnter q to quit:");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }

	}
}

int32_t bitcnt(uint32_t x){
	int32_t i;
	/* counts the set bits in an integer */
	for(i=0;x !=0;x &= (x-1)){
		i++;
	}
	return i;
}

