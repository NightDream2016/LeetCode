#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "We have " << argc << " arguments" << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << "[" << i << "] " << argv[i] << std::endl;
  }
  return 0;
}