#include <iostream>
#include "StackUnderflow.hpp"

StackUnderflow::StackUnderflow() {
  std::cerr << __LINE__ << ": " << "Incorrect size." << '\n';
}
