

/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"
#include <ctype.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000


int32_t getint(int32_t *pn){
        int32_t c,sign;
        while (isspace(c = _getch())) /* skip white space */
                ;

        if (c == EOF) return EOF;

        if ( !isdigit(c) && c!= EOF && c != '+' && c != '-'){
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

        *pn *= sign;
        if (c != EOF)
                un_getch(c);
        return c;

}

void call_getint(){
	int32_t Number;
	while(1){
		/* checking if input is valid or not */
		if(getint(&Number))
			printf("%d\n", Number);
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


#include <stdio.h>

#define BUFSIZE 100  // Size of the _buffer for un_getch

char _buf[BUFSIZE];  // Buffer for un_getch
int _bufp = 0;       // Next free position in _buf

// Reads a single character from input or _buffer
int _getch(void) {
    return (_bufp > 0) ? _buf[--_bufp] : getchar();
}

// Pushes a character back into input (supports one-step unreading)
void un_getch(int c) {
    if (_bufp >= BUFSIZE)
        printf("un_getch: too many characters\n");
    else
        _buf[_bufp++] = c;
}



