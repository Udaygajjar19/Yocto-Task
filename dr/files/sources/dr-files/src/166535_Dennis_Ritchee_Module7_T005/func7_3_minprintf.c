/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>


#include <stdarg.h>
void minprintf(char *fmt, ...);

#define MAX 100

void call_minprintf(){
	char string[MAX];
	strcpy(string,"Hello");
	minprintf("Integer: %d\n",12);
	minprintf("Double/Float: %f\n", 132.22);
    	minprintf("String: %s\n", string);

    	minprintf("Char: %c\n", 'O');
    	minprintf("Unsigned: %u\n", 123);
    	minprintf("Octal: %o\n", 20);
    	minprintf("Hexadecimal: %x\n", 20);
}

/* minprintf: minimal printf with variable argument list */
 void minprintf(char *fmt, ...)
 {
 	va_list ap; /* points to each unnamed arg in turn */
 	char *p, *sval;
 	int ival;
 	double dval;
	char cval;
	unsigned int uval;
	int oval,xval;
 	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
 	for (p = fmt; *p; p++) {
 		if (*p != '%') {
 		putchar(*p);
 		continue;
 	}
 	switch (*++p) {
 		case 'd':
 			ival = va_arg(ap, int);
 			printf("%d", ival);
 			break;
 		case 'f':
 			dval = va_arg(ap, double);
 			printf("%f", dval);
 			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		case 'c':
			cval = va_arg(ap,int);
			printf("%c",cval);
			break;
	
		case 'u':	
			uval = va_arg(ap,unsigned int);
			printf("%u",uval);
			break;
		
		case 'o':
		       	oval = va_arg(ap,int);
	       		printf("%o",oval);	       
			break;


		case 'x':
			xval = va_arg(ap,int);
			printf("%x",xval);
			break;


		default:
			putchar(*p);
			break;
		}
	}
 	va_end(ap); /* clean up when done */
 }
