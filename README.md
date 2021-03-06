# CProgTest - Type C Source in Command Line
*Comment: This document is incomplete,`CProgTest` is incomplete too. This document and `CProgTest` sources will still update.*
## Abstract
`CProgTest` (C Program Tester) is coding by C Programming Language, it's a C's REPL. You see, it looks like `python3`:
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
## Magic Methods
The magic methods in `CProgTest` is always start with `@`. They can do something *like a magic*. They are very useful:
| Magic method | Meaning                            |
|:------------:|:---------------------------------- |
| `@exit`      | Quit the program                   |
| `@outmain`   | Write the sources outside `main()` |
| `@inmain`    | Write the sources inside `main()`  |
### Magic method `@exit`
You can use magic method `@exit` to quit `CProgTest`. It will raise `SIGINT` signal. Like this:
```C
>>> @exit
exit
$
```
You can also type <kbd>Ctrl</kbd>+<kbd>C</kbd> to quit.
### Magic methods `@outmain` and `@inmain`
You can use these magic methods to write your sources in different places like this:
```C
>>> @outmain
>>> int var1 = 100;    // var1 is a global variable
>>> int var2 = 1000;   // var2 is a global variable too
>>> @inmain
>>> int var3 = 10000;  // var3 is a local variable in main()
>>> printf("1=%i, 2=%i, 3=%i\n", var1, var2, var3);
1=100, 2=1000, 3=10000
>>>
```
`@outmain` will write the sources outside `main()` and `@inmain` will write the sources inside `main()`. If you didn't use these magic methods, your sources will write inside `main()`.
## Known BUGs
### `printf`
If you type two `printf`s in `CProgTest`, your program will look strange like this:
```C
>>> printf("A: Hello world!\n");
A: Hello world!
>>> printf("B: Hello world!\n");
A: Hello world!
B: Hello world!
>>>
```
`CProgTest` get your inputs and write into a file. Then it will compile and run it. So if you type two `printf`s, `CProgTest` will write two `printf`s into the file. Then you will see two `printf`s' result. `CProgTest` will add a magic method named `@getvar` to repair this BUG.
## Download
Download this package and type `make` in command line, then you can use `CProgTest` in your computer.
```bash
$ cd CProgTest/
$ make
gcc -c CProgTest.c
gcc -c base.c
gcc -c magic-method.c
gcc CProgTest.o base.o magic-method.o -o CProgTest
$ make clean
rm *.o
$ ./CProgTest
>>> @exit
exit
$
```
