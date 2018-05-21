#include "hls.h"

/**
  * print_cmd_struct - print out a cmd_struct
  * @args: the struct to print
  **/

void print_cmd_struct(cmd_struct *args)
{
	unsigned int i = 0;

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
}
