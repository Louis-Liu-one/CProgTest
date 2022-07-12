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
## Source Input
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
>>>
```
In many-lines mode, type <kbd>Enter</kbd> to input a new line, type two <kbd>Enter</kbd>s to stop input many lines and run it.
## How to Quit
Input `@exit`+<kbd>Enter</kbd>+<kbd>Enter</kbd> or type <kbd>Ctrl</kbd>+<kbd>C</kbd> to quit.
