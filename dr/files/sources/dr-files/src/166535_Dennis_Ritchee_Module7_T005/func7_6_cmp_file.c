/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>


/* REQUERED MACROS */
#define MAX 1000

void call_fileCmp(int32_t argc,char *argv[]){
	FILE *file1,*file2;
	if (argc != 3){
		printf("Enter argument like ./a.out <File 1> <File 2>\n");
		return;
	}
	else{
		if ((file1 = fopen(argv[1],"r")) == NULL){
			printf("File 1 could'nt open \n");
			return;
		}
		else if ((file2 = fopen(argv[2],"r")) == NULL){
                        printf("File 2 could'nt open \n");
                        return;
                }
		else{
			cmpFile(file1,file2);
			printf("both files do have same contents\n");
			fclose(file1);
			fclose(file2);
		
		}
	}
}


void cmpFile(FILE* Src,FILE *Dest){
	char src_str[MAX];
	char dest_str[MAX];
	char *lp1,*lp2;
	do{	
		lp1 = fgets(src_str,MAX,Src);
		lp2 = fgets(dest_str,MAX,Dest);
		if (lp1 == src_str && lp2 == dest_str ){
			if (strcmp(src_str,dest_str) != 0){
				printf("files are not same,from below line its different.\n%s\n",src_str);
				lp1 = lp2 = NULL;	
			}
		}
		else if (lp1 != src_str  && lp2 == dest_str) {
			printf("end of first file at line.\n%s\n",lp2);
		}
		else if (lp1 == src_str  && lp2 != dest_str){
			printf("end of second file at line.\n%s\n",lp1);
		}
	}while(lp1 != NULL && lp1 != NULL );

}

