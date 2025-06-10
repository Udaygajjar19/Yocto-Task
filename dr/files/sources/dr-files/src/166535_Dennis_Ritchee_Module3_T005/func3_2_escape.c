/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

void call_escape(){
	int8_t str1[MAXLINE],c;
	int32_t i=0;
	getchar();
	printf("Enter string ->");
	while((c=getchar()) != EOF){
		str1[i++]=c;
	}
	str1[i]='\0';
	int8_t str2[MAXLINE],str3[MAXLINE];
	/* string 1 gets copied to string 2 by replacing it with escapes */
	escape(str2,str1);
	printf("escaped string:%s\n",str2);
	unescape(str3,str1);
	printf("unescaped string:%s\n",str3);
}


int32_t escape(int8_t s[],int8_t t[]){
	int32_t i,j;
	for (i=0,j=0;t[i] != '\0';i++){

		/*Using switch case to replace char with escape char \t or \n*/
		switch(t[i]){
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	/* terminating the string */
	s[j]='\0';
	return 0;
}

int32_t unescape(int8_t s[],int8_t t[]){
        int32_t i,j;
        for (i=0,j=0;t[i] != '\0';i++){

                /*Using switch case to replace char with escape char \t or \n*/
               	 
		if ((t[i] == '\\') && ((t[i+1] == 'n') || (t[i+1] == 't')) ){
		i++;
		switch(t[i]){
                        
			case 't':
                                s[j++] = '\t';
                                
                                break;
                        case 'n':
                                s[j++] = '\n';
                                
                                break;
			
			}

		i++;
                }
     	s[j++] = t[i];
        }
        /* terminating the string */
        s[j]='\0';
        return 0;
}
