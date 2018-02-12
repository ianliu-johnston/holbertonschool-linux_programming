#include <stddef.h>
#ifndef STRING_H
#define STRING_H

int _strlen(const char *str);
int _strcspn(char *haystack, const char *needle);
void *_memset(void *s, int c, size_t n);
char *_strncpy(char *dest, const char *src, size_t n);

#endif
