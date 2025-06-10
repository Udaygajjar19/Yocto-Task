/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#include <fcntl.h>
#include <unistd.h>

/*
int32_t Fseek(_FILE *fp,long offset,int32_t origin){
	if (fp == NULL)
		return -1;
	if (fp->flag.is_write){
		if(FFlush(fp) == EOF)
			return -1;
	}

	else if (fp->flag.is_read){
		if (origin == SEEK_CUR){
			offset -= fp->cnt;
		}
	}

	long pos = lseek(fp->fd,offset,origin);
	if (pos == -1)
		return -1;
	
	fp->cnt = 0;
	fp -> ptr = fp->base;

	fp->flag.is_eof = 0;
	
	return 0;
}*/
