/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.12%)
 * Likes:    13759
 * Dislikes: 504
 * Total Accepted:    2.6M
 * Total Submissions: 5.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map <int, int> hashTable;

        for (int i = 0; i < nums.size(); i++)
        {
            hashTable.insert({nums[i], i});
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int anotherNum = target - nums[i];
            if (hashTable.find(anotherNum) != hashTable.end())
            {
                if (i != hashTable[anotherNum])
                {
                    result.push_back(i);
                    result.push_back(hashTable[anotherNum]);
                    break;
                }
            }    
        } 

        return result;
    }
};


int main(int argc, char *argv[])
{
    Solution solution;

    vector<int> input1 = {3, 2, 4};
    int input2 = 6;
    vector<int> result = solution.twoSum(input1, input2);
    return 0;
}
// @lc code=end

