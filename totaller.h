
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void input(char *prompt, char *result);
char *input_manylines();
int catch_signal(int sig, void (*handler)(int));
