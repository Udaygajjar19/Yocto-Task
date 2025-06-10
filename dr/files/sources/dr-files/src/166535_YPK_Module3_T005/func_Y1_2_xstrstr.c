/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000



void call_xstrstr(){
        char Main_str[MAXLINE];
        char Search_str[MAXLINE];
        /*Taking user input*/
        printf("Enter String 1: ");
        getchar();
        scanf("%[^\n]",Main_str);
	getchar();
	printf("Enter String 2: ");
        scanf("%[^\n]",Search_str);
	/* storing the returned value of func to Matched*/
	char *Matched = xstrstr(Main_str,Search_str);

	/*if matched is not null then prints where the string is matched*/

	if (Matched != NULL){
		printf("matched string 2 at %s\naddress: %p\n",Matched,Matched);
	}
	else{
		printf("Error: match is not Found\n");
	}

}

char * xstrstr (char *string1,char *string2){
	int Count=0;
	/*making string2 copy to check it string 1*/
	char *string2_copy=string2;
	while(*string1 != '\0'){
		/*comparing string 1 and string 2*/
		while(*string1 == *string2_copy){
			string2_copy++;
			Count++;
			string1++;
		}
		/*If the 2nd string is matched then return the addresss of first char of str2*/
		if(*string2_copy == '\0'){
			return (string1-Count);
		}
		
		/*if count is 0 then string is increamented*/
		if(!Count){
			string1++;	
		}
		/*Reseting the count and string 2*/
		Count=0;
		string2_copy=string2;
		
	}
	return NULL;
}
