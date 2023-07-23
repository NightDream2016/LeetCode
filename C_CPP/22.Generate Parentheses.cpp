#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<string> solutions;

    string binaryToParentheseString(uint64_t binary, int stringSize)
    {
        string result;
        for (int i = stringSize - 1; i >= 0; i--)
        {
            if ((binary & (1 << i)) >> i == 1)
            {
                result += ')';
            }
            else
            {
                result += '(';
            }
        }

        return result;
    }

    // 用遞迴跟balance值去判斷現在的字串是否合法
    // balance其實就是一種Stack，用來判斷括號是否合法
    // 每放一個左括號balance就+1,右括號balance就-1
    void checkString(uint64_t stringBinary, int balance, int currentIndex, int countOfLeft, int countOfRight, int n)
    {
        // cout << "result:" << result << " balance:" << balance << " countOfLeft:" << countOfLeft << " countOfRight:" << countOfRight << " n:" << n << endl;

        // balance < 0 表示一定有多放右括號，不合法
        // balance > n 表示左括號放太多，不合法
        if (balance < 0 || balance > n)
        {
            return;
        }

        // 當來到字串最尾端 (字串長度是2n，也就是目前的括號字元Index = 2n - 1的時候)
        // 如果balance是0就表示剛剛好用光所有括號也都有搭起來，Pass結果
        if (currentIndex == (n * 2 - 1))
        {
            if (balance == 0)
            {
                string result = binaryToParentheseString(stringBinary, n * 2);
                solutions.push_back(result);
            }

            return;
        }

        // 重點優化:記住現在的左括號和右括號數量，它們最多都不會 > n
        // 所以只需要在數量小於n的時候才做下一個Index的搜尋。
        // (等於也不用，因為這表示目前的某個括號數量都用玩了，只要找另一種括號就好)
        if (countOfLeft < n)
        {
            uint64_t binary = stringBinary << 1;
            checkString(binary, balance + 1, currentIndex + 1, countOfLeft + 1, countOfRight, n);
        }

        if (countOfRight < n)
        {
            uint64_t binary = stringBinary << 1 && 1;
            checkString(binary, balance - 1, currentIndex + 1, countOfLeft, countOfRight + 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        solutions.clear();

        if (n == 0)
        {
            return solutions;
        }

        if (n == 1)
        {
            solutions.push_back("()");
            return solutions;
        }

        checkString(0, 1, 0, 1, 0, n);

        return solutions;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    vector<string> solutionResult = solution.generateParenthesis(5);

    for (string result : solutionResult)
    {
        std::cout << result << std::endl;
    }
    return 0;
}