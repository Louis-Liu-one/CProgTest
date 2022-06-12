
#include "totaller.h"

int main()
{
    char *inmain = (char *)malloc(2048);
    char *outofmain = (char *)malloc(2048);
    char *includes = (char *)malloc(256);
    char *inputs = (char *)malloc(4532);
    char *input_line = (char *)malloc(128);
    FILE *ctestfile;

    memset(inmain, 0, 2048);
    memset(outofmain, 0, 2048);
    memset(includes, 0, 256);
    memset(inputs, 0, 4532);
    memset(input_line, 0, 128);

    sprintf(includes, "%s\n", "#include <stdio.h>");

    while ((input_line = input_manylines()) != NULL) {
        sprintf(inmain, "%s%s\n", inmain, input_line);
        sprintf(inputs, "%s%sint main() {\n%s}", includes, outofmain, inmain);
        ctestfile = fopen("testfile.c", "w");
        fprintf(ctestfile, "%s", inputs);
        fclose(ctestfile);
        system("gcc testfile.c -o testfile && ./testfile");
    }

    return 0;
}
