#ifndef __LOG_MACROS_HPP__
#define __LOG_MACROS_HPP__

#include <iostream>  // for std::cout

// comment this define if you don't need log
#define LOG_MACROS_TAG

#ifdef LOG_MACROS_TAG

#define LOG_MACROS(x, y) std::cout << "Type " #x " Function " #y << std::endl;

#else

#define LOG_MACROS(x, y) ;

#endif

#endif  // __LOG_MACROS_HPP__
