/* Description  ->  This is a program to display and change the attributes of files present on the disk.
 * Author       -> Om Rathod
 * Created      -> 10 March 2025
 * Modified     -> 10 March 2025
 */

/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include <time.h>
#include"main.h"
 
/* Function  ->  This is a Function to display and change the attributes of files present on the disk.
 * Author       -> Om Rathod
 * Created      -> 10 March 2025
 * Modified     -> 10 March 2025
 */
void print_file_attributes()
{
	/*struct stat uses the inbluid header sys/stat*/
    	struct stat File_Stats;
    	char path[100];
	/*user input path to get file attributes*/
	printf("Enter file or directory path: ");
    	scanf("%s",path);
 
    	if (stat(path, &File_Stats) < 0)
    	{
        	printf("Error: File not Found\n");
        	return;
    	}
 	
	/*Displaying the file path*/
    	printf("File: %s\n", path);
	/*prints size of file*/
    	printf("Size: %ld bytes\n", File_Stats.st_size);
    	/*displays user group other permission only*/
	printf("Permissions of file: %o\n", File_Stats.st_mode & 0777);
	print_permissions(File_Stats.st_mode);
	print_file_type(File_Stats.st_mode);
	/*displays last accessed timestamp*/
	printf("Last accessed: %s", ctime(&File_Stats.st_atime));
    	/*displays last modified timestamp*/
	printf("Last modified: %s", ctime(&File_Stats.st_mtime));
    	/*displays last status changed*/
	printf("Last status change: %s", ctime(&File_Stats.st_ctime));
	

	/* changing the given file permission*/
	printf("-----------------upadating the permission-------------\n");
	change_permission(path);
	stat(path, &File_Stats);
	print_permissions(File_Stats.st_mode);

}
/* Function     -> This is a Function to change permission
 * Author       -> Om Rathod
 * Created      -> 10 March 2025
 * Modified     -> 10 March 2025
 */
void change_permission(char * path){
	
	mode_t updated_permission;
	printf("change the permission: ");
	scanf("%o",&updated_permission);
	/*function to change the permission*/
	chmod(path,updated_permission);

}


/* Function  	-> This is a Function to print file type
 * Author       -> Om Rathod
 * Created      -> 10 March 2025
 * Modified     -> 10 March 2025
 */
void print_file_type(mode_t mode) {
	printf("File Type: ");
	/*printing the type of file it is*/
	if (S_ISREG(mode))  printf("Regular File\n");
	else if (S_ISDIR(mode))  printf("Directory\n");
	else if (S_ISLNK(mode))  printf("Symbolic Link\n");
	else if (S_ISCHR(mode))  printf("Character Device\n");
	else if (S_ISBLK(mode))  printf("Block Device\n");
	else if (S_ISFIFO(mode)) printf("FIFO (Named Pipe)\n");
	else if (S_ISSOCK(mode)) printf("Socket\n");
	else printf("Unknown\n");
}

/* Function  ->  This is a Function to print file permissions in rwx format.
 * Author       -> Om Rathod
 * Created      -> 10 March 2025
 * Modified     -> 10 March 2025
 */

void print_permissions(mode_t mode) {
    	printf("Permissions: ");
	/*checks the bits and if its set then prints permission accordingly*/
    	printf((mode & S_IRUSR) ? "r" : "-");
    	printf((mode & S_IWUSR) ? "w" : "-");
    	printf((mode & S_IXUSR) ? "x" : "-");
    	printf((mode & S_IRGRP) ? "r" : "-");
    	printf((mode & S_IWGRP) ? "w" : "-");
    	printf((mode & S_IXGRP) ? "x" : "-");
    	printf((mode & S_IROTH) ? "r" : "-");
    	printf((mode & S_IWOTH) ? "w" : "-");
    	printf((mode & S_IXOTH) ? "x" : "-");
    	printf("\n");
}
