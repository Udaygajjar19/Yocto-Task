/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"
#include<string.h>

/* REQUIRED MARCOS */
#define MAXLINE 100

void call_itob(){
	int32_t n,b;
	int8_t c,s[MAXLINE];
	
	while(1){
		/* taking user input */
		printf("Enter number -> ");
		scanf("%d",&n);
		printf("\nEnter base number -> ");
                scanf("%d",&b);
		/*passing the arg in th func*/
		itob(n,s,b);
		printf("\n%s\n",s);
		printf("press 'q' to quit program(press any key to continue) ->");
		scanf(" %c", &c);                                               
		if (c == 'q'){
			break;
		}
	}
}



void itob(int32_t n,int8_t *s,int32_t b){
	int32_t i=0,j;
	/* Entered number is negative then it will show error */
	if((b < 0) || (n < 0)){
		printf("Error: negative input not allowed");
	}
	/*first getting msb and then doing division in while*/
	do{
		j = n % b;
		/*storing the value of reminder into string*/
		*(s+i) = (j > 9) ? (j - 10) + 'A' : j + '0'; 
		i++;
	}while ((n/=b) > 0);

	*(s+i) = '\0';
	reverses(s);
}
void reverses(int8_t *s){
	int32_t i,j;
	int8_t temp;
	for(i=0,j = strlen((char *)s) - 1;i<j;i++,j--){
		temp = *(s+i);
        	*(s+i) = *(s+j);
        	*(s+j) = temp;
	}
	//s[i]='\0';
}

