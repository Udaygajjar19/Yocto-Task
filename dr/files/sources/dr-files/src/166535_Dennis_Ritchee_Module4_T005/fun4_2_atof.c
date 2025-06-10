/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
//#include<stdlib.h>
#include "main.h"

#include<ctype.h>
/* REQUIRED MARCOS */
#define MAXLINE 1000
void call_atof(){
	getchar();
	int8_t s1[MAXLINE];
	double result;
	while(1){
		int8_t c;
		printf("Enter string -> ");

		scanf(" %[^\n]",s1);

		/*calling the function*/
		result = _atof(s1);
		printf("%f\n", result);

		printf("press 'q' to quit program(press any key to continue) ->");
		scanf(" %c", &c);
		if (c == 'q'){
			break;
		}
	}
}



/* atof: convert string s to double */  
double _atof(int8_t *s) 
{ 
	double val, power,mul; 
	int32_t i, sign,sign1; 
	for (i = 0; isspace(s[i]); i++) /* skip white space */ 
		; 
	sign = (s[i] == '-')? -1: 1;
	if (s[i] == '+' || s[i] == '-') 
		i++; 
	for (val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0'); 
	if (s[i] == '.') 
		i++; 
	for (power = 1.0; isdigit(s[i]); i++) 
	{ 
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val = sign * val / power;


	/*check if there is any e in string*/
	if (s[i] == 'e' || s[i] == 'E' ){
		i++;

		/*checking for negative sign after e*/
		if(s[i] == '-'){
			sign1 = -1;
			i++;
		}
		else if(s[i] == '+'){
			sign1 = 1;
			i++;
		}
		else{
			sign1 = 1;
		}
		/*capturing the integer after e*/
		for (mul= 0.0; isdigit(s[i]);i++){
			mul = 10.0 * mul + (s[i] - '0');
		}
		/*if sign is positive then it will multiply by 10*/
		if (sign1 ==1 ){
			while (mul-- > 0)
				val *= 10;
		}
		/*else sign is negative then it will divide by 10*/
		else {
			while (mul-- > 0)
				val /= 10;
		}
	}
	return val;
}

