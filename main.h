#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
void execute(char **argv);
char *location(char *command);
char *_getenv(const char *name);
void print_environment(void);
extern char **environ;
#endif /* MAIN_H */
