#include "GlobalInclude.cpp"

/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:

    int countSubstrings(string s) 
    {
        int n = s.length();
        int totalCount = n;
        
        // 搜奇數長度的子字串
        // 以原字串的每個char開始，往左右長，一次各張1
        // 如果遇到左端字元 != 右端字元的情況，就Continue掉 
        // (因為接下來所有以此為中心的子字串一定都不是結果)
        // 字串的長度會是1 3 5 7 9...
        // (長度1的字串不用搜一定是，所以這裡從shift = 1開始搜)
        for (int midIndex = 1; midIndex < n - 1; midIndex++)
        {
            for(int shift = 1; shift < n; shift++)
            {
                int left = midIndex - shift;
                int right = midIndex + shift;
                if(left < 0 || right >= n || s[left] != s[right])
                {
                    break;
                }

                totalCount++;
            }
        }
        
        // 搜偶數長度的子字串
        // 以字串的每兩個char為單位開始往左右長，一次各張1
        // 如果遇到左端字元 != 右端字元的情況，就Continue掉 
        // (因為接下來所有以此為中心的子字串一定都不是結果)
        // 字串的長度會是2 4 6 8 10...
        // 這裡因為要包含"長度為2的子字串"，所以Shift從0開始
        for (int midIndex = 0; midIndex < n-1; midIndex++)
        {
            for(int shift = 0; shift < n; shift++)
            {
                int left = midIndex - shift;
                int right = midIndex + 1 + shift;
                if(left < 0 || right >= n || s[left] != s[right])
                {
                    break;
                }

                totalCount++;
            }
        }
        
        return totalCount;
        
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    Solution solution;
    int result = solution.countSubstrings("dnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvgdnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvg");

    return 0;
}