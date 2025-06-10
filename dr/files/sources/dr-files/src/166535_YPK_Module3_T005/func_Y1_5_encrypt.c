/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000
#define PASSWORD 0010


void call_encode_decode(){
	int8_t Orignal[MAXLINE],Encode[MAXLINE],Decode[MAXLINE];
	printf("Enter String: ");
	getchar();
	scanf("%[^\n]",Orignal);
	
	/*calling the encode decode function*/
	encode(Orignal,Encode);
	decode(Encode,Decode);

	/*Displaying all the strings*/
	printf("Orignal\t: %s\n",Orignal);
	printf("Encode\t: %s\n",Encode);
	printf("Decode\t: %s\n",Decode);


}


void encode(int8_t string[],int8_t Encode[]){
	int32_t index;
	for(index=0;string[index] != '\0';index++ ){
		/* using exor to encrpyt the string with certain key */
		Encode[index] = string[index] ^ PASSWORD;
	}
	/* Terminating the string */
	Encode[index] = '\0';
}





void decode(int8_t Encode[],int8_t Decode[]){
	int32_t index;
        for(index=0;Encode[index] != '\0';index++ ){
                
		/* again toggling the string using Exor to bring back the orignal string */
		Decode[index] = Encode[index] ^ PASSWORD;
        }
	/*terminating the string*/
	Decode[index] = '\0';
}
