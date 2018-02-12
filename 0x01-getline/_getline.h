#ifndef GETLINE_H
#define GETLINE_H

#define LINE_ENDINGS "\n\r\v"
#define READ_SIZE 1024
int _strcspn(char *haystack, const char *needle);
char *_getline(int fd);

#endif
