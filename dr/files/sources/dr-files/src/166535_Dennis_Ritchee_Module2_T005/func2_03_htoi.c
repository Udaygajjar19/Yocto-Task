/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 100

int32_t htoi (int8_t *s);
int32_t strtoint(int8_t c);

void call_htoi(){
	while(1){
		int8_t c;
		int32_t result;
		int8_t hexa_value[MAXLINE];
		printf("Enter hexadecimal value(0x..) -> ");
		scanf("%s",hexa_value);
		/*calling htoi function to convert string hex to int */
		result = htoi(hexa_value);
		/*if return value is -1 then there is some error*/
		if (result != -1){
			printf("integer value for hexa %s is %d\n",hexa_value,result);
		}
		else{
			printf("Error: Invalid input\n");
		}	
	printf("press 'q' to quit program(press any key to continue) ->");
	scanf(" %c", &c);
      	if (c == 'q'){
              	break;
       	}
	}
}
	




int32_t htoi (int8_t *s){

	int32_t i_value,int_value=0,i=0;
	/* not starting with 0x then invalid input */
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X') ){
		i += 2;
	}

	/*loop to check char by char*/
	for(;s[i] != '\0';i++){
		/*converting string to int*/
		i_value = strtoint(s[i]);
		if (i_value == -1){
			return -1;
		}
		/*logic for hexa to integer
		 * multiply resultant char by 16 and then to add current char*/
		int_value=(int_value << 4) | i_value;
	}
	return int_value;
}

int32_t strtoint(int8_t c){
	/*converts string char into interger*/

		if(c>='0' && c<='9' ){
			return c - '0';
		}
		else if(c>='a' && c<='f' ){
			return c - 'a' +10;
		}
		else if(c>='A' && c<='F' ){
			return c - 'A' + 10;
		}
		else{
			return -1;
		}
}
