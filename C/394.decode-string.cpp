#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    
    string decodeString(string s) 
    {
        stack<char> characterStack;
        stack<char> digitStack;
        stack<int> timesStack;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                digitStack.push(s[i]);
            }
            else
            {
                if (digitStack.empty() == false)
                {
                    int time = 0;
                    int tenPower = 1;
                    while (digitStack.empty() == false)
                    {
                        int digit = digitStack.top() - 48;
                        time += digit * tenPower;
                        digitStack.pop();
                        tenPower *= 10;
                    }
                    timesStack.push(time);
                }
                
                if (s[i] == ']')
                {
                    vector<char> decodeChar; 

                    while (characterStack.top() != '[')
                    {
                        decodeChar.push_back(characterStack.top());
                        characterStack.pop();    
                    }
                    characterStack.pop();

                    // 從Stack pop出來的字元會是倒序的，所以用Vector接完要做一次Reverse順序才會對
                    reverse(decodeChar.begin(), decodeChar.end());

                    int times = timesStack.top();
                    timesStack.pop();

                    for (int i = 0; i < times; i++)
                    {
                        for (auto& ch : decodeChar)
                        {
                            characterStack.push(ch);
                        }
                    }
                }
                else
                {
                    characterStack.push(s[i]);
                }
            }            
        }
        
        vector<char> resultStringVector;
        
        while (characterStack.empty() == false)
        {
            resultStringVector.push_back(characterStack.top());
            characterStack.pop();
        }
        
        reverse(resultStringVector.begin(), resultStringVector.end());

        string result = string(resultStringVector.begin(), resultStringVector.end());
        return result;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    Solution solution;
    string result = solution.decodeString("100[abc]3[cd]ef");
    cout << result;
    return 0;
}