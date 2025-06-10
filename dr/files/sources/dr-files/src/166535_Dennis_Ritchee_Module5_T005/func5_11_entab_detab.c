
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"


/* REQUIRED MACROS */
#define MAXOP 100
#define NUMBER '0'

void replace_tab2space_a(char TAB){
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



void remove_space2tab_a(char TAB){
        int8_t c;
        uint8_t i_position=0,i_space=0;

        while((c=getchar()) != EOF ){
                i_position++;
                if (c == ' '){
                        i_space++;
                        if (i_position % TAB == 0){
                                putchar('t');
                                i_space=0;
                        }
                }
                else {
                        while(i_space>0){
                                putchar(' ');
                                i_space--;
                        }
                        if ( c == '\n'){
                                i_position=0;
                        }
                        putchar(c);
                }
        }
}

