#ifndef __TYPES_EXAMPLE_HPP__
#define __TYPES_EXAMPLE_HPP__

#include "log.macros.hpp"

struct A {
  void add() { LOG_MACROS(A, add); };
};

// this version fails on gcc (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4
// error message: ‘A’ is not an accessible base of ‘B’
// struct B : protected A {
// struct B : private A {
  struct B {
  void push() { LOG_MACROS(B, push); };
};

struct C {
  void push() { LOG_MACROS(C, add); };
};

#endif  // __TYPES_EXAMPLE_HPP__
