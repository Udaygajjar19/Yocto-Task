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

int32_t current_line = 1;

int32_t is_noise(char *word){
	static const char *noise_words[] = {
        	"a", "an", "and", "the", "is", "to", "at","am", "i", "from", "as", "being", "my"
    	};
	int32_t count = sizeof(noise_words) / sizeof(noise_words[0]);

	for (int32_t i =0; i < count ; i++){
		if (strcasecmp(word,noise_words[i]) == 0) return 1;
	}
	return 0;
}
typedef struct tnode {
    	char *word;
    	int count;
    	int lines[100];
	int line_index;
    	struct tnode *left;
    	struct tnode *right;
} tnode;


tnode *talloc1(void){
        return (tnode *) malloc(sizeof(tnode));
}

int32_t getword_read_file(char *word, int lim, FILE *fp)
{
        int ch;
        char *w = word;
        while (isspace(ch = fgetc(fp)))
        {
                if (ch == '\n') {
    			current_line++;
		}

        }
        if (ch == '"')
        {
                while ((ch = fgetc(fp)) != '"' && ch != EOF)
                {
                        if (ch == '\n')
                        {
                                current_line++;
                        }
                }
                return getword_read_file(word, lim, fp);
        }
        if (ch == '#')
        {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF)
                {
                        ;
                }
                current_line++;
                return getword_read_file(word, lim, fp);
        }
        if (ch == '/' && (ch = fgetc(fp)) == '*')
        {
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF)
                {
                        if (ch == '\n')
                        {
                                current_line++;
                        }
                        if (prev == '*' && ch == '/')
                        {
                                break;
                        }
                        prev = ch;
                }
                return getword_read_file(word, lim, fp);
        }
        if (ch != EOF)
        {
                *w++ = ch;
        }
        if (!isalpha(ch) && ch != '_')
        {
                *w = '\0';
                return ch;
        }
        for (; --lim > 0; w++)
        {
                ch = fgetc(fp);
		if (ch == EOF)
                        {
				break;
                        }
                if (!isalnum(ch) && ch != '_')
                {
			if (ch == '\n'){
				ungetc(ch,fp);
			}
			else{
				ungetc(ch,fp);
			}
                        break;
                }
                *w = ch;
        }
        *w = '\0';
        return word[0];
}




struct tnode *addtree_6_3(struct tnode *p, char *w)
{
    	int cond;

    	if (p == NULL)
    	{
        	p = talloc1();
        	p->word = strdup(w);
        	p->count = 1;
        	p->line_index = 0;
        	p->lines[p->line_index++] = current_line;  // store line number
        	p->left = p->right = NULL;
    	}
    	else if ((cond = strcasecmp(w, p->word)) == 0)
    	{
        	p->count++;

        	// Only add line number if it's different from the last one
        	if (p->line_index == 0 || p->lines[p->line_index - 1] != current_line)
        	{
        	    	if (p->line_index < MAXLINES)
            		{
                		p->lines[p->line_index++] = current_line;
            		}
        	}
    	}
    	else if (cond < 0)
    	{
        	p->left = addtree_6_3(p->left, w);
    	}
    	else
    	{
    	    	p->right = addtree_6_3(p->right, w);
    	}

    	return p;
}

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

void Word_Count_line(int argc , char * argv[])
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
                          root = addtree_6_3(root, word);
                }
        }
        treePrint_line(root);

        fclose(fp);
}
