/* REQUIRED HEADERS */

#include<stdio.h>
#include<math.h>
#include<stdint.h>
//#include<stdlib.h>
#include "main.h"
#include <ctype.h>

/* REQUIRED MARCOS */
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100  /* Stack size*/
#define MAXLINE 1000
int32_t iIpLine=0;
int8_t line[MAXLINE];

int32_t getop_mygetline(int8_t s[]) {
	int32_t i=0, c;
	
	/*taking input using getline*/
	if (line[iIpLine] == '\0' ){
		if (my_getline(line,MAXLINE) == 0)
			return EOF;
		else
			iIpLine = 0;
	}
        /*skips white spaces*/
        while ((s[0] = c = line[iIpLine++]) == ' ' || c == '\t')
                ;
                s[1] = '\0';
                /* rerturns operator if not number or negative sign */
                if (!isdigit(c) && c != '.' && c != '-' )
                        return c;
                /*condtion to handle negative sign*/
                if (c == '-'){
                        /* if digit or decimal then store in array */
                        if (isdigit(line[iIpLine]) || line[iIpLine] == '.'){
                                s[i=1]=c=line[iIpLine++];
                        }
                        /* else will return operator */
                        else{    
                                return '-';   
                        }
                }
                if (isdigit(c)) /* Collect integer part*/
                        while (isdigit(s[++i] = c = line[iIpLine++]));

                if (c == '.')  /* Collect fraction part*/
                        while (isdigit(s[++i] = c = line[iIpLine++]));

                s[i] = '\0';
                iIpLine--;
                return NUMBER;
}
