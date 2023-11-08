#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

char *get_path_check(char *command);
extern char **environ;
extern char *token;
extern char *line;
extern char *delimiters;
extern char *command_arguments[];
/* Builtin prototypees */
void cd_builtin(char *arg);
void exit_builtin(void);
/*other helping functions */
int compare_strings(const char *string1, const char *string2);
char *concatenate_strings(char *destination, char *sourc);

int _pid(char *command_arguments[]);
void env_builtin(void);
void error_message(char *command);

/* functions*/
void handle_comments(char *input);
size_t calculate_length(const char *str);
char *check_path(char *cmd);
int tokenize(char *input);
int start_new_program(char *args[]);
void handle_signal(int sig);
void print_error_message(char *cmd);
void print_environment(void);


#endif /* SHELL_H */
