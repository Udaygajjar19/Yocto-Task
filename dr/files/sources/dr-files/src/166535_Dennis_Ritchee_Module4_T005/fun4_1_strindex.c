/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000
void call_index(){
	int8_t str[MAXLINE],str1[MAXLINE];
	int32_t result;  
	while(1){
                int8_t c;
                printf("Enter string 1 -> ");
                scanf(" %[^\n]",str);
		printf("Enter string 2 -> ");
		scanf(" %[^\n]",str1);

		/*calling the strindex function*/
                result = strindex(str,str1);
		/*displaying the index*/
		if (result != -1){
                        printf("index is at %d\n",result);
                }
		/* if returns -1 then display didnt found */
                else{
                        printf("string did'nt matched\n");
                }
        printf("press 'q' to quit program(press any key to continue) ->");
        scanf(" %c", &c);
        if (c == 'q'){
                break;
        }	
}
}
int32_t strindex(int8_t *s, int8_t *t){
	int32_t i,j,k;
	/*lowercasing both the input string*/
	lowercase(s);
	lowercase(t);
	/*to get the rightmost match starting from end the string*/
	for(i=strlen(s);i>=0;i--){

		/*if it gets match then continues the loop*/
		for(j=i,k=0;(*(t+k) != '\0') && (*(s+j)== *(t+k));j++,k++ );
		/* if greater than and string is terminated then return index */
		if ( (k>0) && *(t+k) == '\0'){
			return (i+1);
		}
	}
	return -1;
}
