/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000


void call_str_library(){
	char main_string[MAXLINE],compare_string[MAXLINE];
	while(1){
		/*taking user input*/
		printf("Enter string-> ");
		scanf(" %[^\n]",main_string);
		printf("Enter string-> ");
		scanf(" %[^\n]",compare_string);
		/*storing return value in the result*/
		strncpy(compare_string,main_string,2);
		printf("string copied is :%s\n",compare_string);
		strncat(main_string,compare_string,5);
		printf("string concated is :%s\n",main_string);
		int32_t result = strncmp(main_string,compare_string,100);
		printf("strncmp return value is %d\n",result);

		//printf("strcmp return value is %d\n",strcmp(main_string,compare_string));
		printf("press q to quit:");
		getchar();
		if(getchar() == 'q'){
			break;
		}
	}			
}


char *strncpy(char *dest,const char *src,size_t n){
	int32_t index;
	/*it will copy the src string to dest with n char only*/
	for(index =0;index<n && *(src + index) != '\0';index++){
		*(dest+index) = *(src+index);
	}
	while (index < n) { 
		/* Fill the remaining with null if n > src length*/
        	*(dest+index) = '\0';
		index++;
    	}
	return dest;
}


char *strncat(char *dest,const char *src,size_t n){
	int32_t Count=0;
	/* reaching to the NULL */
	while(*(dest++));
	dest--;
	/* adding the src string after dest string */
	while( (*(dest++) = *(src++)) && (Count++ != n));
	/*terminating with null*/
	*dest = '\0';
	return dest;

}


int32_t strncmp(const char *str1, const char *str2, size_t n){
	int32_t index;
	/* it will compare untill n char */
	for(index=0;index<n;index++){
		/* if char is not same then returns char ascii difference */
		if(*(str1+index) != *(str2+index)  || *(str1+index) == '\0' || *(str2+index) == '\0' ){
			return *(str1+index) - *(str2+index);	
		}
	}
	return 0;
}

