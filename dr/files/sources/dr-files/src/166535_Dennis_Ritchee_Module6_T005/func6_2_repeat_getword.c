/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>


#define MAXWORD 100

typedef struct tnode{
	char *word;
	int32_t count;
	struct tnode *left;
	struct tnode *right;

}tnode;
void call_main(FILE *fp,int32_t n );
tnode *addtree(tnode *p, char *w);
void treeprint();
tnode *talloc(void);

//int32_t n = 6;

void treeprint1(struct tnode *p,int32_t n) {
    if (p != NULL) {
        treeprint1(p->left,n);
	if (strlen(p->word) >= n){
        	printf("%d %s\n", p->count, p->word);
      	}
        treeprint1(p->right,n);
    }
}

void call_main(FILE *fp, int32_t n){
	
	struct tnode* root = NULL;
	
	char word[MAXWORD];


	while (getword(word, MAXWORD,fp) != EOF){
		if (isalpha(word[0])){
			root = addtree(root, word);
		}
	}
	 printf("word frequency:\n");
        treeprint1(root,n);
	printf("similar upto n:\n");
	treeprint(root,n);
	
}



tnode *addtree(tnode *p, char *w){
	int32_t cond;
	if (p == NULL){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p -> right = NULL;
	}
	else if ((cond = strcmp(w,p->word))  == 0){
		p->count++;
	}
	else if (cond < 0){
		p->left = addtree(p->left,w);
	}

	else {
		p->right = addtree(p->right,w);
	}
	return p;	
}


int prefix_match_count(tnode *p, const char *prefix, int n) {
    	if (!p) return 0;

    	int count = 0;
    	char temp[MAXWORD];
    	strncpy(temp, p->word, n);
    	temp[n] = '\0';

    	if (strncmp(prefix, temp, n) == 0)
        	count++;

    	return count + prefix_match_count(p->left, prefix, n) + prefix_match_count(p->right, prefix, n);
}


void treeprint(tnode *p, int32_t n){
	static char last_prefix[MAXWORD]="";
	if (p != NULL){
		//_Bool flag =0;
		treeprint(p->left,n);
		
		char prefix[MAXWORD];
		strncpy(prefix,p->word,n);
		prefix[n] = '\0';
		/*if (strlen(p->word) < n){
			flag =1;
		}*/
		if (strncmp(prefix,last_prefix,n) != 0 /* && flag == 0*/){
			int32_t count = prefix_match_count(p,prefix,n);
			if (count > 1){
				printf("\n%s\n",prefix);
				strncpy(last_prefix,prefix,n);
			}
		}
		if (strncmp(prefix, last_prefix, n) == 0 ){
			printf("  %d %s\n",p->count,p->word);
		}
		treeprint(p->right,n);
	}	
}


tnode *talloc(void){
	return (tnode *) malloc(sizeof(tnode));
}






