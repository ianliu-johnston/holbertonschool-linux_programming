#include "utils.h"
#include <stdio.h>
#define NOTFOUND 0
/**
  * _strcspn - Get the length of a string without a set of characters
  * @haystack: string to search in
  * @needle: characters to search for
  * Return: pointer to first instance of any character
  *		 in needle or 0 if not found
 **/
unsigned int _strcspn(char *haystack, const char *needle)
{
	unsigned int i, j;

	printf("%s\n", haystack);
	if (haystack == NULL || needle == NULL)
		return (NOTFOUND);
	for (i = 0; needle[i] != '\0'; i++)
	{
		for (j = 0; haystack[j] != '\0'; j++)
			if (needle[i] == haystack[j])
				return (j);
	}
	return (NOTFOUND);
}

