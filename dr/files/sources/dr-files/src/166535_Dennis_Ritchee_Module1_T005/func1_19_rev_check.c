/* REQUIRED HEADERS */
#include<stdio.h>
#include <stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000
#define ROW 100

int my_getline(int8_t s[], int32_t lim);
void reverse(int8_t line[], int32_t l);


void rev_check()
{
        /* Declaring variable */
        int32_t len[ROW],i;
        int8_t line[ROW][MAXLINE];
        printf("Enter string to reverse it (press CTRl+d to teminate): \n");
        /* if length of line is greater than 0 then it will be true */
	getchar();
        get_strbyline(line,ROW,len);        
	for(i=0;i<ROW;i++){
                if (line[i][0] == '\0'){
                        break;
                }
                int8_t s_str_copy[MAXLINE];
                int32_t i_len;
                manual_copy(s_str_copy,line[i],MAXLINE);
                i_len = len[i];
		i_len++;
                //remove_trail_blanks(s_str_copy,i_len);
		/* calling function to reverse the input */        
		reverse(s_str_copy,i_len);
                //printf("%s\n",s_str_copy);

        }

}



/*---------------------------------------------------------------------------------*/


/* REQUIRED HEADER FILES */
/*
#include<stdio.h>
#include "main.h"

#define MAXLINE 1000

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
}
*/

/* ------------------------------------------------------------------------------ */

/*
 * Description  -> Function for reversing the input
 * Author       -> Om Rathod
 * Created      -> 3 febuary 2025
 * Modified     -> 3 febuary 2025
 */


void reverse(int8_t line[],int32_t l){
	/* Initializing rev[] to store the revesed string */
	int8_t rev[MAXLINE];
	uint8_t i;
	for(i=0;i<(l-1);i++){
		/* stores last value of line string to the first value of rev */
		rev[i]=line[l-2-i];
	}
		/* storing \n into last second position */
	        rev[i] = '\n';
		/* Terminating the reversed string with \0 */
                rev[i+1] = '\0';

		printf("%s",rev);
}
