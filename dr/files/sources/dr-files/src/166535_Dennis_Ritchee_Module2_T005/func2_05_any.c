/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

#define MAXLINE 100
void call_any(){
	int32_t i_index;

	int8_t c,str_main[MAXLINE],str_rm[MAXLINE];
        while(1){

                /*Getting string as a input execept \n*/
                printf("Enter string 1 -> ");
                scanf(" %[^\n]",str_main);
                printf("\nEnter string 2 -> ");
                scanf(" %[^\n]",str_rm);

                /*calling function to change the uppercase to lowercase*/
                lowercase(str_main);
                lowercase(str_rm);

                /* calling function to get index match the number*/
		i_index = any(str_main,str_rm);
                
		if(i_index == -1){
			printf("string 1 does'nt match the char of string 2\n");
		}
		else{
		printf("matched char at index -> %d\n",i_index);
		}
                /*Asking user whether thry want to quit or not*/
                printf("\nEnter q to quit:");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }
        }
}




int32_t any(int8_t s1[],int8_t s2[]){
	uint16_t i,j;
	uint8_t FLAG=0;
	/* checking char by char string 1 with string 2 */
	for(i=0;s1[i] != '\0';i++){
		for(j=0;s2[j] != '\0';j++){

			/* when it gets matched then returns the current index 
			 * then it sets the flag and breaks*/
			if (s1[i] == s2[j]) {
				return i;
				FLAG = 1;
				break;
			}
		}

		/* if flag is 1 then break it */
		if(FLAG){
			break;
		}
	}
	/*if there is no match then the flag remains 0*/
	if(!FLAG){
		return -1;
	}
	return 0;

}
