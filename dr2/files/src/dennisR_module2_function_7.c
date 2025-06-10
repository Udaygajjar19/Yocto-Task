//required headers
#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<stdint.h>

//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025
//funtion to convert the decimal value in binary
extern void binary(int decimal);

/*{


        int i;
        for(i=15;i>=0;--i){
        unsigned int binary= (decimal >> i) & 1;
        printf("%u",binary);
        }
        printf("\n");


}
*/

//author:bhavik parekh
//created:10 jan 2025
//modified:10 jan 2025
//function to invert the n number of bits from given postion 
void invert(int x,int inumber,int iposition){
	
	int mask;
	long long output;
	mask= ((1<<inumber)-1)<<iposition;

	int variable;

	variable = x ^ mask;
	printf("\noutput bit string:");
	binary(variable);
	

}	

	

//author:bhavik parekh
//created:10 jan 2025
//modified:10 jan 2025
//function to take input as bit string and convert that into binary and do invert operation which invert n number of string from given postion in input bit string and print the output bit string
void InvertedbitOutput(){


        int inumber,iposition;
        int input1;

        char input[32];

        printf("enter the value of first binary string:");
        fgets(input,32,stdin);
        input1 = strtoul(input,NULL,2);



        printf("\nenter the value of position you want to change the binary string:");
        scanf("%d",&iposition);

        printf("\nenter the value of the number of bits you want to change from the position given:");
        scanf("%d",&inumber);


        invert(input1,inumber,iposition);



}


