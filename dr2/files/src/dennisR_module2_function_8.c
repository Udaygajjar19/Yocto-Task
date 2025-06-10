//required headers
#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<stdint.h>

//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025
//function to convert decimal value to binary
extern void binary(int decimal);

/*{


        int i;
        for(i=15;i>=0;--i){
        unsigned int binary= (decimal >> i) & 1;
        printf("%u",binary);
        }
        printf("\n");


}*/


//author:bhavik parekh
//created:13 jan 2025
//modified:13 jan 2025
//function to right rotate the number by number of bits
void rightrot(int x,int inumber){

        int mask;
	
        int variable1,variable2,variable3,variable;
        long long output;
        mask= ((1<<inumber)-1) ;
	variable1= mask & x;
	variable2= variable1 << (8 - inumber) ;
	variable3= x >> inumber;
	variable= variable2 | variable3 ;

        printf("\noutput bit string:");
        binary(variable);


}

//author:bhavik parekh
//created:13 jan 2025
//modified:13 jan 2025
//function to rightroatate the input string
void RightrotateOutput(){

        int inumber;
        int input1;

        char input[32];

        printf("enter the value of first binary string:");
        fgets(input,32,stdin);
        input1 = strtoul(input,NULL,2);




        printf("\nenter the number you want to rotate right the bit string: ");
        scanf("%d",&inumber);


        rightrot(input1,inumber);



}
