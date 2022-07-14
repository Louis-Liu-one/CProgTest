
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

extern char *inmain, *outofmain, *includes, *inputs, *input_line;
extern char *lastone_inmain, *lastone_inputs, *lastone_includes;
extern char *writenow;

void input(char *prompt, char *result);
char *input_manylines();
int catch_signal(int sig, void (*handler)(int));
int is_startswith(const char *str1, char *str2);

typedef enum {
    NONE, EXIT, OUTMAIN, INMAIN
} magic_method;

magic_method magic_method_getter(char *input_line);
void magic_method_runner(magic_method magic_method_no);
void magic_method_exit();
void magic_method_outmain();
void magic_method_inmain();
