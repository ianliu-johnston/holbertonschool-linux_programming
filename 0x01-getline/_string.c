#include <stdio.h>
#include <string.h>
#include "_string.h"
/**
  * _strlen - Get length of string
  * @str: string to measure
  * Return: measurement
 **/
int _strlen(const char *str)
{
	int i = 0;

	while (str[++i] != '\0')
		;
	return (i);
}

/**
  * _strstr - find any characters that are in a string in another string
  * @haystack: string to search in
  * @needle: characters to search for
  * Return: pointer to first instance of any character in needle or NULL if not found
 **/
int _strcspn(char *haystack, const char *needle)
{
	int i, j;

	i = 0;
	j = 0;

	if (haystack == NULL || needle == NULL)
		return 0;
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
	return 0;
}

void *_memset(void *s, int c, size_t n)
{
	return (memset(s, c, n));
}

char *_strncpy(char *dest, const char *src, size_t n)
{
	return (strncpy(dest, src, n));
}
