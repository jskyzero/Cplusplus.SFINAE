#ifndef __TYPES_EXAMPLE_HPP__
#define __TYPES_EXAMPLE_HPP__

#include "log.macros.hpp"

struct A {
  void Add() { LOG_MACROS(A, Add); };
};

struct B : A {
  void Push() { LOG_MACROS(B, Push); };
};

struct C {
  void Push() { LOG_MACROS(C, Push); };
};

#endif  // __TYPES_EXAMPLE_HPP__
