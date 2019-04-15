# Cplusplus.TemplateMetaProgramming

[![](https://img.shields.io/badge/Author-jskyzero-brightgreen.svg?style=flat)]()
[![](https://img.shields.io/badge/Data-2019/04/15-brightgreen.svg?style=flat)]()
[![Build Status](https://travis-ci.com/oYOvOYo/Cplusplus.SFINAE.svg?branch=master)](https://travis-ci.com/oYOvOYo/Cplusplus.SFINAE)
[![CodeFactor](https://www.codefactor.io/repository/github/oyovoyo/cplusplus.sfinae/badge)](https://www.codefactor.io/repository/github/oyovoyo/cplusplus.sfinae)
[![](https://img.shields.io/badge/C%2B%2B-11-blue.svg?style=flat)]()

## Overview

"Substitution Failure Is Not An Error"

> This rule applies during overload resolution of function templates: When substituting the explicitly specified or deduced type for the template parameter fails, the specialization is discarded from the overload set instead of causing a compile error.
> 
> 此规则适用于函数模板的重载解析期间：当替换显式指定或推断的类型的模板参数失败时，将从重载集中丢弃特化而不是导致编译错误。

## Structure
```
.
├── LICENSE                   // MIT LICENSE
├── README.md                 // intriduction file
├── include                   // header files
│   ├── add.universal.hpp     // 通用的add函数，会根据实例方法来调用add或者push
│   ├── log.macros.hpp        // 日志宏，用于命令行打印日志
│   ├── main.hpp              // 普通的头文件X1
│   ├── types.example.hpp     // 用于测试的类
│   └── version.hpp           // 普通的头文件X2
├── makefile                  // make rule
└── src                       // source files
    ├── main.cpp              // 程序入口
    └── version.cpp           // 用于测试汇编代码
```

## Tips
```cpp
template <typename TYPE>
auto add_universal(TYPE instance)
    -> decltype(instance.add(), std::declval<void>()) {
  // call add
  instance.add();
}

template <typename TYPE>
auto add_universal(TYPE instance)
    -> decltype(instance.push(), std::declval<void>()) {
  // call push
  instance.push();
}

void add_universal(...) {
  LOG_MACROS(NULL, NULL);
}
```
返回值类型为`(decltype(instance.add(), std::declval<void>())`中的后半部分的void，但是编译过程中会尝试`instance.add()`，失败后进行下一次尝试，最后由优先级最低的`void add_universal(...)`匹配。

```cpp
template <typename ReturnType, typename...A>
ReturnType GetReturnType(ReturnType(*)(A...));

B bb();
C cc();
auto b = decltype(bb())();
auto c = decltype(GetReturnType(cc))();
auto dd = []() -> int {};
decltype(dd()) d = 0;

```
只是换了种声明初始化方式，没什么特别的。

## Reference
+ [How do you get assembler output from C/C++ source in gcc?](https://stackoverflow.com/questions/137038/how-do-you-get-assembler-output-from-c-c-source-in-gcc)
+ [SFINAE](https://en.cppreference.com/w/cpp/language/sfinae)
+ [placeholder type specifiers](https://en.cppreference.com/w/cpp/language/auto)
+ [decltype specifier](https://en.cppreference.com/w/cpp/language/decltype)
+ [Get decltype of function](https://stackoverflow.com/questions/32887979/get-decltype-of-function)
+ [Compiler standards support (c++11, c++14, c++17)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2634.html)
+ [Solving the SFINAE problem for expressions](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2634.html)
