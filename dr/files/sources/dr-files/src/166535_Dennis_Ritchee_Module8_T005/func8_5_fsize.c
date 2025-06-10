/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/* REQUIRED MACROS */

#define MAX_PATH 1024 

/* dirwalk: apply fcn to all files in dir */ 
void dirwalk(char *dir, void (*fcn)(char *)) 
{ 
	char d_name[MAX_PATH]; 
	struct dirent *dp; 
	DIR *dfd; 
	if ((dfd = opendir(dir)) == NULL) { 
		fprintf(stderr, "dirwalk: can't open %s\n", dir); 
		return; 
	} 
	while ((dp = readdir(dfd)) != NULL) { 
		if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) 
			continue; /* skip self and parent */ 
		if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(d_name)) 
			fprintf(stderr, "dirwalk: d_name %s %s too long\n", dir, dp->d_name); 
		else { 
			sprintf(d_name, "%s/%s", dir, dp->d_name); 
			(*fcn)(d_name); 
		} 
	} 
	closedir(dfd); 
} 

/* fsize: print the d_name of file "d_name" */
void fsize(char *d_name)	{
 	struct stat stbuf;
 	if (stat(d_name, &stbuf) == -1) {
 		fprintf(stderr, "fsize: can't access %s\n", d_name);
 		return;
 	}
 	{
	printf("inode no. | mode(octal) | no. of link | size | d_name\n");
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(d_name, fsize);
	printf("%5lu\t   %6u\t  %3lu\t %8ld\t%s\n",stbuf.st_ino,stbuf.st_mode,stbuf.st_nlink, stbuf.st_size, d_name);
	}
}
