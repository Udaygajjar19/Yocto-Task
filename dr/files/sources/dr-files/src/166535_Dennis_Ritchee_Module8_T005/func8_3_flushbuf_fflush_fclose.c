/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#include <fcntl.h>
#include <unistd.h>

/* REQUIRED MACROS */
/*

int32_t _flushbuf(int32_t x,_FILE *fp){
	uint32_t num_written;
	int32_t bufsize;
	if (fp->flag.is_write == 0 || fp == NULL  )
		return EOF;

	bufsize = (fp->flag.is_unbuf) ? 1 : BUFSIZ;

	if (fp -> base == NULL){
		if ((fp->base = (char *) malloc(bufsize)) == NULL){
			fp->flag.is_err = 1;
			return EOF;
		}
	}
	else{
		num_written = write(fp->fd, fp->base, fp->ptr - fp->base);
		if (num_written != fp->ptr - fp->base){
			fp->flag.is_err = 1;
			return EOF;
		}
	}
	fp->ptr = fp->base;
    	*fp->ptr++ = c;
   	fp->cnt = bufsize - 1;

    	return (unsigned char)c;
}



int fflush_bitfield(_FILE *fp) {
    	if (fp == NULL)
        	return 0;

    	if (fp->flag.is_write && fp->base != NULL) {
        	int num_written = write(fp->fd, fp->base, fp->ptr - fp->base);
        	if (num_written != fp->ptr - fp->base) {
            		fp->flag.is_err = 1;
            		return EOF;
        	}
    	}

    	fp->ptr = fp->base;
    	fp->cnt = (fp->flag.is_unbuf) ? 0 : BUFSIZ;

    	return 0;
}



int fclose_bitfield(_FILE *fp) {
    	int result = 0;

    	if (fp == NULL)
        	return EOF;

    	result = fflush_bitfield(fp);

    	if (close(fp->fd) == -1)
        	result = EOF;

    	if (fp->base != NULL)
        	free(fp->base);

    	fp->fd = -1;
    	fp->cnt = 0;
    	fp->ptr = NULL;
    	fp->base = NULL;
    	fp->flag.is_read = fp->flag.is_write = fp->flag.is_err = fp->flag.is_eof = 0;

    	return result;
}



*/

