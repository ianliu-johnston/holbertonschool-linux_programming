#include <string.h>
#include "_getline.h"

/**
  * _getline - get characters until a newline
  * @fd: file descriptor to get characters from
  * Return: Malloc'd space that has the line in it.
  */
char *_getline(const int fd)
{
	static char buf[READ_SIZE];
	char *line;
	unsigned int index;
	int bytes_read = 0;
	static size_t bytes_total;
	static size_t offset;

	if (bytes_total <= offset || bytes_total == 0)
	{
		bytes_read = read(fd, buf, READ_SIZE);
		if (bytes_read <= 0) /* if eof, zero out buffer. */
		{
			memset(buf, '\0', READ_SIZE);
			return (NULL);
		}
		bytes_total += bytes_read;
	}
	index = _strcspn(buf + offset, LINE_ENDINGS);
	line = malloc((index + 1) * sizeof(char));
	line = strncpy(line, buf + offset, index);
	line[index] = '\0';
	offset += index + 1;
	return (line);
}
