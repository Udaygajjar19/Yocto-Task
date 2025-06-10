/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000


void call_strend(){
	int8_t main_string[MAXLINE],compare_string[MAXLINE];
while(1){
	/*taking user input*/
	printf("Enter string-> ");
	scanf(" %[^\n]",main_string);
	printf("Enter string-> ");
        scanf(" %[^\n]",compare_string);
	/*storing return value in the result*/
	int32_t result = Strend(main_string,compare_string);
	printf("string end function return value is %d\n",result);
	printf("press q to quit:");
	getchar();
	if(getchar() == 'q'){
		break;
	}

}
}


int32_t Strend(int8_t *s,int8_t *t){
	/*checking if the main string is less than the 2nd string*/
	if( strlen((char *)s) < strlen((char *)t) ){
		return 0;
	}

	else{
		/*reaching at the terminating point for both strings*/
		while(*(s++));
		while(*(t++));
		s--;
		t--;
		/*checking with the reversed string it will run untill char is matched*/
		while( (*(s--) == *(t--))  ){
			/* as soon as space is counter it return 1 as last word is matched */
			if(*s == ' ')
				return 1;
		}
		/*if the it does'nt matches than return 0*/
		return 0;
	}
}



