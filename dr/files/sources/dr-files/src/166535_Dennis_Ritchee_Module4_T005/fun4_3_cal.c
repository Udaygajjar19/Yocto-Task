/* REQUIRED HEADERS */

#include<stdio.h>
#include<math.h>
#include<stdint.h>
//#include<stdlib.h>
#include "main.h"
#include <ctype.h>

/* REQUIRED MARCOS */
#define MAXOP 1000
#define NUMBER '0'
#define MAXVAL 100   /* Stack size*/


int32_t sp = 0;             /* Stack pointer*/
double val[MAXVAL];     

void cal_stack() {
    int32_t type,var=0,i;
    double variables[26]={0.0};
    double op2,op1,r;
    
    int8_t s[MAXOP];
    getchar();
    /* Loop to process input untill EOF */
    while ((type = getop_mygetline(s)) != EOF) {
        switch (type) {
		/*if its number push it onto stack */
            case NUMBER:
                push(_atof(s));
                break;
		/* compute addtion */
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
		/* compute modulus */
	    case '%':
		op2 = pop();
		op1= pop();
		/* if operand is non zero then */
		if ((int)op2 != 0){
			/*if either one of operand is negative*/
			if (op1 < 0 || op2 < 0 ){
				/*add the second operand to result*/
				push(((int)op1 % (int)op2) + op2);

			}
			else{
			push((int)op1 % (int)op2);
			}
		}
		else{
			printf("Error: zero divisor\n");
		}
		break;
		/*if enter is pressed then result is displayed*/
	    case '\n':
		r = pop();
                printf("\t%.8g\n",r);
                break;
	    case 't':  /* top of the stack value */
		print_stack();
                printf("top\t%.8g\n",val[sp - 1]);
                break;
	    case 'd':  /* top of the stack value is duplicated*/
		print_stack();
		Dup();
		print_stack();
                break;
	    case 's':/*swapping toptwo element*/
		print_stack();
		swap();
		print_stack();
		break;
	    case 'c':/* clearing the top to stack */
		print_stack();
                clear();
		print_stack();
                break;
	    case 'p':/* finding the power of a number */
		op1= pop();
		op2=pop();
		push(pow(op2,op1));
		break;
	    case 'a':/* finding sin angle of given value */
	    	push(sin(pop()));
		break;
	    case 'e':/* finding exponent */
	    	push(exp(pop()));
	    	break;
	    case '=':
		/* if before = its alphabet then*/
		if (var >= 'A' && var <= 'Z'){
			variables[var - 'A'] = pop();

		}
		else{
			printf("Error: no variable is present");
		}
		break;
		
	    case 'v':
		for (i=0;i<26;i++){
			if (variables[i] != 0){
				printf("%c = %.8g\n",(i + 'A'),variables[i]);
			}
		}

		
		break;
		
		/*other then above commands it will show error*/
            default:
		/*storing variables in an array*/
		if (type >= 'A' && type <= 'Z'){
			if (variables[type - 'A'] != 0){
				push(variables[type - 'A']);
			}
		}

		else if (type == 'r'){
			push(r);
			printf("result = ");
		}
		/*else if (type == EOF){
			printf("EOF has been occured\n");
		}*/
		else{
                	printf("error: unknown command %s\n",s);
		}
                break;
	
        }
	var = type;
    }
}


void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int32_t getop(int8_t *s) {
    	int32_t i = 0, c;
	/*skips white spaces*/
    	while ((*(s+0) = c = getch()) == ' ' || c == '\t')
		;
    		*(s+1) = '\0';
		/* rerturns operator if not number or negative sign */
    		if (!isdigit(c) && c != '.' && c != '-' )
			return c;
		/*condtion to handle negative sign*/
		if (c == '-'){
			/* if digit or decimal then store in array */
			if (isdigit(c = getch()) || c == '.'){
				i++;
				*(s+i)=c;
				
			}
			/* else will return operator */
			else{
				if ( c != EOF){
					ungetch(c);
				return '-';
				}
			}
		}
    		if (isdigit(c)){ /* Collect integer part*/
			i++;
    	    		while (isdigit(*(s+i) = c = getch()));
		}
		if (c == '.')  /* Collect fraction part*/
			while (isdigit(*(s+i) = c = getch()));
    		
		*(s+i) = '\0';
    		if (c != EOF)
        		ungetch(c);
    		return NUMBER;
}

//#define BUFSIZE 100
int8_t buf='\0';
_Bool EOF_push;
//int32_t bufp = 0;
int32_t getch(void) {
	int8_t cBUF;
	if (EOF_push){
		EOF_push = 0;
		return EOF;
	}
    	if (buf != '\0' ) { 
		cBUF = buf;
    	} 
    	else{ 
	    cBUF=getchar();
 	}
    	buf = '\0';
	return cBUF;
}
void ungetch(int32_t c) 
{
    if(c == EOF){
    	EOF_push =1; 
    }

    else if (buf != '\0'){
        printf("ungetch: already there is one character\n");
    }
    else{
        buf = c;
    }
}


void Dup(){
	if(sp>0 && sp<MAXVAL){
		val[sp]=val[sp-1];
		sp++;
		printf("Duplicated top of the element: %.8g\n",val[sp-1]);
	}
	else{
		printf("Error:duplicating failed\n");
	}
}

void swap(){
	double dTmp;
	if (sp>1 ){	
		dTmp=val[sp-2];
		val[sp-2]= val[sp-1];
		val[sp-1]=dTmp;
		printf("Swapped top two stack elements\n");
	}
	else{
		printf("Error: swapped failed\n");
	}
}
void clear(){
	sp=0;
	printf("Stack cleared\n");
}

void print_stack(){
	int32_t index;
	printf("stack: ");
	if(sp>0){
		for(index=(sp-1);index >= 0;index--){
			printf("%.8g ",val[index]);
		}
	printf("\n");
	}
}

