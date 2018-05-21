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

	dir = opendir(dirname);
	if (dir == NULL)
		exit(1);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] == '.')
			continue;
		printf("%s  ", read->d_name);
	}
	putchar('\n');
	closedir(dir);
	return (0);
}
