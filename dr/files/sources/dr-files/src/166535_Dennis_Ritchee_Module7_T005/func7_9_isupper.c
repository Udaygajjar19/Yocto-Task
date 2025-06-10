/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>
#include<time.h>


void time_space_isupper(){
	double Time_time,Time_space;
	clock_t start_time,end_time,start_space,end_space;
	char input = 'Q';
	start_space = clock();
	int32_t index_space = 2000000;
	while(index_space > 0 ){
		isUpperSpace(input);
		index_space--;
	}
	end_space = clock();
	

	start_time = clock();
	int32_t index_time = 2000000;
	while(index_time > 0 ){
		isUpperTime(input);
		index_time--;
	}
	end_time = clock();

	Time_space = ((double) (end_space - start_space))/CLOCKS_PER_SEC;
	Time_time = ((double)(end_time - start_time))/CLOCKS_PER_SEC;

	printf("Time taken by for space-efficient implementation %8g\n",Time_space);
	printf("Time for time-efficient implementation %8g\n",Time_time);


}


int32_t isUpperSpace(char c){
	return (c >= 'A' && c<='Z');
}

int32_t isUpperTime(char c ){
	return isupper(c);
}


