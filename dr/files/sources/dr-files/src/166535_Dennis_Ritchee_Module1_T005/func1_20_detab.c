
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdint.h>
#include "main.h"

#define TAB 8



/* FUNCTION: this function is to replace tab with spaces
 * Author       -> Om Rathod
 * Created      -> 5 febuary 2025
 * Modified     -> 5 febuary 2025
 */


void replace_tab2space(){
	int8_t c;
	uint8_t i;
	
	uint8_t i_position=0,i_space=0;
	printf("Enter string: ");
	while((c = getchar()) != EOF ){
		/* Checksif tab is pressed or not */
		if (c == '\t'){
			/* if yes then replacing it with space */
			i_space=TAB - (i_position) % TAB;

			for(i=0;i<i_space;i++){
				putchar(' ');
				i_position++;
			}
		
		
		}

		/* Reset the count */
		else if (c == '\n'){
			putchar(c);
			i_position = 0;
		}
		else{
			/* else will print what is given input */
			putchar(c);
			i_position++;	
		}
	}
	
}
