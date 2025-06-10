/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

/* REQUIRED MACROS */
#define HASHSIZE 101
#define MAXWORD 1000


struct nlist { /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name */
	char *defn; /* replacement text */
};


static struct nlist *hashtab[HASHSIZE]; /* pointer table */



/* hash: form hash value for string s */ 
unsigned hash(char *s) 
 	{ 
 	unsigned hashval; 
 	for (hashval = 0; *s != '\0'; s++) 
 		hashval = *s + 31 * hashval; 
  
	return hashval % HASHSIZE; 
 	} 



/* lookup: look for s in hashtab */ 
struct nlist *lookup(char *s) 
{ 
	struct nlist *np; 
	for (np = hashtab[hash(s)]; np != NULL; np = np->next) 
		if (strcmp(s, np->name) == 0) 
			return np; /* found */ 
	return NULL; /* not found */ 
}




/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) { /* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL){
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else{ /* already there */
		free((void *) np->defn); /*free previous defn */
	}
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char *name){
	unsigned hashval = hash(name);

	struct nlist *temp,*prev= NULL;
	temp = hashtab[hashval];
	while(temp){
		if (strcmp(name,temp->name) == 0){
			if(prev == NULL){
				hashtab[hashval] = temp->next;
				free(temp->name);
				free(temp->defn);
				free(temp);
			}
			else{
				prev->next = temp->next;
				free(temp->name);
				free(temp->defn);
				free(temp);
			}
			return;
		}
		prev = temp;
		temp = temp->next;
	}
	printf("name:%s not found in the hashTable!\n",name);
}

void Display_hashTable(struct nlist *np){
	for(int32_t i=0;i<HASHSIZE;i++){
		for (np = hashtab[i]; np != NULL; np = np->next) {
			printf("%s\t|\t%s\n",np->name,np->defn);
		}
	}
}



void call_hashTable(){
	struct nlist *head = NULL;
	head = install("name1","1");
	head = install("name2","2");
	head = install("name3","3");
	undef("name3");

	Display_hashTable(head);

}


struct nlist *head1 = NULL;
void hash_define(){

        char word[MAXWORD];
        char name[MAXWORD],defn[MAXWORD];
        FILE *fp =fopen("/home/omrathod/c_task/testcode.c","r");
	if (!fp) {
        	printf("Failed to open file\n");
        	return;
    	}
	printf("NAME\t|     DEFINETION\n");
        while(getword(word,MAXWORD,fp) != EOF){
                if (strcasecmp(word,"#define") == 0){
                        if (getword(name, MAXWORD, fp) == EOF) break;
                        if (getword(defn, MAXWORD, fp) == EOF) break;
                        
			
			head1 = install(name, defn);
                }
        }
	fclose(fp);
}


void call_hash_define(){
	hash_define();
        Display_hashTable(head1);
}
