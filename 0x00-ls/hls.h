#ifndef HLS
#define HLS
#include <dirent.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int print_files(char *dirname);
char *parse_args(int ac, char *argv[]);
#endif
