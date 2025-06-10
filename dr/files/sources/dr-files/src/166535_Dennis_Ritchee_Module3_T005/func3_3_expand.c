
/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

/* Function     -> This function is call escape(s,t) func
 * Author       -> Om Rathod
 * Created      -> 13 febuary 2025
 * Modified     -> 13 febuary 2025
 */
void call_expand(){
	int8_t s1[MAXLINE],s2[MAXLINE];
	        while(1){
                int8_t c;
                printf("Enter string -> ");
                scanf(" %[^\n]",s1);

                /*calling the expand function*/
		expand(s1,s2);
		printf("%s\n",s2);
        printf("press 'q' to quit program(press any key to continue) ->");
        scanf(" %c", &c);
        if (c == 'q'){
                break;
        }
}
}


void expand(int8_t s1[],int8_t s2[]){
	int32_t i=0,j=0;
	int8_t start,end;
	while(s1[i] != '\0')
	{
		if ((s1[i] == '-') && (s1[i-1] == s1[i+1])) {
    			i += 2;
		      		/* Skip the '-' and move forward*/
 	 		continue;
		}

		/*this is to check for forward expand*/
		if( (s1[i] == '-') && (i>0) && (s1[i+1] != '\0') && (s1[i-1] < s1[i+1]) ){
			/*initializing start and end*/
			start = s1[i-1] +1;
			end = s1[i+1];	
			while(start <= end ){
				s2[j++]	 = start++;
			}
			i++;
		}
		/*this is to check for backward expand*/
		else if ( (s1[i] == '-') && (i>0) && (s1[i+1] != '\0') && (s1[i-1] > s1[i+1]) ){
			/*initializing start and end*/
			start = s1[i-1] - 1;
                        end = s1[i+1];
                        while(start >= end ){
                                s2[j++]  = start--;
                        }
			i++;
		}
		else{
			/* storing same char if did'nt matched */
			s2[j++] = s1[i];
		}
		i++;

	}
	s2[j] = '\0';
}


