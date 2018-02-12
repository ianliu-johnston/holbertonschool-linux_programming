#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

/**
 * main - entry point.
 *
 * Return: always 0.
 */
int main(int ac, char *argv[])
{
    int fd;
    char *line;

	if (ac != 2)
		fd = open("main.c", 0);
	else
		fd = open(argv[1], 0);
    while ((line = _getline(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}

/*
 * Additional tests:
 *  Carriage Return
 *  Vertical Tab
 *
 */
