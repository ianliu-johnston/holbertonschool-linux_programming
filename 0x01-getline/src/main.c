#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

/**
 * main - entry point.
 * @ac: arg count
 * @av: arg vectors
 * Return: always 0.
 */
int main(int ac, char *av[])
{
	int fd;
	char *line;
	char *filename = "testings";

	if (ac > 1)
		filename = av[1];
	fd = open(filename, 0);
	while ((line = _getline(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
