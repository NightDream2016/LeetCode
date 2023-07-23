#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:

    void combinationDFS(string digits, int currentIndex, string& currentResult, vector<string>& results)
    {
        if (currentIndex == digits.length())
        {
            results.push_back(currentResult);
            return;
        }   

        vector<string> charMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};     

        char digit = digits[currentIndex];
        string relatedChars = charMap[digit - '2'];
        for (int i = 0; i < relatedChars.length(); i++)
        {
            currentResult[currentIndex] = relatedChars[i];
            combinationDFS(digits, currentIndex + 1, currentResult, results);
            currentResult[currentIndex] = '\0';
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        vector<string> results;

        if (digits.length() == 0)
        {
            return results;
        }

        string resultString(digits.length(), '\0');
        combinationDFS(digits, 0, resultString, results);

        return results;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    Solution solution;
    vector<string> results = solution.letterCombinations("23456789");
    outputVector(results);

    return 0;
}
