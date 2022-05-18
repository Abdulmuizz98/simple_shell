#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
char **split_string_words(char *text);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int putprompt(void);
char *commandline(char *nline, ssize_t nread);
#endif /*MAIN_H*/
