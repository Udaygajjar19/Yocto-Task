//required header
#include<stdio.h>
#include "header.h"
#include<stdint.h>

//author:bhavik parekh
//created:3 jan 2025
//modified:3 jan 2025
//function to print power value of number 16
int Power(int n)
{
	int iPower;
	for (iPower = 1; n > 0; n--)
		iPower = iPower * 16;

	return iPower;
}

//author:bhavik parekh
//created:3 jan 2025
//modified:3 jan 2025
//function to convert the value of hex in integer using formula and it ignores the first 2 digit if they are '0X' or '0x' and returns -1 if invalid input
int HextoInteger(char s[])
{

	int value=0,wordcount=0,index=0,powervalue=0,charvalue=0;
	if (s[0]== '0' && ( s[1]== 'x' || s[1]== 'X' )){
		s+=2;
	}
	while(s[wordcount] !='\0')
	{
		wordcount++;
	}

	for (index=0;index < wordcount;++index)
	{
		powervalue = Power( wordcount-1-index );

		if(s[index]>='0' && s[index]<='9'){
			charvalue = s[index]-'0';
		}
		else if(s[index]>='a' && s[index]<='f'){
			charvalue = s[index]- 'a' + 10;
		}
		else if (s[index]>='A' && s[index]<='F'){
			charvalue = s[index]- 'A' + 10 ;
		}
		else {
			printf("invalid character:%c\n",s[index]);
			return -1;
		}

		value = ((powervalue) * (charvalue)) + value ;

	}
	return value;
}

//author:bhavik parekh
//created:3 jan 2025
//modified:3 jan 2025
//function to take input in hex and convert it to integer
void HextoIntgerOutput(){

	char input[100];
	int index = 0;
	char ch;
	int result;

	printf("enter hex number(ctrl d to exit):\n");

	// Read input character by character using getchar
	while ((ch = getchar()) != EOF &&  ch != '\n') {
		input[index++] = ch;
	}
	 input[index] = '\0';

	// Convert the input hexadecimal string to integer.
	result = HextoInteger(input);
	if (result != -1) {
		printf("integer value is: %d\n", result);
	}


} 
