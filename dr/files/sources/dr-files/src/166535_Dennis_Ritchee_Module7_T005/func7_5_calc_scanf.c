/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#define NUMBER '0'
#define MAX 100

void calc_scanf(){
	int32_t type;
	char s[MAX];
	double op1,op2;
	while ((type = getop_scanf(s)) != EOF){
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				/* compute multiplication */
				push(pop() * pop());
				break;
				/* compute substraction*/
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
				/* compute division */
			case '/':
				op2 = pop();
				if (op2 != 0.0)
				    push(pop() / op2);
				else
				    printf("error: zero divisor\n");
				break;


			default:
				 printf("error: unknown command %s\n",s);
				 break;
		}
	}
				printf("Result: %g\n", pop());
}

int32_t getop_scanf(char s[]){
	int32_t c,rc;
	double f;
	char temp[MAX];
	rc = scanf("%s",temp);
	if (rc == EOF ){
		return EOF;
	}
	if (sscanf(temp,"%lf",&f) == 1){
		sprintf(s, "%lf", f);
        	return NUMBER;
	}
	else{
		s[0] = temp[0];  /* Store the operator as a string for error msg*/
        	s[1] = '\0';
        	return temp[0];
	}
	
}
