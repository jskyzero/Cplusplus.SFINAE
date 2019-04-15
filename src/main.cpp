#include "main.hpp"
#include <iostream>
#include "version.hpp"

int f(){};

void SFINAE() {
  A a{};
  B bb();
  C cc();
  auto b = decltype(bb())();
  auto c = decltype(GetReturnType(cc))();
  auto dd = []() -> int {};
  decltype(dd()) d = 0;

  add_universal(a);
  add_universal(b);
  add_universal(c);
  add_universal(d);
}

int main() {
  std::cout << GetVersion() << std::endl;

  SFINAE();

  return 0;
}
