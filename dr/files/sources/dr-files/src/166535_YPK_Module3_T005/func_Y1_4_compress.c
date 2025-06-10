/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

void call_com_decom(){
	int8_t string[MAXLINE],Compress[MAXLINE],Decompress[MAXLINE];
	int32_t SpaceCount[MAXLINE]={0};
	getchar();
	printf("Enter string ->");
	scanf("%[^\n]",string);

	/*callig the Compress and decompress function */
	compress(string,Compress,SpaceCount);
	decompress(Compress,Decompress,SpaceCount);

	/* printing all the strings */
	printf("Orignal\t\t: %s\n",string);
	printf("Compressed\t: %s\n",Compress);
	printf("Decompressed\t: %s\n",Decompress);

}


void compress(int8_t string[],int8_t string_compress[],int32_t SpaceCount[]){
	int32_t i,j,k=0;
	/*flag of is for checking if one space occured and checks there is another*/
	/*space is for allocating the space count in an array*/
        _Bool flag=0,Space=0;

	/*checking the string char by char*/
        for(i=0,j=0;string[i] != '\0';i++){
		/*if there is space*/
                if (string[i] == ' ' || string[i] == '\t'){
                        /* if new space is occured then k count is increased */
			if(!Space){
				/* space flag is turned on */
				k++;
				Space = 1;
			}
			/*counting the extra spaces to use it in decompress part*/
			SpaceCount[k]++;
			/* it only gives single space */
			if(!flag){
                                string_compress[j++] = ' ';
                                flag=1;
                        }
                }else{
			/*else part is stored as it is*/
                        string_compress[j++]= string[i];
                        Space=0;
			flag=0;
                }
        }
	/*  prints space count
	for(i=0;i<10;i++){
		printf("%d ",SpaceCount[i]);
	}
	printf("\n");
	*/
        string_compress[j] = '\0';
}


void decompress(int8_t string_compress[],int8_t recover[],int32_t SpaceCount[]){
	int32_t i,j=0,k=1,l;

	for(i=0;string_compress[i] != '\0';i++){
		/*if there is space then*/
		if (string_compress[i] == ' '){
				/*it will put the extra spaces which were being removed*/
			for(l=0;l<SpaceCount[k];l++){
				recover[j++] = ' ';
			}
		k++;
		}
		/*if not space then it will store string as it is*/
		else{
			recover[j++] = string_compress[i];
		}
	}

	/* Terminating the string */
	recover[j] = '\0';
}

