
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

/* REQUIRED MACROS */
#define MAXLINE 100  
#define NUMBER '0'


void expr(int argc, char *argv[]) {
    double op2;
    int32_t type;
    char input[MAXLINE];

    for (int i = 1; i < argc; i++) {
        strncpy(input, argv[i], MAXLINE - 1);
        input[MAXLINE - 1] = '\0';
        type = isdigit(input[0]) || (input[0] == '-' && isdigit(input[1])) ? NUMBER : input[0];

        switch (type) {
            case NUMBER:
                push(atof(input));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: Division by zero!\n");
                break;
            default:
                printf("Error: Unknown command %s\n", input);
                break;
        }
    }
    printf("Result: %.8g\n", pop());
}

void argv_to_string(int argc, char *argv[], char *result, size_t size) {
    result[0] = '\0'; // Initialize empty string
  	for (int i = 1; i < argc; i++) {
        	strncat(result, argv[i], size - strlen(result) - 1);
     		if (i < argc - 1) {
            	strncat(result, " ", size - strlen(result) - 1);
        	}
   	}
}
