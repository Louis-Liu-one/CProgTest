
#include "totaller.h"

void (*magic_method_handlers[])() = {
    NULL,
    magic_method_exit,
};

magic_method magic_method_getter(char *input_line)
{
    if (input_line[0] == '@') {
        if (is_startswith("@exit", input_line))
            return EXIT;
    }
    return NONE;
}

void magic_method_runner(magic_method magic_method_no)
{
    (magic_method_handlers[magic_method_no])();
}

void magic_method_exit()
{
    raise(SIGINT);
}
