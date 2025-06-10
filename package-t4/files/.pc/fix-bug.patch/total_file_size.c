#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

off_t get_total_size(const char *path
{
	DIR *dir;
	struct dirent *entry;
	struct stat statbuf;
	char fullpath[4096];
	off_t total_size = 0;

	dir = opendir(path);
	if( dir == NULL )
	{
		perror("opendir");
		return 0;
	}

	while(( entry = readdir(dir)) != NULL )
	{
		if( strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0 )
		{
			continue;
		}
		
		snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        	if (lstat(fullpath, &statbuf) == -1) 
		{
            		perror("lstat");
            		continue;
        	}

        	if (S_ISREG(statbuf.st_mode)) 
		{
            		total_size += statbuf.st_size;
        	} 
		else if (S_ISDIR(statbuf.st_mode)) 
		{
            		total_size += get_total_size(fullpath);
        	}
    	}

    	closedir(dir);
    	return total_size;
}

int main(int argc, char *argv[]) 
{
    	const char *start_path = (argc > 1) ? argv[1] : ".";
    	off_t total = get_total_size(start_path);
    	printf("Total size of regular files in '%s': %ld bytes\n", start_path, total);
    	return 0;
}

