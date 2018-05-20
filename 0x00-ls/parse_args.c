#include "hls.h"

/**
  * print_usage - print out help
  * Return: NULL to bubble back.
  **/
void *print_usage(void)
{
	printf("Usage: hls [OPTION]... [FILE]...\nList information about the FILEs ");
	printf("(the current directory by default).\nSort entries alphabetically if");
	printf("none of -cftuvSUX nor --sort is specified.\n\nMandatory arguments t");
	printf("o long options are mandatory for short options too.\n    -a, --all ");
	printf("       do not ignore entrires starting with .\n");
	return (NULL);
}

/**
  * validate_flags - checks if the flags are valid
  * @flag: identified flag (starts with '-')
  * Return: TRUE or FALSE (1 or 0)
  **/
int validate_flags(char *flag)
{
	flag++;
	return (TRUE);
}

/**
  * verify_files - checks if the supplied files exist
  * @filepath: the path to the file
  * Return: TRUE or FALSE (1 or 0)
  **/
int verify_files(char *filepath)
{
	filepath++;
	return (TRUE);
}

/**
  * parse_args - parses arguments, and fills the cmd_struct
  * @ac: Argument count
  * @argv: Argument vectors
  * Return: TRUE or FALSE (1 or 0)
  **/
char *parse_args(int ac, char *argv[])
{
	int i;

	for (i = 0; i < ac; i++)
	{
		if (argv[i][0] == '-')
		{
#ifdef DEBUG
			printf("%s\n", argv[i][0]);
#endif
			if (validate_flags(argv[i]) == FALSE)
				return (print_usage());
		}
		else
		{
			if (verify_files(argv[i]) == FALSE)
				return (print_usage());
		}
		/* Fill cmd_args struct */

	}
	return ("tests");
}
