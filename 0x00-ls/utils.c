#include "hls.h"

/**
  * _strlen - get length of string
  * @str: string to measure
  * Return: length of string
  **/
unsigned int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
  * _bzero - zero out a buffer up to n bytes
  * @buf: Buffer to zero out
  * @n: number of bytes to zero out to
  **/
void _bzero(void *buf, size_t n)
{
	char *tmp;

	if (!buf)
		return;
	tmp = (char *)buf;
	while (n != 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
}
