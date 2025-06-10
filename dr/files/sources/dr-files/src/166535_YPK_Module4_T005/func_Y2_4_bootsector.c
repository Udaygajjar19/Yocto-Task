/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>
#include"main.h"

/* REQUIRED MACROS */
#define SECTOR_SIZE 512
#define MAXLINE 1000


void dir_file_read(){
	char sub_dirname[MAXLINE];
        char dirname[MAXLINE] = "/home/omrathod/";
        char buffer[MAXLINE] = {0};
        printf("Enter dir path: ");
        scanf(" %s", sub_dirname);
	strcat(dirname,sub_dirname);
        /*opens the search dir*/
	DIR *dirp = opendir(dirname);
	if (dirp == NULL) {
                /*if there is no file searched for*/
                printf("Error: Unable to open directory\n");
                closedir(dirp);
                return;
        }

	/* getting dir struct and then reading from opended dirname*/
        struct dirent *dir;
        dir = readdir(dirp);
	if (dir == NULL) {
                /*if there is no file searched for*/
                printf("Error: directory is empty\n");
                closedir(dirp);
                return;
        }
	printf("Name of file is -> %s\n", dir->d_name);
        printf("-----------------FILE CONTENT-------------\n");
        
        strcat(dirname,"/");

        strcat(dirname, dir->d_name);

	/* giving full path to fopen to read file and store in buffer */
        FILE *fptr = fopen(dirname, "r");
        fread(buffer, 1000, 1, fptr);
	/* Displaying the content of file opened */
        for(int32_t index = 0; buffer[index] != '\0'; index++){
                printf("%c", buffer[index]);
        }
        fclose(fptr);

}
	


/*
void bootsector_read(){
	int32_t hard_disk;
	uint8_t buffer[SECTOR_SIZE];
	ssize_t bytesRead;*/
	/*using the fcntl lib device sda is opend*/
	//hard_disk = open("/dev/sda",O_RDONLY);

	/* open will return -1 if file couldnt open */
	/*if(hard_disk == -1){
		printf("Error: could not open the disk device");
		return;
	}*/
	/* reads bytes from dev/sda and stores in buffer using unistd */
	/*bytesRead = read(hard_disk,buffer,SECTOR_SIZE);
	*//* if it could read all the bytes then error */
	/*if (bytesRead != SECTOR_SIZE) {
        	printf("Error: reading boot sector");
        	close(hard_disk);
        	return;
    	}
	*/
	/* prints the buffer in 32 x 16 pattern */
	/*for (int32_t i = 0; i < SECTOR_SIZE; i++) {
        	printf("%02x ", buffer[i]);
        	if ((i + 1) % 16 == 0) {
      			printf("\n");
		}
	}*/
	/*closing the file using the unistd lib*/
	//close(hard_disk);
//}
