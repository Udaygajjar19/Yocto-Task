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

 /* cat: concatenate files, version 1 */ 
void cat(int argc, char *argv[]) { 
	int fp; 
	if (argc == 1) /* no args; copy standard input */ 
		filecopy(0, 1); 
	else 
		while(--argc > 0) 
			if ((fp = open(*++argv,O_RDONLY)) == -1) { 
				printf("cat: can't open %s\n", *argv); 
				return; 
			} else { 
				filecopy(fp, 1); 
				close(fp); 
			} 
	return; 
} 
/* filecopy: copy file ifp to file ofp */ 
void filecopy(int32_t ifp, int32_t ofp) 
{ 
	int32_t c;
	char buff[BUFSIZ];
	while ((c = read( ifp,buff,BUFSIZ)) > 0) {
		if ( write(ofp,buff,c ) != c ){
			printf("Error: in cat \n");
		}
	}
}

