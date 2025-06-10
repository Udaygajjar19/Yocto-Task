//required headers
#include<stdio.h>
#include <limits.h>
#include "header.h"


//author
//created
//modified
//
void Data_Type_Size()
{
  printf("maximum value of data type char: %d\n", CHAR_MAX);//prints the max value of char data type        
  printf("minimum value of data type char: %d\n\n", CHAR_MIN); //prints the min value of char data type
  printf("maximum value of data type unsigned char: %u\n\n", (unsigned) UCHAR_MAX); //prints the max value of unisgned char data type


  printf("maximum value of data type short: %d\n", SHRT_MAX); //prints the max value of short data type      
  printf("minimum value of data type short: %d\n\n", SHRT_MIN); //prints the min  value of short data type
  printf("maximum value of data type unsigned short: %u\n\n", (unsigned) USHRT_MAX); //prints the max value of unsigned short data type



  printf("maximum value of data type int: %d\n", INT_MAX); //prints the max value of int data type
  printf("minimum value of data type int: %d\n\n", INT_MIN);//prints the min value of int data type
  printf("maximum value of data type unsigned int: %u\n\n", UINT_MAX);//prints the max value of unsigned int data type
 
 
  printf("maximum value of data type long: %ld\n", LONG_MAX);  //prints the max value of long data type
  printf("minimum value of data type long: %ld\n\n", LONG_MIN); //prints the min value of long data type
  printf("maximum value of data type unsigned long: %lu\n\n", ULONG_MAX);//prints the max value of unsigned long data type

}
