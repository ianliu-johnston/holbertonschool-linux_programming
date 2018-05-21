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
	printf("o long options are mandatory for short options too.\n	-a, --all ");
	printf("	   do not ignore entrires starting with .\n");
	return (NULL);
}

/**
  * validate_flags - checks if the flags are valid
  * @flag: identified flag (starts with '-')
  * Return: TRUE or FALSE (1 or 0)
  **/
int validate_flags(char *flag)
{
	int i, j;
	char valid_flags[6];

	valid_flags[0] = '1';
	valid_flags[1] = 'a';
	valid_flags[2] = 'A';
	valid_flags[3] = 'l';
	valid_flags[4] = 'h';
	valid_flags[5] = 'R';
	valid_flags[6] = '\0';

	j = 0;
	for (i = 1; flag[i] != '\0'; i++)
	{
		if (j == 5)
			return (FALSE);
		for (j = 0; valid_flags[j] != '\0'; j++)
			if (flag[i] == valid_flags[j])
				continue;
		printf("%c\n", valid_flags[j]);
	}
	return (TRUE);


}

/**
  * check_dirent - checks if the supplied files exist
  * @filepath: the path to the file
  * Return: TRUE or FALSE (1 or 0)
  **/
files_stat *check_dirent(char *filepath)
{
	struct stat *stat_buf;
	int status;

	stat_buf = malloc(sizeof(struct stat));
	if (!stat_buf)
	{
		perror("BAD DOG");
		return (NULL);
	}
	_bzero((void *)stat_buf, sizeof(struct stat));
	status = lstat(filepath, stat_buf);
	if (status == -1)
	{
		perror("You are wrong");
		return (NULL);
	}
	return (stat_buf);
}

/**
  * parse_args - parses arguments, and fills the cmd_struct
  * @ac: Argument count
  * @argv: Argument vectors
  * Return: TRUE or FALSE (1 or 0)
  **/
cmd_struct *parse_args(int ac, char *argv[])
{
	int i;
	char pwd_flag = FALSE;
	unsigned int num_flags = 0;
	unsigned int num_ents = 0;

	cmd_struct *args;

#ifndef NO_DEBUG
	printf("in cmd_struct *parse_args\n\n");
	printf("step one: malloc\n");
#endif
	args = malloc(sizeof(cmd_struct));
	if (!args)
	{
		perror("WHYY malloc?!?");
		return (NULL);
	}
	_bzero(args, sizeof(cmd_struct));
#ifndef NO_DEBUG
	printf("step two: count args\n");
#endif
	for (i = 1; i < ac; i++)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0')
			num_flags++;
		else
			num_ents++;
	}

#ifndef NO_DEBUG
	printf("step three: start malloc-ing\n");
#endif
	if (num_flags > 0)
	{
		args->flags = malloc(sizeof(char *) * num_flags + 1);
		if (!args->flags)
			return (NULL);
		_bzero(args->flags, sizeof(char *) * num_flags + 1);
	}

	if (num_ents == 0)
	{
		num_ents++;
		pwd_flag = TRUE;
	}
	args->dirents = malloc(sizeof(struct stat) * num_ents + 1);
	if (!args->dirents)
		return (NULL);
	_bzero(args->dirents, sizeof(char *) * num_ents + 1);

	args->dirpaths = malloc(sizeof(struct stat) * num_ents + 1);
	if (!args->dirpaths)
		return (NULL);
	_bzero(args->dirpaths, sizeof(char *) * num_ents + 1);

	args->num_flags = num_flags;
	args->num_ents = num_ents;

#ifndef NO_DEBUG
printf("step four: done malloc-ing\n");
#endif

	for (i = 1; i < ac; i++)
	{
#ifndef NO_DEBUG
		printf("step five: start to fill_struct: %d\n", i);
#endif
		if (pwd_flag || (argv[i][0] != '-' && argv[i][1] != '\0'))
		{
			args->dirents[num_ents] = check_dirent(pwd_flag ? "." : argv[i]);
			args->dirpaths[num_ents--] = pwd_flag ? "." : argv[i];
		}
		else if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			validate_flags(argv[i]);
			args->flags[num_flags--] = argv[i];
		}
	}

#ifndef NO_DEBUG
	printf("args->dirpaths: %s\n", args->dirpaths[1]);
	printf("Exiting Function\n\n");
#endif
	return (args);
}


/**
  * free_cmd_struct - Frees the command structure from memory
  * @args: The command structure
  **/
void free_cmd_struct(cmd_struct *args)
{
	struct stat *dirent;

#ifndef NO_DEBUG
	printf("\nEntering free_cmd_struct fxn\n");
#endif
	if (args->num_ents > 0)
	{
		while ((dirent = args->dirents[args->num_ents--]))
		{
#ifndef NO_DEBUG
			printf("num_ents: %d\n", args->num_ents);
			printf("dirpath: %s\n", args->dirpaths[args->num_ents]);
#endif
			free(dirent);
			dirent = NULL;
		}
		free(args->dirents);
		free(args->dirpaths);
		args->dirents = NULL;
	}
	args->dirpaths = NULL;

#ifndef NO_DEBUG
	printf("Finished Freeing dirents\n");
	printf("Starting to free flags\n");
#endif

	if (args->num_flags > 0)
	{
		free(args->flags);
		args->flags = NULL;
	}
	free(args);
	args = NULL;
#ifndef NO_DEBUG
	printf("Exiting free_cmd_struct Function\n\n");
#endif
}
