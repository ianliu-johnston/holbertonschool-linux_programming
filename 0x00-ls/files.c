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

printf("~~~Inside of print_files function~~~\n");
	dir = opendir(dirname);
	read = readdir(dir);
	while (read)
	{
		printf("%s", read->d_name);
		read = readdir(dir);
		delineator = read ? "  " : "\n";
		printf("%s", delineator);
	}
	return (0);
}
