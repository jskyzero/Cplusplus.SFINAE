#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include "types.example.hpp"
#include "add.universal.hpp"

void SFINAE();

template <typename ReturnType, typename...A>
ReturnType GetReturnType(ReturnType(*)(A...));

#endif // __MAIN_HPP__
