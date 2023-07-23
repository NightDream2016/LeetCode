#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
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
        
        int dptableWithFirst[n];
        int dptableWithoutFirst[n];

        dptableWithFirst[0] = nums[0];
        dptableWithFirst[1] = max(nums[0], nums[1]);
        dptableWithoutFirst[1] = nums[1];
        dptableWithoutFirst[2] = max(nums[1], nums[2]);

        for (int i = 2; i < n - 1; i++)
        {
            int j = i + 1;

            dptableWithFirst[i] = max(dptableWithFirst[i - 2] + nums[i], dptableWithFirst[i - 1]);
            dptableWithoutFirst[j] = max(dptableWithoutFirst[j - 2] + nums[j], dptableWithoutFirst[j - 1]);
        }

        int result = max(dptableWithFirst[n - 2], dptableWithoutFirst[n - 1]);

        return result;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {1,2,3,1};
    Solution solution;
    int result = solution.rob(vectorInput);

    return 0;
}