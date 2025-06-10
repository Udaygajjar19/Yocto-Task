/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#include <fcntl.h>
#include <unistd.h>

#include <dirent.h>

/* REQUIRED MACROS */

void *Calloc(uint32_t n,uint32_t size){
	uint32_t i ,nb;
	char *p,*q;

	nb = n*size;
	if ((p = q = malloc(nb)) != NULL ){
		for (i=0;i < nb; i++)
			*(p++);
		return q;
	}
	return NULL;

}


void call_Calloc(){
	int32_t *arr;
	arr= Calloc(100,sizeof(int32_t));
	if (arr == NULL) {
        	printf("Memory allocation failed\n");
        	return;
    	}

    	for (int i = 0; i < 5; i++) {
        	arr[i] = i;
		printf("arr[%d] = %d\n", i,arr[i]);  
    	}

    	free(arr);  

}
