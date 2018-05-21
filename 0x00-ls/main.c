#include "hls.h"

/**
  * main - main fxn
  * @ac: Arg count
  * @argv: argument vectors
  * Return: Status code
  **/
int main(int ac, char *argv[])
{
	cmd_struct *args;

#ifndef NO_DEBUG
	printf("Begin Program\n\n");
#endif
	if (ac == 1)
	{
		print_dirs(".");
#ifndef NO_DEBUG
		goto end;
#endif
		return (SUCCESS);
	}
	args = parse_args(ac, argv);
#ifndef NO_DEBUG
	print_cmd_struct(args);
#endif
	print_dirents(args, "  ");
	free_cmd_struct(args);

#ifndef NO_DEBUG
end: printf("\n\nEnd of Program\n\n");
#endif
	return (SUCCESS);
}
