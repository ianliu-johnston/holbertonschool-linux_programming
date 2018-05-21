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

	if (!dirpath)
		return (1);
	printf("\n\n%s:\n", dirpath);
	dir = opendir(dirpath);
	if (dir == NULL)
		exit(DIROPENERROR);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] == '.')
			continue;
		printf("%s  ", read->d_name);
	}
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
	printf("%s:%d", filepath, S_ISDIR(dirent->st_mode));
	return (SUCCESS);
}

/**
  * print_dirents - print all directory entries
  * @args: all stats stored in memory
  * @delimiter: what chars to print out
  **/
void print_dirents(cmd_struct *args, char *delimiter)
{
	unsigned int i;
	struct stat *dirent;

	/* struct stat tmp_swap_buf; */
	for (i = 0; i < args->num_ents; i++)
	{
		dirent = args->dirents[i];
		if (S_ISDIR(dirent->st_mode) != 0)
		{
			print_dirs(args->dirpaths[i]);
		}
		else
		{
			printf("%s", i == 0 ? "" : delimiter);
			print_files(dirent, args->dirpaths[i]);
		}
	}
	putchar('\n');
}
