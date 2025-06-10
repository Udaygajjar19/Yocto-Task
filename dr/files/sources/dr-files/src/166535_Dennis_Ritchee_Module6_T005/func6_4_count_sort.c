/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>


/* REQUIRED MACROS */
#define MAXWORD 1000
#define MAXLINES 1000

int32_t current_line_1 = 1;

typedef struct tnode {
        char *word;
        int count;
        int lines[100];
        int line_index;
        struct tnode *left;
        struct tnode *right;
} tnode;


tnode *talloc2(void){
        return (tnode *) malloc(sizeof(tnode));
}



struct tnode *addtree_6_4(struct tnode *p, char *w)
{
        int cond;

        if (p == NULL)
        {
                p = talloc2();
                p->word = strdup(w);
                p->count = 1;
                p->line_index = 0;
                p->lines[p->line_index++] = current_line_1;  // store line number
                p->left = p->right = NULL;
        }
        else if ((cond = strcasecmp(w, p->word) ) == 0)
        {
                p->count++;

                // Only add line number if it's different from the last one
                if (p->line_index == 0 || p->lines[p->line_index - 1] != current_line_1)
                {
                        if (p->line_index < MAXLINES)
                        {
                                p->lines[p->line_index++] = current_line_1;
                        }
                }
        }
        else if (cond < 0)
        {
                p->left = addtree_6_4(p->left, w);
        }
        else
        {
                p->right = addtree_6_4(p->right, w);
        }

        return p;
}
/*
void treePrint_line(struct tnode *p)
{
        if (p != NULL){
                treePrint_line(p->left);

                printf("%4d %s\tLines:", p->count, p->word);
                for (int i = 0; i < p->line_index; i++){
                        printf(" %d", p->lines[i]);
                }
                printf("\n");
                treePrint_line(p->right);
        }
}
*/
void tree_to_array(struct tnode *p, struct tnode **arr, int *index) {
    	if (p != NULL) {
        	tree_to_array(p->left, arr, index);
        	arr[(*index)++] = p;
        	tree_to_array(p->right, arr, index);
    	}
}

void sort_array(struct tnode *arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ( ( arr[j] ) -> count < ( arr[j + 1] ) -> count)
            {
                // Swap
                int temp = ( arr[j] ) -> count;
                ( arr[j] ) -> count = ( arr[j + 1] ) -> count;
                ( arr[j + 1] ) -> count = temp;
            }
        }
    }
}

void treePrint_sort_by_Word_count(struct tnode *root)
{
    	struct tnode *arr[MAXWORD];
    	int index = 0;

    	tree_to_array(root, arr, &index);

	sort_array(arr,index);
    	printf("Sorted by Word Frequency (Descending):\n");

    	for (int i = 0; i < index; i++) {
        	printf("%4d %s\tLines:", arr[i]->count, arr[i]->word);
        	for (int j = 0; j < arr[i]->line_index; j++) {
            		printf(" %d", arr[i]->lines[j]);
        	}
        	printf("\n");
    	}
}



void Word_Count_line_sort(int argc , char * argv[])
{
        struct tnode *root = NULL;
        char word[MAXWORD];
        FILE *fp =NULL;
        if (argc == 1){
                printf("Enter text (Ctrl+D to finish):\n");
                getchar();
                fp = stdin;
        }
        else{
                fp = fopen(argv[1], "r");

                if (!fp)
                {
                        perror("File opening failed");
                        return ;
                }
        }
        while (getword_read_file(word, 100, fp) != EOF)
        {
                if(is_noise(word))
                {
                        continue;
                }
                if (isalpha(word[0]) || word[0] == '_')
                {
                          root = addtree_6_4(root, word);
                }
        }
        treePrint_sort_by_Word_count(root);

        fclose(fp);
}
