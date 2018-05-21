#include "hls.h"

/**
  * main - main fxn
  * @ac: Arg count
  * @argv: argument vectors
  * Return: Status code
  **/
int main(int ac, char *argv[])
{
	if (ac == 1)
	{
		print_files(".");
		return (0);
	}
	/*
	* parse_args(ac, argv);
	*/
	print_files(argv[1]);
	return (0);
}
