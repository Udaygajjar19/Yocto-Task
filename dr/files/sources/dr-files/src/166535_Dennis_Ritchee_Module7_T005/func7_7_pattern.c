/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

/* REQUIRED MACROS */
#define MAX_LINE 1000


void call_pattern(int argc, char *argv[]) {
        char *pattern;
        FILE *fp;

        if (argc < 2) {
                fprintf(stderr, "Usage: ./%s <pattern> [file...]\n", argv[0]);
                return;
        }

        pattern = argv[1];

        if (argc == 2) {
                /* No files provided, use stdin*/
                find_pattern(stdin, "stdin", pattern);
        } else {
                for (int i = 2; i < argc; i++) {
                        fp = fopen(argv[i], "r");
                        if (fp == NULL) {
                                fprintf(stderr, "Could not open file: %s\n", argv[i]);
                                continue;
                        }
                        find_pattern(fp, argv[i], pattern);
                        fclose(fp);
                }
        }

}

void find_pattern(FILE *fp, const char *filename, const char *pattern) {
        char line[MAX_LINE];
        int line_number = 0;

        while (fgets(line, MAX_LINE, fp)) {
                line_number++;
                if (strstr(line, pattern) != NULL) {
                        printf("%s:%d:\t%s\n", filename, line_number, line);
                }
        }
}

