#include "WrongStackSize.hpp"

WrongStackSize::WrongStackSize() {
  std::cerr << __LINE__ << ": " << "Array size  below  zero,  it is  not cool." << '\n';
}