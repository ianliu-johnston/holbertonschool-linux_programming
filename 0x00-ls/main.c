#include "hls.h"

/**
  * main - main fxn
  * @ac: Arg count
  * @argv: argument vectors
  * Return: Status code
  **/
int main(int ac, char *argv[])
{
	unsigned int num_ents = 0;
#ifndef NO_DEBUG
	unsigned int i = 0;
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
	printf("\n\nPrinting out args struct\n\n");
	printf("num_flags: %d\n", args->num_flags);
	printf("flags: %p\n", (void *)args->flags);
	for (i = 0; i < args->num_flags; i++)
		printf("  %d: %s\n", args->num_flags, args->flags[args->num_flags]);
	printf("num_ents: %d\n", args->num_ents);
	printf("dirents: %p\n", (void *)args->dirents);
	printf("dirpaths: %p\n", (void *)args->dirpaths);
	for (i = 0; i < args->num_ents; i++)
	{
		printf("  %d:", args->num_ents);
		printf("%i\n", (int)args->dirents[args->num_ents]->st_ino);
		printf("  %d: %s", args->num_ents, args->dirpaths[args->num_ents]);
	}
	printf("\n\nFinished Printing\n\n");
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

#ifndef NO_DEBUG
	printf("\n\nEnd of Program\n\n");
#endif
	return (SUCCESS);
}
