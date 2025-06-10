/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"
#include<string.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000
 /*
 * Function     -> This function is to call reverse recursvive
 * Author       -> Om Rathod
 * Created      -> 27 febuary 2025
 * Modified     -> 27 febuary 2025
 */

void call_recursive_rev(){
	/*Initializing variables*/
	int8_t sMainstr[MAXLINE];	
	int8_t rev[MAXLINE];
	getchar();
	/*Getting user input*/
	scanf("%[^\n]",sMainstr);
	/*calling the function*/
	recursive_reverse(sMainstr,rev,0);
	printf("reverse: %s\n",rev);
}



void recursive_reverse(int8_t s[],int8_t rev[],int32_t iIndex)
{
	/*Getting string legth */
	int32_t iLen=strlen((char *)s);
	/*length is greater than index then reverse*/
	if ( iIndex < iLen){
		/*putting last index to the first and recursively calling it*/
		rev[iIndex] = s[iLen-1-iIndex];
		recursive_reverse(s,rev,iIndex+1);
	}
	else{
		/*at the end terminate it*/
		rev[iIndex] = '\0';
	}
	
}





