//required headers
#include<stdio.h>
#include"header.h"
#include<stdint.h>

//function of an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. 
//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025
void squeeze(char s1[],char s2[]){

	int index1,index2,index3;
	for(index3=0;s2[index3] !='\0';++index3){
		for(index1=index2=0; s1[index1] !='\0' ; ++index1){
			if(s1[index1] != s2[index3]){
				s1[index2++]=s1[index1];
			}
		}	
	
	s1[index2]='\0';
	}

}


//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025
//function to take input of 2 strings and removes every same character from string2 in string1 and prints the output
void SqueezeOutput(){

        char string1[100],string2[100];
        int index1,index2;
        index1=index2=0;
        char ch;
        printf("enter string1:");
        while ((ch = getchar()) != EOF &&  ch != '\n') {
                string1[index1++] = ch;
    }
        printf("enter string2:");
        while ((ch = getchar()) != EOF &&  ch != '\n') {
                string2[index2++] = ch;
    }
        squeeze(string1,string2);
        printf("output string:%s\n",string1);
        //printf("string2:%s\n",string2);
}
