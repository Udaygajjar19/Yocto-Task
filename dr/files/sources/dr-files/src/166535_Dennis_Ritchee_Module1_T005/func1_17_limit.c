/* REQUIRED HEADER FILES */
#include<stdio.h>
#include <stdint.h>
#include "main.h"

int my_getline(int8_t s[], int32_t lim);

/* DECLARING MARCOS */
#define MAXLINE 1000
#define ROW 100
#define LIMIT 8


/* MAIN PROGRAM */
void limit(){
        /* Declaring variable */
        int8_t line[ROW][MAXLINE],c;
	int32_t len[ROW]={0};
	int32_t i=0,j=0,k;
        printf("Enter line (press CTRL+D to exit): ");

        /* Its true if the length of the function getline is greater then 0 */
        getchar();
	while((c=getchar()) != EOF && (i<ROW)){
                /*checks if its within the limit or not*/
			
		/*checks for enter is pressed or not*/	
		if (c == '\n'){
			/*if enter is pressed then string is terminated and length is stored*/
			line[i][j]='\0';
			len[i]=j;
			i++;
			j=0;
			
		}
		/*else it will store line in 2D ARRAY*/
		else if (j< MAXLINE-1){
			line[i][j++] = c;
		}
		
	}
	/*number of line that execeds the limit*/
   	for (k = 0; k < i; k++) {
		if (len[k] > LIMIT) {
                        printf("Line %d exceeds %d characters:\n%s\n", k + 1, LIMIT, line[k]);
                        }
   	}	
}


void get_strbyline(int8_t line[][MAXLINE],int32_t i_row,int32_t len[]){
	int32_t i=0,j=0;
	int8_t c;
	while((c=getchar()) != EOF && (i<i_row)){
                /*checks if its within the limit or not*/

                /*checks for enter is pressed or not*/
                if (c == '\n'){
                        /*if enter is pressed then string is terminated and length is stored*/
                        line[i][j]='\0';
                       	len[i]=j;
			i++;
                        j=0;

                }
                /*else it will store line in 2D ARRAY*/
                else if (j< MAXLINE-1){
                        line[i][j++] = c;
                }

        }
}





/*
#include<stdio.h>
#include "main.h"

int my_getline(char s[], int lim){

        int c,i;
        for(i=0;i < lim-1 &&  (c=getchar()) != EOF && c != '\n'; i++ )
                s[i]=c;

        if( c == '\n' ){
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}*/
