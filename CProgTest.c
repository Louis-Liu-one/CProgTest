
#include "totaller.h"

char *inmain, *outofmain, *includes, *inputs, *input_line;
char *lastone_inmain, *lastone_inputs;

void cleanup(int sig)
{
    puts("exit");
    free(inmain);
    free(outofmain);
    free(includes);
    free(inputs);

    free(lastone_inmain);
    free(lastone_inputs);
    exit(0);
}

int main()
{
    inmain = (char *)malloc(2048);
    outofmain = (char *)malloc(2048);
    includes = (char *)malloc(256);
    inputs = (char *)malloc(4532);

    lastone_inmain = (char *)malloc(2048);
    lastone_inputs = (char *)malloc(4532);

    FILE *ctestfile;

    memset(inmain, 0, 2048);
    memset(outofmain, 0, 2048);
    memset(includes, 0, 256);
    memset(inputs, 0, 4532);

    memset(lastone_inmain, 0, 2048);
    memset(lastone_inputs, 0, 4532);

    sprintf(includes, "%s\n", "#include <stdio.h>");

    catch_signal(SIGINT, cleanup);
    while (strcmp((input_line = input_manylines()), "@exit") != 0) {
        sprintf(lastone_inputs, "%s", inputs);
        sprintf(lastone_inmain, "%s", inmain);
        sprintf(inmain, "%s%s\n", inmain, input_line);
        sprintf(inputs, "%s%sint main() {\n%s}", includes, outofmain, inmain);
        ctestfile = fopen("testfile.c", "w");
        fprintf(ctestfile, "%s", inputs);
        fclose(ctestfile);
        if (system("gcc testfile.c -o testfile && ./testfile") != 0) {
            ctestfile = fopen("testfile.c", "w");
            fprintf(ctestfile, "%s", lastone_inputs);
            fclose(ctestfile);
            sprintf(inputs, "%s", lastone_inputs);
            sprintf(inmain, "%s", lastone_inmain);
        }
        free(input_line);
    }

    cleanup(0);
    return 0;
}
