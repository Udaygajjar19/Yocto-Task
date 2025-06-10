/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

/* REQUIRED MACROS */
#define MAXLINES 1000
#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))
#define MAXWORD 100

struct key {
 char *word;
 int count;
 };
struct key keytab[] = {
        {"auto", 0},
        {"break", 0},
        {"case", 0},
        {"char", 0},
        {"const", 0},
        {"continue", 0},
        {"default", 0},
        {"do", 0},
        {"double", 0},
	{"define",0},
        {"else", 0},
        {"enum", 0},
        {"extern", 0},
        {"float", 0},
        {"for", 0},
        {"goto", 0},
        {"if", 0},
        {"inline", 0},
        {"int", 0},
        {"long", 0},
        {"register", 0},
        {"restrict", 0},
        {"return", 0},
        {"short", 0},
        {"signed", 0},
        {"sizeof", 0},
        {"static", 0},
        {"struct", 0},
        {"switch", 0},
        {"typedef", 0},
        {"union", 0},
        {"unsigned", 0},
        {"void", 0},
        {"volatile", 0},
        {"while", 0}
};



int Binsearch(char *word, struct key *tab, int n);

 /* count C keywords */
void  call_getword(){
 	int n;
 	char word[MAXWORD];
	FILE *fp = fopen("/home/bhavik_23/c_task/test_code.c","r");
	if (!fp){
		printf("Error opening the file");
		return;
	}
 	while (getword(word, MAXWORD,fp) != EOF)
 	if (isalpha(word[0])){
 		if ((n = Binsearch(word, keytab, NKEYS)) >= 0){
 			keytab[n].count++;
		}
	}
 	for (n = 0; n < NKEYS; n++){
 		if (keytab[n].count > 0)
 			printf("%4d %s\n",keytab[n].count, keytab[n].word);
	}
 	
}
 
/* binsearch: find word in tab[0]...tab[n-1] */
int Binsearch(char *word, struct key *tab, int n)
 {
 	int cond;
 	int low, high, mid;
 	low = 0;
 	high = n - 1;
 	while (low <= high) {
 		mid = (low+high) / 2;
 		if ((cond = strcmp(word, tab[mid].word)) < 0)
 			high = mid - 1;
 		else if (cond > 0)
 			low = mid + 1;
 		else
 			return mid;
 	}
 	return -1;
 }
/*void call_getword(){
	char word[MAXLINES];
	int32_t result = getword(word,100);
	printf("%d\n",result);
	printf("%s",result);
}
*/
int getword(char *word, int lim,FILE *fp){ 
 	int c; 
 	//void ungetch(int); 
 	char *w = word; 
 	while (isspace(c = fgetc(fp))) 
 		; 
 	if (c == EOF)
		return EOF;

 	*w++ = c; 
	/*handling underscore*/
 	if (isalpha(c)  || c == '_' ) {
	       for(;--lim>0;w++){
			c =fgetc(fp);
		 	if (!isalnum(c) && c != '_'){
				ungetc(c,fp);
				break;
			}	
			*w = c;
	       }	
 	} 
	/*handling for string*/
	else if( c == '"'){
		
		for(;--lim> 0 ; w++){
			*w =c = fgetc(fp);
			
			if (c == '"' || c == EOF )
				break;
		}
	}
	/*Comment handling*/
	else if (c == '/' ){
		if ((c=fgetc(fp)) == '/'){
			while ((c = fgetc(fp)) != '\n' && c != EOF)
				;
		}
		else if ((c == '*' )){
			while ((c = fgetc(fp)) != EOF ){
				if (c == '*' && (c = fgetc(fp)) == '/' )
					break;
			}
		}
		else {
			ungetc(c,fp);
		}

	}
	else if (c == '#'){
	/*	*w++ = c; */ /*Store the '#' */
    		while (--lim > 0) {
        		c = fgetc(fp);
        		if (c == EOF || isspace(c)) {
        	    		break;
        		}
        		*w++ = c;
		}
	}
	*w = '\0';
	return word[0];
} 








