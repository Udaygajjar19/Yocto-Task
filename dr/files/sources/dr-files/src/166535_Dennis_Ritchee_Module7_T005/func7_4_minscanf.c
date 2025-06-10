/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>


#include <stdarg.h>
void minscanf(char *fmt, ...);

#define MAX 100

void call_minscanf(){
        int ival;
        double dval;
        char cval;
        unsigned int uval;
        int oval,xval;
        char string[MAX];
        //strcpy(string,"Hello");
	
	getchar();
        minscanf(" %d",&ival);
	getchar();
        minscanf(" %f",&dval);
	getchar();
        minscanf(" %s", string);
	getchar();
        minscanf(" %c", &cval);
	getchar();
        minscanf(" %u", &uval);
	getchar();
        minscanf(" %o", &oval);
	getchar();
        minscanf(" %x", &xval);


	printf("\nYou entered:\n");
    	printf("Integer: %d\n", ival);
    	printf("Float: %f\n", dval);
    	printf("String: %s\n", string);
    	printf("Char: %c\n", cval);
    	printf("Unsigned: %u\n", uval);
    	printf("Octal: %o\n", oval);
    	printf("Hexadecimal: %x\n", xval);
}

/* minscanf: minimal scanf with variable argument list */
 void minscanf(char *fmt, ...)
 {
        va_list ap; /* points to each unnamed arg in turn */
        char *p, *sval;
        int *ival;
        double *dval;
        char *cval;
        unsigned int *uval;
        int *oval,*xval;
        va_start(ap, fmt); /* make ap point to 1st unnamed arg */
        for (p = fmt; *p; p++) {
                if (*p != '%') {
                continue;
        }
        switch (*++p) {
                case 'd':
                        ival = va_arg(ap, int*);
                        printf("Enter integer: ");
			scanf(" %d", ival);
                        break;
                case 'f':
                        dval = va_arg(ap, double *);
                        printf("Enter float: ");
			scanf(" %lf", dval);
                        break;
                case 's':
			sval = va_arg(ap,char *);
                        printf("Enter string: ");
                     	scanf(" %[^\n]",sval);
                        break;
                case 'c':
                        cval = va_arg(ap,char*);
                        printf("Enter char: ");
                        scanf(" %c",cval);
                        break;

                case 'u':
                        uval = va_arg(ap,unsigned int *);
                        printf("Enter unsigned: ");
                        scanf(" %u",uval);
                        break;

                case 'o':
                        oval = va_arg(ap,int *);
                        printf("Enter octal: ");
			getchar();
                        scanf(" %o",oval);
                        break;


                case 'x':
                        xval = va_arg(ap,int *);
                        printf("Enter hexal: ");
			getchar();
			scanf("%x",xval);
                        break;


                default:
                        break;
                }
        }
        va_end(ap); /* clean up when done */
 }
