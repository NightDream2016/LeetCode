#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  std::cout << "We have " << argc << " arguments" << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << "[" << i << "] " << argv[i] << std::endl;
  }
  return 0;
}