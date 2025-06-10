/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

/* REQUIRED MACROS */
#define MAX_LINE 1000
#define LINES_PER_PAGE 50


void call_print_file(int argc, char *argv[]) {
        FILE *fp;

        if (argc < 2) {
                fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
                return ;
        }

        for (int32_t i = 1; i < argc; i++) {
                fp = fopen(argv[i], "r");
                if (fp == NULL) {
                        fprintf(stderr, "Could not open file: %s\n", argv[i]);
                        continue;
                }

                print_file(fp, argv[i]);
                fclose(fp);
        }
}

void print_file(FILE *fp, const char *filename) {
        char line[MAX_LINE];
        int32_t line_count = 0;
        int32_t page = 1;

        /* Print first page header */
        printf("\f");  /* Form feed: start new page */
        printf("File: %s\t\tPage: %d\n\n", filename, page);

        while (fgets(line, MAX_LINE, fp)) {
                if (line_count >= LINES_PER_PAGE) {
                        page++;
                        line_count = 0;
                        printf("\f");  /* New page */
                        printf("File: %s\t\tPage: %d\n\n", filename, page);
                }

                fputs(line, stdout);
                line_count++;
        }

}

