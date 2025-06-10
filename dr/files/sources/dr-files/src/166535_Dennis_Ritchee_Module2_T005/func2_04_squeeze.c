
/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 100

/* Function     -> This function is to call squeez function
 * Author       -> Om Rathod
 * Created      -> 10 febuary 2025
 * Modified     -> 10 febuary 2025
 */
//void squeeze(int8_t str1[], int8_t str2[]);
//int32_t lowercase(int8_t s[]);
void call_squeez(){
	int8_t c,str_main[MAXLINE],str_rm[MAXLINE];
	while(1){

		/*Getting string as a input execept \n*/
		printf("Enter string 1 -> ");
		scanf(" %[^\n]",str_main);
		printf("\nEnter string 2 -> ");
                scanf(" %[^\n]",str_rm);

		/*calling function to change the uppercase to lowercase*/
		lowercase(str_main);
		lowercase(str_rm);

		/* calling function to squeez the line */
		squeeze(str_main,str_rm);

		/*Asking user whether thry want to quit or not*/
		printf("\nEnter q to quit: ");
		scanf(" %c", &c);
		if(c == 'q'){
			break;
		}
	}
}

void squeeze(int8_t str1[], int8_t str2[]){
	uint16_t i,j,k;
	uint8_t FLAG;
	/*single char of str1 is check by second string if matched then it is squeezed*/	
	for(i=k=0;str1[i] != '\0';i++){
		
		/*reseting the flag*/
		FLAG=0;
		for(j=0;str2[j] != '\0';j++){

			/*string is matched then set flag as 1*/
			if (str1[i] == str2[j]){
				FLAG = 1;
				break;
			}
		}

		/* if there is no match with string 2 then only it store in string 1 */
		if (!FLAG) {
         		str1[k++] = str1[i];  
       	 	}	

	}
	str1[k] = '\0';
	printf("%s\n",str1);
}

int32_t lowercase(int8_t s[]){
	int16_t i;
	for(i=0;s[i] != '\0';i++){
		/* converting upper to lowercase*/
		if(s[i]>= 'A' && s[i] <= 'Z' ){
			s[i] = s[i] + ('a' - 'A');
		}
	}
	return 0;
}
