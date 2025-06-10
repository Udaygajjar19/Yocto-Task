//required header
#include"header.h"
#include<stdio.h>
#include<stdint.h>

#define lim 10




//funtion of loop  equivalent to the for loop above without using && and || which is to print only given limit of character
//author:bhavik parekh
//created:3 jan 2025
//modified:3 jan 2025

void eqloop()
{
	int index,iChar;
        char s[lim];
  	index=0;
	printf("enter the string:\n");
         while(index<lim) {
              if((iChar=getchar()) != '\n') {
                   if(iChar != EOF) {
                         s[index] = iChar; 
                   }
              }
              index++;
         }	
	printf("%s\n",s);
	//printf("%d\n",index);
 

}
