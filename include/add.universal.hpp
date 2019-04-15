#ifndef __ADD_UNIVERSAL_HPP__
#define __ADD_UNIVERSAL_HPP__

#include <utility>  // for declval
#include "log.macros.hpp" // for LOG_MACROS


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

#endif  // __ADD_UNIVERSAL_HPP__
