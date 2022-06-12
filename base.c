
#include "totaller.h"

void input(char *prompt, char *result)
{
    char input_carr[128];
    char *find_endl;
    printf("%s", prompt);
    if (fgets(input_carr, sizeof(input_carr), stdin) != NULL) {
        find_endl = strchr(input_carr, '\n');
        if (find_endl)
            *find_endl = '\0';
        strcpy(result, input_carr);
    }
}

char *input_manylines()
{
    char *firstinputline = (char *)malloc(128);
    char *input_line = (char *)malloc(128);
    char *inputs = (char *)malloc(1024);
    memset(firstinputline, 0, 128);
    memset(input_line, 0, 128);
    memset(inputs, 0, 1024);
    input(">>> ", firstinputline);
    sprintf(inputs, "%s", firstinputline);
    if (firstinputline[strlen(firstinputline) - 1] != ';') {
        input("... ", input_line);
        while (input_line[0] != '\0') {
            sprintf(inputs, "%s\n%s", inputs, input_line);
            input("... ", input_line);
        }
    }
    return inputs;
}
