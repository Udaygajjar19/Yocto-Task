#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<stdint.h>
//author:bhavik parekh
//created:9 jan 2025
//modified:9 jan 2025
//function to count set bits 
int bitcount(int x){

	int bit;

	while(x!=0){
		x&=x-1;
		   bit++;}
	printf("number of 1's in the input is %d\n",bit);
	return 0;	
}
//author:bhavik parekh
//created:9 jan 2025
//modified:9 jan 2025
//function to take the of bit string and count the set bit of the string and print the number of set bits
void BitcountOutput(){

        char input_string[100];
        int input;
        fgets(input_string,100,stdin);
        input=strtoul(input_string,NULL,2);

        bitcount(input);

}
