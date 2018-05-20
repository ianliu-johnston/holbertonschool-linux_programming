#include "hls.h"
#define DIROPENERROR 1

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
	delineator = "";
	dir = opendir(dirname);
	if (dir == NULL)
		return (DIROPENERROR);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] == '.')
			continue;
		printf("%s%s", delineator, read->d_name);
		delineator = "  ";
	}
	putchar('\n');
	closedir(dir);
	return (0);
}
