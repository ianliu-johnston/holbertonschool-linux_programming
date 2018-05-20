#include "hls.h"

/**
  * print_files - print the names of your files
  * @dirname: directory to list
  * Return: Status code
  **/

int print_files(char *dirname)
{
	DIR *dir;
	struct dirent *read;
	char *delineator;

#ifndef NO_DEBUG
	printf("~~~Inside of print_files function~~~\n");
#endif
	dir = opendir(dirname);
	read = readdir(dir);
	while (read)
	{
		printf("%s", read->d_name);
		read = readdir(dir);
		delineator = read ? "  " : "\n";
		printf("%s", delineator);
	}
	closedir(dir);
	return (0);
}
