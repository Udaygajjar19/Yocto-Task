/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 100

/* Function     -> This function is call lower func
 * Author       -> Om Rathod
 * Created      -> 13 febuary 2025
 * Modified     -> 13 febuary 2025
 */
void call_lower_wo_if(){
	while(1){
		int8_t c;
		int8_t ch[MAXLINE];
		printf("Enter string -> ");
		scanf(" %[^\n]",ch);
		/*calling func to lower the input*/
		lower_wo_if(ch);
		printf("lowercase: %s \n",ch);
		/*Asking user whether thry want to quit or not*/
                printf("\nEnter q to quit:");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }
	}	
}

int32_t lower_wo_if(int8_t c[]){
	int32_t i;
	for(i=0;c[i] !='\0';i++){
		/*doing it using ternary operation*/
		c[i] = ((c[i] >= 'A') && (c[i]<= 'Z')) ? (c[i] + 'a' - 'A'):c[i];
	}
}

