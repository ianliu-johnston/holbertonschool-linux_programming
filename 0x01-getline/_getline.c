#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "_getline.h"
#include "_string.h"


char *_getline(int fd)
{
	static char buf[READ_SIZE];
	char *line;
	int index, bytes_read;
	static size_t bytes_total;
	static size_t offset;

	if (bytes_total <= offset || bytes_total == 0)
	{
		if ((bytes_read = read(fd, buf, READ_SIZE)) < 0)
			_memset(buf, '\0', READ_SIZE);
		bytes_total += bytes_read;
	}
	else
		bytes_read = 1;
	buf[bytes_total] = '\0';
	index = _strcspn(buf + offset, LINE_ENDINGS);
	line = malloc((index + 1)* sizeof(char));
	line = _strncpy(line, buf + offset, index);
	line[index] = '\0';
	offset += index + 1;

	return (bytes_read > 0 ? line : NULL);
}

int main(int ac, char *argv[])
{
	int fd;
	char *line;

	if (ac != 2)
		return (1);
	fd = open(argv[1], 0);
	line = NULL;
	while ((line = _getline(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	fd2 = open(argv[2], 0);
	while ((line = _getline(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
