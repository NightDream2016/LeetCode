/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) 
    {
        if (n <= 2)
        {
            return n;
        }
        
        int dpTable[n];
        dpTable[0] = 1;
        dpTable[1] = 2;
        
        for (int i = 2; i < n; i++)
        {
            dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
        }
        
        return dpTable[n - 1];
    }
};
// @lc code=end

