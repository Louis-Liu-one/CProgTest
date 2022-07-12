# CProgTest - Type C Source in Command Line
*Comment: This document is incomplete,`CProgTest` is incomplete too. This document and `CProgTest` sources will still update.*
## Abstract
`CProgTest` is coding by C Programming Language, it's a C's REPL. You see, it looks like `python3`:
```python
$ python3
Python 3.10.0 (v3.10.0:b494f5935c, Oct  4 2021, 14:59:20) [Clang 12.0.5 (clang-1205.0.22.11)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> print("Hello!")
Hello!
>>> exit
Use exit() or Ctrl-D (i.e. EOF) to exit
>>> exit()
$
```
```C
$ ./CProgTest
>>> int sum = 0;
>>> for (int i = 0; i < 101; ++i)
...     sum += i;
...
>>> printf("%i\n", sum);
5050
>>> @exit
...
exit
$
```
## Normal Source Input
### Input One Line
If you want to input one line, just input and wait a second, then you can see the output (or the error info)：
```C
>>> int sum = 0;  // wait a few seconds ...
>>>
```
### Input Many Lines
If `CProgTest` sees your source is not ended by `;`, `CProgTest` will think you are inputing many lines like `for` loop:
```C
>>> int sum = 0;
>>> for (int i = 0; i < 101; ++i)  // a for loop is not end of `;`
...     sum += i;
...
>>> printf("%i\n", sum);
5050
>>>
```
In many-lines mode, type <kbd>Enter</kbd> to input a new line, type two <kbd>Enter</kbd>s to stop input many lines and run it.
## How to Include a Header File
Just type `#include <header-file.h>` and two <kbd>Enter</kbd>s in `CProgTest`, then you can include `header-file.h`. When `CProgTest` sees you input a source starts with `#include`, then it thinks you want to include a header file.
`CProgTest` will include `stdio.h` first because it's very important. Some frequently-used functions like `printf` are in `stdio.h`. You can do not include `stdio.h` and use these functions.
```C
>>> #include <stdlib.h>  // Include stdlib.h
...
>>> #include <string.h>  // Include string.h
...
>>> char *p = (char *)malloc(100);  // The function malloc needs stdlib.h
>>> memset(p, 0, 100);  // The function memset needs string.h
>>> free(p);
>>>
```
### `#include` in Many-Lines Mode
`#include` cannot use in many-lines mode, except this situation:
```C
>>> #include <stdlib.h>
... #include <string.h>
...
>>>
```
## How to Quit
Input `@exit`+<kbd>Enter</kbd>+<kbd>Enter</kbd> or type <kbd>Ctrl</kbd>+<kbd>C</kbd> to quit.
