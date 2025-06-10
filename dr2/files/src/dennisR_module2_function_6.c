//required headers
#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<stdint.h>


//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025
//funtion to convert the decimal value in binary
void binary(int decimal){


        int index;
        for(index=7;index>=0;--index){
        int binary= (decimal >> index) & 1;
        printf("%d",binary);
        }
        printf("\n");


}

//author:bhavik parekh
//created:10 jan 2025
//modified:10 jan 2025
//function to set n number of bits from any number of position in input1 from input2
void setbit(int x,int inumber,int iposition, int y){
	
	int mask;
	//long long output;
	mask= (((1<<inumber)-1)<<iposition);
	printf("\noutput bit string:%d\n",x);
	int variable1,variable2,variable3;
	
	printf("\nmask:%d\n",mask);
	printf("\n!mask:%d\n",~mask);
	y&=mask;
	x&=~mask;
	x|=y;
	printf("\noutput bit string:%d\n",x);
	binary(x);
	

	
}	
//author:bhavik parekh
//created:10 jan 2025
//modified:10 jan 2025
//function to take two inputs as binary string converts to decimal and set n number of bit from given postion from given 2nd string
int SetbitOutput(){

        int inumber,iposition;
	int input1,input2;

        char input[9];

        printf("enter the value of first binary string:");
        fgets(input,32,stdin);
        input1 = strtoul(input,NULL,2);

        printf("\nenter the value of second binary string:");
        fgets(input,32,stdin);
        input2 = strtoul(input,NULL,2);

        printf("\nenter the value of position you want to change the binary string:");
        scanf("%d",&iposition);

        printf("\nenter the value of the number of bits you want to change from the position given:");
        scanf("%d",&inumber);


        setbit(input1,inumber,iposition,input2);
	return 0;


}
