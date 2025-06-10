/* REQUIRED HEADER FILES */
#include<stdio.h>
#include <stdint.h>
#include "main.h"

/* REQUIRED MARCOS*/
#define MAXLINE 100

/* Function: plots histogram of word length */

void histogram_hor(){
        /* Initializing variables */
	int8_t c,istate=0;
	int32_t WordLength[MAXLINE]= {0};
	int8_t s_main_str[MAXLINE];
	int32_t icnt=0,i=0,j;
	getchar();
	printf("Enter string :\n");

	/*storint input in string*/
        while((c = getchar()) != EOF){
		s_main_str[i]=c;
		i++;
	}
	s_main_str[i]='\0';

	for(i=0;s_main_str[i] != '\0';i++){

		/*if there is any space or tab or newline then it will store the length of word in array*/
                if ( (s_main_str[i] == ' ') || (s_main_str[i] == '\t') || (s_main_str[i] == '\n') ){
			if(istate){
                        	WordLength[icnt]++;
                	}
			
                        icnt=0;
			istate = 0; 	
                        }
                
		/*counts the word */
                else{
			icnt++;
			istate=1;
                }
	}
		printf("\n---------------------------horizontal histogram------------------------------\n");
		/*prints histogram horizontal*/
		for(i=0;i<MAXLINE;i++){
			if(WordLength[i] > 0){
				printf("%3d |",i);
				for(j=0;j<WordLength[i];j++){
					printf(" * ");
				}
			printf("\n");
			}

		}
		printf("\n---------------------------vertical histogram------------------------------\n");
		int32_t imax=0;
		/*finding max occurance of same length word*/
		for(i=0;i<MAXLINE;i++){
			if(imax < WordLength[i]){
				imax= WordLength[i];
			}
		}
		/*decreamenting the for loop*/
		for(i=imax;i>0;i--){
			
			/*operating the length array of word*/
			for(j=0;j<MAXLINE;j++){
			/*if element is non zero then only it will print*/
			if(WordLength[j] > 0 ){
				/*it will only print * if element is greater than i */
				if(WordLength[j] >= i){
					printf(" * ");
				}
				else{
					printf("   ");
				}
			}
			}
			printf("\n");

		}
		/*printing the index of the array*/
		for(i=0;i<MAXLINE;i++){
                        if(WordLength[i] > 0){
                                      
                                printf(" %d ",i);
                                
                        //printf("\n");
                        }

                }

}


