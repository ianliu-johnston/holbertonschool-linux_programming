#include "hls.h"

/**
  * main - main fxn
  * @ac: Arg count
  * @argv: argument vectors
  * Return: Status code
  **/
int main(int ac, char *argv[])
{
	unsigned int num_ents;
#ifndef NO_DEBUG
	int i = 0;
#endif
	cmd_struct *args;
	struct stat *dirent;

	if (ac == 1)
	{
		print_dirs(".");
		return (SUCCESS);
	}
#ifndef NO_DEBUG
	printf("START DEBUGGING\n");
#endif
	args = parse_args(ac, argv);
#ifndef NO_DEBUG
	printf("Printing out args struct");
	printf("num_flags: %d\n");
	printf("flags: %p\n");
	for (i = 0; i < num_flags; i++)
		printf("  %d: %s", args->num_flags, args->flags[num_flags]);
	printf("num_ents: %d\n", args->num_ents);
	printf("dirents: %p\n", args->dirents);
	for (i = 0; i < num_dirents; i++)
		printf("  %d: %s", args->num_dirents, args->dirents[num_dirents]);
	printf("dirpaths: %p\n");
	for (i = 0; i < num_dirents; i++)
		printf("  %d: %s", args->num_dirpaths, args->dirpaths[num_dirents]);
#endif
	num_ents = args->num_ents;
	while ((dirent = args->dirents[num_ents]))
	{
#ifndef NO_DEBUG
		printf("S_ISDIR? %d\n", S_ISDIR(dirent->st_mode));
		printf("dirpath = %s\n", (char *)args->dirpaths[num_ents]);
#endif
		if (S_ISDIR(dirent->st_mode))
			print_dirs(args->dirpaths[num_ents]);
		else
			print_files(dirent, args->dirpaths[num_ents]);
		num_ents--;
	}
	free_cmd_struct(args);
	return (SUCCESS);
}
