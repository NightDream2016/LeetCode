#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
  
  vector <uint64_t> integerStack;
  string input;
  
  while (cin >> input)
  { 
    if (input[0] == '\n')
    {
      break;
    }
    else if(input[0] == '+')
    {
      uint64_t a = integerStack.back();
      integerStack.pop_back();
      uint64_t b = integerStack.back();
      integerStack.pop_back();
      
      uint64_t sum = (a + b);
      integerStack.push_back(sum);
    }
    else if (input[0] == '*')
    {
      uint64_t a = integerStack.back();
      integerStack.pop_back();
      uint64_t b = integerStack.back();
      integerStack.pop_back();
      
      uint64_t sum = (a * b);
      cout << sum << " ";
      integerStack.push_back(sum);
    }
    else
    {
      uint64_t num = stoi(input);
      integerStack.push_back(num);
    }
  }
  
  uint64_t result = integerStack.back();
  integerStack.pop_back();
  
  cout << result;
  return 0;
}
