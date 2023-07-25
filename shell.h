#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#define BUFFSIZ 1024

/* tokenize function */
#define TOKENS_BUFF 64
#define DELIM " \t\r\n\a"

/* environment variable */
extern char **environ;

/* MAIN FXN -  functions */
void interactive_mode(void);
void non_interactive_mode(void);

/* string helper file */
int _strcmp(const char *, const char *);
char *_strcpy(char *, const char *);
char *_strcat(char *, const char *);
size_t _strlen(const char *);
int _strncmp(const char *, const char *, size_t);

/* string helper1 file */
char *str_tok(char *, const char *);
ssize_t _getline(char **, size_t *, FILE *);
char *_strdup(char *);
char **_strdup_arr(char **);
int _putchar(int);

/* interactive/non-interactive mode fxns*/
char *read_input(void);
char **_tokenize(char *);
int process_handler(char **);
int abs_path_cmd_runner(char **);
int cmd_runner(char **);


/* BUILT-IN FUNCTIONS */
int _cd(char **);
int _env(char **);
/*int my_exit(char **);*/

/* functions for finding path */
char *_getenv(char *);
char *get_path(char **);

#endif
