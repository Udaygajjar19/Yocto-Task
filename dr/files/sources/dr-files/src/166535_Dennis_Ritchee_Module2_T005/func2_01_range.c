/* REQUIRED HEADERS */
#include<stdio.h>
#include<limits.h>
#include<float.h>
#include "main.h"

void all_range() {
	printf("-------------SIGNED DATA TYPES------------------\n");
    	printf("char MIN (Computed)\t-> %d\n", -((unsigned char)1 << (sizeof(char) * 8 - 1)));
   	printf("char MAX (Computed)\t-> %d\n", ((1 << (sizeof(char) * 8 - 1)) - 1));
    	printf("char MIN (using headers)\t-> %d\n", SCHAR_MIN);
    	printf("char MAX (using headers)\t-> %d\n", SCHAR_MAX);

    	printf("\nINT MIN (Computed) \t-> %d\n", -((unsigned int)1 << (sizeof(int) * 8 - 1)));
    	printf("INT MAX (Computed) \t-> %d\n", ((1 << (sizeof(int) * 8 - 1)) - 1));
    	printf("INT MIN (using headers) \t-> %d\n", INT_MIN);
   	printf("INT MAX (using headers) \t-> %d\n", INT_MAX);

   	printf("\nSHORT MIN (Computed)\t-> %d\n", -((unsigned short)1 << (sizeof(short) * 8 - 1)));
   	printf("SHORT MAX (Computed)\t-> %d\n", ((1 << (sizeof(short) * 8 - 1)) - 1));
   	printf("SHORT MIN (using headers)\t-> %d\n", SHRT_MIN);
    	printf("SHORT MAX (using headers)\t-> %d\n", SHRT_MAX);

    	printf("\nLONG MIN (Computed)\t-> %ld\n", -((unsigned long)1L << (sizeof(long) * 8 - 1)));
    	printf("LONG MAX (Computed)\t-> %ld\n", ((1L << (sizeof(long) * 8 - 1)) - 1));
    	printf("LONG MIN (using headers)\t-> %ld\n", LONG_MIN);
    	printf("LONG MAX (using headers)\t-> %ld\n", LONG_MAX);
	
    	printf("\n-------------UNSIGNED DATA TYPES-------------------\n");
    	printf("char MAX (Computed) \t-> %u\n", (1U << (sizeof(char) * 8)) - 1);
    	printf("char MAX (using headers) \t-> %u\n", UCHAR_MAX);

    	printf("\nINT MAX (Computed) \t-> %u\n", (1U << (sizeof(int) * 8)) - 1);
    	printf("INT MAX (using headers) \t-> %u\n", UINT_MAX);

    	printf("\nSHORT MAX (Computed) \t-> %u\n", (1U << (sizeof(short) * 8)) - 1);
    	printf("SHORT MAX (using headers) \t-> %u\n", USHRT_MAX);

    	printf("\nLONG MAX (Computed) \t-> %lu\n", (1UL << (sizeof(long) * 8)) - 1);
    	printf("LONG MAX (using headers) \t-> %lu\n", ULONG_MAX);
}


