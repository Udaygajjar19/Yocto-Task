
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
 
int gettoken(void);
void dcl(void);
void dirdcl(void);
 
int tokentype;

char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void)
{
        int c;
        char *p = token;

        while ((c = getchar()) == ' ' || c == '\t')
                ;

        if (c == '*') {
                *p++ = c;
                *p = '\0';
                return tokentype = '*';
        } else if (c == '(') {
                if ((c = getchar()) == ')'){
			strcpy(token,"()");
			return tokentype = PARENS;
		}
		else{
			ungetc(c,stdin);
			return tokentype = '(';
		}
		*p++ = c;
                *p = '\0';
                return tokentype = PARENS;
	}
	else if (c == '[') {
        	*p++ = c;
        	while ((*p++ = getchar()) != ']')
            		;  
        	*p = '\0';
        	return tokentype = '[';  
    	
        } else if (isalpha(c)) {
                for (*p++ = c; isalnum(c = getchar()); )
                        *p++ = c;

                *p = '\0';
                ungetc(c, stdin);

                if (strcmp(token, "int") == 0)
                        return tokentype = TYPE;
                else if (strcmp(token, "char") == 0)
                        return tokentype = TYPE;
                else if (strcmp(token, "float") == 0)
                        return tokentype = TYPE;
                else if (strcmp(token, "double") == 0)
                        return tokentype = TYPE;
                else if (strcmp(token, "void") == 0)
                        return tokentype = TYPE;
                else
                        return tokentype = NAME;
        } else if (c == '\n' || c == EOF) {
                return tokentype = c;
        } else {
                *p++ = c;
                *p = '\0';
                return tokentype = c;
        }
}

void dcl(void)
{
        int ns = 0;

        while (gettoken() == '*')
                ns++;

        dirdcl();

        while (ns-- > 0)
                strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */ 
void dirdcl(void){ 
 	int type; 
 	if (tokentype == '(') { /* ( dcl ) */ 
 		gettoken();
		dcl(); 
 		if (tokentype != ')') 
 			printf("error: missing )\n"); 
 	} else if (tokentype == NAME) /* variable name */ 
 		strcpy(name, token); 
 	else 
 		printf("error: expected name or (dcl)\n"); 
 	while ((type=gettoken()) == PARENS){ 
 		strcat(out, " function returning"); 
 	} 
} 
void call_dcl(void)
{
        printf("Enter a declaration: \n");
	getchar();
        if (gettoken() != TYPE) {
                printf("error\n");
                return;
        }

        strcpy(datatype, token);
        out[0] = '\0';

        dcl();

        printf("%s: %s %s\n", name, out, datatype);
}

