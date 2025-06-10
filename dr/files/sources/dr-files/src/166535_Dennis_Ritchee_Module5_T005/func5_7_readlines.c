
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"

/* REQUIRED MARCOS */
#define MAXLINES 5000  /* max #lines to be sorted */
#define MAXLEN 1000    /* max length of any input line */
#define MAXSTOR 5000
#define ALLOCSIZE 10000 /* size of memory buffer */


char *lineptr[MAXLINES]; /* pointers to text lines */

/* Function prototypes */
int getLine(char *, int);
char *alloc(int);
int readlines(char *lineptr[],char *linestore, int nlines);
void writelines(char *lineptr[], int nlines);
void Qsort(char *lineptr[], int left, int right);
void Swap(char *v[], int i, int j);

/* Buffer for alloc */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* Main function */
void call_readlines() {
    int nlines; /* number of input lines read */
    char linestore[MAXSTOR];
    if ((nlines = readlines(lineptr,linestore,MAXLINES)) >= 0) {
        Qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return;
    } else {
        printf("error: input too big to sort\n");
        return;
    }
}

/* Function to read lines */
int readlines(char *lineptr[],char *linestore, int maxlines) {
    	int len, nlines;
    	char *p, line[MAXLEN];
	p= linestore;
	char *linestop = linestore + MAXSTOR;
    	nlines = 0;
    	while ((len = getLine(line, MAXLEN)) > 0) {
        	if (nlines >= maxlines || p+len > linestop)
            		return -1;
        	else {
            		line[len - 1] = '\0'; /* remove newline */
            		strcpy(p, line);
            		lineptr[nlines++] = p;
			p += len;
        	}
    	}
    	return nlines;
}

/* Function to write lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* Quicksort implementation */
void Qsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) return; // Base case: 1 or 0 elements

    Swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            Swap(v, ++last, i);

    Swap(v, left, last);
    Qsort(v, left, last - 1);
    Qsort(v, last + 1, right);
}

/* Swap function */
void Swap(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* getline function (renamed to avoid conflict) */
int getLine(char *s, int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* Memory allocator */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}



