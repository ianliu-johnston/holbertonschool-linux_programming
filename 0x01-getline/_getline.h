#ifndef GETLINE_H
#define GETLINE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"

#define LINE_ENDINGS "\n\r\v"
#define READ_SIZE 1024
char *_getline(int fd);

#endif
