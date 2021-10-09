#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int maxValue = 0;
        
        if (nums.size() == 0)
        {
            return maxValue;
        }
        
        if (nums.size() == 1)
        {
            maxValue = nums[0];
            return maxValue;
        }
        
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        int dptable[n];
        dptable[0] = nums[0];
        dptable[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dptable[i] = max(nums[i] + dptable[i - 2], dptable[i - 1]);
        }

        return dptable[n - 1];
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {2,7,9,3,1};
    Solution solution;
    int result =  solution.rob(vectorInput);
    return 0;
}

