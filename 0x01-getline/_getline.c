#include <string.h>
#include "_getline.h"

/**
  * _getline - get characters until a newline
  * @fd: file descriptor to get characters from
  * Return: Malloc'd space that has the line in it.
  */
char *_getline(const int fd)
{
	char buf[BUFSIZE];
	char readbuf[READ_SIZE];
	/*
*	char *line_endings = "\n\r\v";
	*/
	static size_t bytes_total;

	int bytes_read = 0;
	unsigned int j = 0;
	unsigned int index = 0;
	unsigned int index_of_nl = READ_SIZE;
	char *line;

	while (index_of_nl == READ_SIZE)
	{
		bytes_read = read(fd, readbuf, READ_SIZE);
		printf("readbuf <%s>\n", readbuf);
		if (bytes_read <= 0) /* if eof, zero out buffer. */
		{
			memset(buf, '\0', BUFSIZE);
			return (NULL);
		}
		bytes_total += bytes_read;
		for (j = 0; readbuf[j] != '\n' && j < READ_SIZE; j++)
			;
		readbuf[j] = '\0';
		index_of_nl = j;
		for (j = 0; j <= index_of_nl; j++)
			buf[index + j] = readbuf[j];
		index += index_of_nl;
	}
	buf[index] = '\0';
	line = malloc((index + 1) * sizeof(char));
	line = strncpy(line, buf, index);
	line[index] = '\0';
	return (line);
}
