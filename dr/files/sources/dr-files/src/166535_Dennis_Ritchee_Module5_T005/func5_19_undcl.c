/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#define MAXTOKEN 1000
#define NAME 0
#define TYPE 3
#define PARENS 4

void undcl() 
{ 
 	int type; 
 	char temp[2000]; 
 	
	while (gettoken() != EOF) { 
 		strcpy(out, token); 
 		
		while ((type = gettoken()) != '\n'){ 
 			if (type == PARENS || type == '[') {
 				sprintf(temp,"%s%s",out,token);
				strcpy(out, temp); 
			}
 			else if (type == '*') { 
 				if(strchr(out,'(') || strchr(out, '[') ){
					sprintf(temp, "(*%s)", out); 
				}
				else{
					sprintf(temp, "*%s", out); 
				}
 				strcpy(out, temp); 
 			} else if (type == NAME) { 
 				sprintf(temp, "%s %s", token, out); 
 				strcpy(out, temp); 
 			
			}
			else if (type == TYPE){
				sprintf(temp,"%s %s",token,out);
				strcpy(out,temp);
			}
		       	else 
 				printf("invalid input at %s\n", token);
		} 
	printf("%s\n",out);
	} 
}
