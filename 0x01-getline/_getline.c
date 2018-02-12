#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "_getline.h"
/**
  * _strcspn - Get the length of a string without a set of characters
  * @haystack: string to search in
  * @needle: characters to search for
  * Return: pointer to first instance of any character
  *         in needle or NULL if not found
 **/
int _strcspn(char *haystack, const char *needle)
{
	int i, j;

	i = j = 0;

	if (haystack == NULL || needle == NULL)
		return (0);
	while (needle[i] != '\0')
	{
		while (haystack[j] != '\0')
		{
			if (needle[i] == haystack[j])
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}


/**
  * _getline - get characters until a newline
  * @fd: file descriptor to get characters from
  * Return: Malloc'd space that has the line in it.
  */
char *_getline(int fd)
{
	static char buf[READ_SIZE];
	char *line;
	int index, bytes_read;
	static size_t bytes_total;
	static size_t offset;

	if (bytes_total <= offset || bytes_total == 0)
	{
		bytes_read = read(fd, buf, READ_SIZE)
		if (bytes_read < 0)
			memset(buf, '\0', READ_SIZE);
		bytes_total += bytes_read;
	}
	else
		bytes_read = 1;
	buf[bytes_total] = '\0';
	index = _strcspn(buf + offset, LINE_ENDINGS);
	line = malloc((index + 1) * sizeof(char));
	line = strncpy(line, buf + offset, index);
	line[index] = '\0';
	offset += index + 1;

	return (bytes_read > 0 ? line : NULL);
}
