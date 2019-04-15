#ifndef __TYPES_EXAMPLE_HPP__
#define __TYPES_EXAMPLE_HPP__

#include "log.macros.hpp"

struct A {
  void add() { LOG_MACROS(A, add); };
};

struct B : protected A {
  void push() { LOG_MACROS(B, push); };
};

struct C {
  void push() { LOG_MACROS(C, push); };
};

#endif  // __TYPES_EXAMPLE_HPP__
