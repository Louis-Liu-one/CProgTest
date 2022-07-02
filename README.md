# CProgTest - 命令行的C工具
此文档非完整文档，`CProgTest`尚未完成，此文档与`CProgTest`源文件将不断更新。
## 概述
`CProgTest`使用C语言编写，是C语言的命令行REPL。可以看到，它看起来很像`python3`：
```
$ python3
Python 3.10.0 (v3.10.0:b494f5935c, Oct  4 2021, 14:59:20) [Clang 12.0.5 (clang-1205.0.22.11)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
```
```python
>>> print("Hello!")
Hello!
>>> exit
Use exit() or Ctrl-D (i.e. EOF) to exit
>>> exit()
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
## 代码输入
### 单行
单行代码直接输入即可，等待一段时间就可以看到结果（如果有的话）：
```C
>>> int sum = 0;  // wait a few seconds ...
>>>
```
### 多行
因为单行代码结尾都是`;`，所以当程序检测到结尾不是`;`时，就会认为用户输入的是多行代码：
```C
>>> int sum = 0;
>>> for (int i = 0; i < 101; ++i)  // a for loop is not end of `;`
...     sum += i;
...
>>>
```
在多行输入时，按一次回车另起一行代码，按两次回车退出并执行多行代码。
## 退出方式
输入`@exit`或按<kbd>Ctrl</kbd>+<kbd>C</kbd>即可退出。
