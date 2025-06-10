/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"
#include <ctype.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000



int32_t getfloat(float *pn){
        int32_t c,sign;
	float DeciPoint;
        while (isspace(c = _getch())) /* skip white space */
                ;

        if (c == EOF) return EOF;

        if ( !isdigit(c) && c!= EOF && c != '+' && c != '-' && c != '.'){
                /*it is not a number*/
                un_getch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '+' || c == '-'){
                /* checking if next is not digit */
                int32_t next = _getch();
                if(!isdigit(next)){
                        /*ungeting both next and c into buffer*/
                        un_getch(next);
                        un_getch(c);
                        /*returning zero*/
                        return 0;
                }
                /* else c = next is assigned */
                c =next;
        }
	
	
        for(*pn =0;isdigit(c);c = _getch()){
                *pn = 10 * *pn + (c - '0');
        }
	
	/*checking if there  is decimal point in an given input*/
	if(c == '.'){
		c = _getch();
	}
	/*taking the digit part after '.' and and calculating how to points need to be kept*/
	for(DeciPoint=1.0;isdigit(c);c =_getch()){
		*pn = 10.0 * *pn + (c - '0');
		DeciPoint *= 10.0;
	}
	/*dividing the result by decimal point to get final integer*/
        *pn *= sign/DeciPoint;
        if (c != EOF)
                un_getch(c);
        return c;

}

void call_getfloat(){
        float Number;
        while(1){
                /* checking if input is valid or not */
                if(getfloat(&Number))
                        printf("%.6g\n", Number);
                else{
                        printf("Error:invalid input\n");
                        break;
                }
        printf("Press q to quit:");
        if(getchar() == 'q'){
                printf("Exited\n");
                break;
        }
        }
}

