//required headers
#include<stdio.h>
#include"header.h"
#include<stdint.h>

//the function about any(s1,s2), which returns the first location in a string s1where any character from the string s2 occurs, or -1 if s1 contains no characters from s2
//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025

int any(char s1[],char s2[]){

	int index1,index2;
	for(index1=0;s2[index1] !='\0';++index1){
		for(index2=0; s1[index2] !='\0' ; ++index2){
			if(s1[index2] == s2[index1]){
				return index2+1;
			}
		}	
	
	}
	return -1;
}

//author:bhavik parekh
//created:7 jan 2025
//modified:7 jan 2025
//function to get input and check if first character of string 2 mtch any charcter of string one if matches then print the character index 
void RemoveCharacter(){

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
        int result;
        result = any(string1,string2);
        if(result != -1){
        printf("index of the matching character: \"%d\" (index starts from 1)\n",result);

        }
        else{
                printf("strings does not match\n");
        }
}
