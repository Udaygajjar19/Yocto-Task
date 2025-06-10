/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000



void call_xstrchr(){
        char Main_str[MAXLINE];
        char Search_ch;
        /*Taking user input*/
	printf("Enter String: ");
        getchar();
	scanf("%[^\n]", Main_str);
        printf("\nEnter character to find: ");
        getchar();
        Search_ch = getchar();
	/*storing output in variable pointer*/
        char *Matched = xstrchr(Main_str, Search_ch);

	/*if return pointer is null then return Error char not found else print char matched*/
        if( Matched != NULL){
		printf("Matched = %c\n", *Matched);
	}
	else{
		printf("Error:char Entered was'nt found\n");
	}
        //printf("re = %p\n", re);
}

char* xstrchr(char* string, char ch){
        /*checking string char by char to match with another char*/
	while(*string != '\0'){
		/*if char is matched then returning that string address*/
                if(*string == ch){
                        //*string = 'b';
                        return string;
                }else{
                        string++;
                }
        }
	/*If char no matched then return NULL*/
        return NULL;
}
