/* REQUIRED HEADERS */
#include<stdio.h>
#include <stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000
#define ROW 100


void remove_check()
{
        /* Declaring variable */
        int32_t len[ROW];
	int32_t i;
        int8_t line[ROW][MAXLINE];
        /* if length of line is greater than 0 then it will be true */
        printf("Enter string to reverse it (press CTRl+d to teminate): \n");
	getchar();
	get_strbyline(line,ROW,len);
	/*while((len = my_getline(line,MAXLINE))>0){
         */        /* removing trailing tabs and  spaces*/
           /*     remove_trail_blanks(line,len);
                printf("[%s]\n", line);
        }*/

	for(i=0;i<ROW;i++){
		if (line[i][0] == '\0'){
			break;
		}
		int8_t s_str_copy[MAXLINE];
		int32_t i_len;
		
		manual_copy(s_str_copy,line[i],MAXLINE);
		printf("copy: %s",s_str_copy);
		i_len = len[i];
		i_len++;
		remove_trail_blanks(s_str_copy,i_len);
		printf("[%s]\n",s_str_copy);
	}


}


void remove_trail_blanks(int8_t line[],int32_t l){
	int32_t i;
	/* removes the extra spaces */
	for(i=(l-2);i>=0 && (line[i] == ' ' || line[i] == '\t');i--)
		;
		
	line[i+1]= '\0';
}

void manual_copy(int8_t *dest, int8_t *src, int32_t max_size) {
    int32_t i;
    for (i = 0; i < max_size - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';  // Ensure null termination
}
