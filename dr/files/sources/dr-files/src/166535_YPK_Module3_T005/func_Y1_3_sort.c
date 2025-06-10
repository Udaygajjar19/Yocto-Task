/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000

void sort_string(){
	/*declaring the names array*/
	char *names[7] = {
		"Santosh",
		"Amol",
		"Santosh Jain",
		"Kishore",
		"Rahul",
		"Amolkumar",
		"Hemant"
	};

	/*Displaying the unsorted array*/
	printf("unsorted names are:\n");
	int32_t index,index1;
	for(index = 0;index<7;index++){
		printf("%s\n",names[index]);
	}
	

	/*using strcmp sorting the array of names*/
	char *temp;
	/*check all the element one after another*/
	for(index1 = 0;index1<6;index1++){
		/*finds the one element with having largest and puts it to last*/
		for(index = 0;index<(6-index1);index++){
			if(strcmp(names[index],names[index+1]) > 0){
				/*if diff is positve then sending the names to next index */
				temp = names[index];
				names[index] = names[index +1];
				names[index+1]=temp;	
			}
		}
	}


	/*Final sorted array*/
	printf("Sorted names are:\n");
	for(index = 0;index<7;index++){
                printf("%s\n",names[index]);
        }
}


