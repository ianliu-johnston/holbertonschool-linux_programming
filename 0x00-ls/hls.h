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
#include "error_codes.h"

#define TRUE 1
#define FALSE 0

/**
  * struct cmd_s - Holds a struct of directory entries, and flags
  * @num_flags: asdf
  * @flags: asdf
  * @num_ents: asd
  * @dirents: asd
  * @dirpaths: asd
  */
typedef struct cmd_s
{
	/* Flags */
	unsigned int num_flags;
	char **flags;

	/* Dirents */
	unsigned int num_ents;
	struct stat **dirents;
	char **dirpaths;
} cmd_struct;

typedef struct stat files_stat;

/* Files */
int print_files(struct stat *dirent, char *filepath);
int print_dirs(char *dirpath);
void print_dirents(cmd_struct *args, char *delimiter);

/* Args */
cmd_struct *parse_args(int ac, char *argv[]);
void free_cmd_struct(cmd_struct *args);

/* Utils */
unsigned int _strlen(char *str);
void _bzero(void *buf, size_t n);

/* Debugging fxns */
#ifndef NO_DEBUG
void print_cmd_struct(cmd_struct *args);
#endif

#endif
