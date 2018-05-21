#include "hls.h"

/**
  * print_dirs - print the names of your files
  * @dirpath: directory to list
  * Return: Status code
  **/
int print_dirs(char *dirpath)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(dirpath);
	if (dir == NULL)
		exit(DIROPENERROR);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] == '.')
			continue;
		printf("%s  ", read->d_name);
	}
	putchar('\n');
	closedir(dir);
	return (SUCCESS);
}

/**
  * print_files - print a file
  * @dirent: lstat of the dirent
  * @filepath: path of the file
  * Return: status code
  **/
int print_files(struct stat *dirent, char *filepath)
{
	printf("is %s a file? %d\n", filepath, S_ISDIR(dirent->st_mode));
	return (SUCCESS);
}
