
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"


/* REQUIRED MACROS */
#define MAX 100



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAX_LINE_LENGTH 1024


int parse_argument(int argc, char *argv[]) {
    	if (argc == 3 && strcmp(argv[1], "-n") == 0) {
        	int n = atoi(argv[2]);  /* Convert the number after -n*/
        	return n > 0 ? n : DEFAULT_LINES;  /* Ensure n is positive*/
    	}
    	return DEFAULT_LINES;  /* Default to 10 if no valid argument is provided*/
}
 
/* Function to print the last n lines*/
void tail(int n) {
    	char lines[n][MAX_LINE_LENGTH];  /* Array to store the last n lines*/
    	int count = 0;  /* Keeps track of the number of lines read*/
 
    	/* Read lines until EOF */
    	while (fgets(lines[count % n], MAX_LINE_LENGTH, stdin)) {
    		count++;  /* Increment the count of lines read*/
    	}
 
    /* Calculate the starting point in the buffer*/
    	int start = count >= n ? count % n : 0;
 
    /* Print the last n lines*/
    	for (int i = 0; i < n; i++) {
        	printf("%s", lines[(start + i) % n]);
    	}
}
 
/* Main function to call tail*/
int call_13(int argc, char *argv[]) {
    	/* Check if arguments are passed correctly*/
    	if (argc > 3 || (argc == 3 && strcmp(argv[1], "-n") != 0)) {
        	fprintf(stderr, "Usage: %s -n <number_of_lines>\n", argv[0]);
        	return 1;
    	}
 
    	/* Get the number of lines to print*/
    	int lines_to_print = parse_argument(argc, argv);
    	if (lines_to_print <= 0) {
        	fprintf(stderr, "Invalid number of lines: %d. Must be a positive integer.\n", lines_to_print);
        	return 1;
    	}
 
    	/* Call the tail function with the desired number of lines*/
    	tail(lines_to_print);  /* Print the last 'lines_to_print' lines*/
    	return 0;
}




/*
void tail_arg(int32_t argc,char *argv[]){
	int32_t n = DEFAULT_N;
	if (argc == 2 && argv[1][0] == '-' ){
		n = atoi(argv[1]+1);
		if(n <= 0){
			printf("Error:invalid input");
			return;
		}
	}
	char input[MAXLINE];
	int32_t length = my_getline(input,MAXLINE);
	int32_t skip = length - n;
	strncpy(input," ",skip);
	printf("%s",input);
}*/
