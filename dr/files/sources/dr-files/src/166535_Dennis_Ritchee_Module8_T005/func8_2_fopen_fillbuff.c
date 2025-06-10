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
#define PERMS 0666 /* RW for owner, group, others */
#define OPEN_MAX 20 

struct flag_field{
	uint32_t is_read:1;
        uint32_t is_write:1;
        uint32_t is_unbuf:1;
        /*uint32_t is_buf:1;*/
        uint32_t is_eof:1;
        uint32_t is_err:1;

};


typedef struct _iobuf { 
 	int cnt; /* characters left */ 
 	char *ptr; /* next character position */ 
 	char *base; /* location of buffer */ 
 	struct flag_field flag; /* mode of file access */ 
 	int fd; /* file descriptor */ 
} _FILE;




_FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */ 
	{ 0, NULL, NULL,{1,0,0,0,0}, 0 }, 
	{ 0, NULL,NULL, {0,1,0,0,0}, 1 }, 
	{ 0, NULL, NULL,{0,1,1,0,0}, 2 } 
};


_FILE *Fopen_bitfield(char *name, char *mode)
{
        int fd;
        _FILE *fp;
        if (*mode != 'r' && *mode != 'w' && *mode != 'a')
                return NULL;
        for (fp = _iob; fp < _iob + OPEN_MAX; fp++){
                if (fp->flag.is_read == 0 && fp->flag.is_write == 0)
                        break; /* found free slot */
	}
        if (fp >= _iob + OPEN_MAX) /* no free slots */
                return NULL;

        if (*mode == 'w')
                fd = creat(name, PERMS);
        else if (*mode == 'a') {
                if ((fd = open(name, O_WRONLY, 0)) == -1)
                        fd = creat(name, PERMS);
                lseek(fd, 0L, 2);
        } else
                fd = open(name, O_RDONLY, 0);
        if (fd == -1) /* couldn't access name */
                return NULL;
        fp->fd = fd;
        fp->cnt = 0;
        fp->base = NULL;

	fp->flag.is_unbuf = 0;
	/*fp->flag.is_buf = 1;*/
	fp->flag.is_eof = 0;
	fp->flag.is_err = 0;

        if (*mode == 'r') {/*read*/
		fp->flag.is_read =1;
		fp->flag.is_write = 0;
	}
	else{/*write*/
		fp->flag.is_read =0;
		fp->flag.is_write = 1;
	}
        return fp;
}




/* _fillbuf: allocate and fill input buffer */
int _fillbuf_bitfield(_FILE *fp)
{
        int bufsize;
        if (fp->flag.is_read ==0 || fp->flag.is_eof == 1 || fp->flag.is_err == 1)
                return EOF;
        bufsize = (fp->flag.is_unbuf == 1) ? 1 : BUFSIZ;
        if (fp->base == NULL) /* no buffer yet */
                if ((fp->base = (char *) malloc(bufsize)) == NULL)
                        return EOF; /* can't get buffer */
        fp->ptr = fp->base;
        fp->cnt = read(fp->fd, fp->ptr, bufsize);
        if (--fp->cnt < 0) {
                if (fp->cnt == -1)
                        fp->flag.is_eof = 1;
                else
                        fp->flag.is_err = 1;
                fp->cnt = 0;
                return EOF;
        }
        return (unsigned char) *fp->ptr++;
}

int fgetc_bitfield(_FILE *fp) {
    	if (fp->cnt <= 0) {
        	if (_fillbuf_bitfield(fp) == EOF) {
            		return EOF;
        	}
    	}
    	fp->cnt--;
    	return (unsigned char)*fp->ptr++;
}


void call_fopen_bitfield(){
	_FILE *fp = Fopen_bitfield("/home/bhavik_23/c_task/test_code.c","r");
	if (fp == NULL)
	{
		printf("failed open file.\n");
		return;
	}
	int32_t c;
	c = _fillbuf_bitfield(fp);
	putchar(c);
	while((c = fgetc_bitfield(fp)) != EOF){
		putchar(c);
	}

}
/* --------------------------EX_8_3--------------------- */

int32_t _flushbuf(int32_t c,_FILE *fp){
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



int FFlush(_FILE *fp) {
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



int Fclose(_FILE *fp) {
        int result = 0;

        if (fp == NULL)
                return EOF;

        result = FFlush(fp);

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


void call_flush(){
	_FILE *fp = Fopen_bitfield("/home/bhavik_23/c_task/test_code.c","w");
        if (fp == NULL)
        {
                printf("failed open file.\n");
                return;
        }
	for (int i = 0; i < 32; ++i) {
        	_flushbuf('A'+i, fp);
    	}
	printf("File has been written\n");

	FFlush(fp);

    	Fclose(fp);
}
/* EX_8_4 */
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
}


void call_Fseek(){
	 _FILE *fp = Fopen_bitfield("/home/bhavik_23/c_task/test_code.c","r");
        if (fp == NULL)
        {
                printf("failed open file.\n");
                return;
        }
	Fseek(fp,7,SEEK_SET);
	int c = _fillbuf_bitfield(fp);
	putchar(c);
}


/*
_FILE *Fopen(char *name, char *mode) 
{ 
	int fd; 
	_FILE *fp; 
	if (*mode != 'r' && *mode != 'w' && *mode != 'a') 
		return NULL; 
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++) 
		if ((fp->flag & (_READ | _WRITE)) == 0) 
			break;*/ /* found free slot */ 
	/*if (fp >= _iob + OPEN_MAX) *//* no free slots */ 
		/*return NULL; 

	if (*mode == 'w') 
		fd = creat(name, PERMS); 
	else if (*mode == 'a') { 
		if ((fd = open(name, O_WRONLY, 0)) == -1) 
			fd = creat(name, PERMS); 
		lseek(fd, 0L, 2); 
	} else 
		fd = open(name, O_RDONLY, 0); 
	if (fd == -1)*/ /* couldn't access name */ 
	/*	return NULL; 
	fp->fd = fd; 
	fp->cnt = 0; 
	fp->base = NULL; 
	fp->flag = (*mode == 'r') ? _READ : _WRITE; 
	return fp; 
} 

*/


/* _fillbuf: allocate and fill input buffer */
/*int _fillbuf(_FILE *fp)
{
	int bufsize;
	if ((fp->flag&(_READ|_EOF_ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) *//* no buffer yet */
		/*if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;*/ /* can't get buffer */
	/*fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
*/
