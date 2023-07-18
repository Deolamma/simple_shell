#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#define BUFFSIZ 1024
/* MAIN FXN -  functions */
void interactive_mode(void);
void non_interactive_mode(void);

/* string helpers */
int _strcmp(const char *, const char *);
char *_strcpy(char *, const char *);
char *_strcat(char *, const char *);
size_t _strlen(const char *);
char *str_tok(char *, const char *);
ssize_t _getline(char **, size_t *, FILE *);

#endif
