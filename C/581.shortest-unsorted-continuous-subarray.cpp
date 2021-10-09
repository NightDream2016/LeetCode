#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.67%)
 * Likes:    2153
 * Dislikes: 107
 * Total Accepted:    101.8K
 * Total Submissions: 331.7K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    void output(vector<int> vector)
    {
        cout << "[";
        for (auto &integer : vector)
        {
            cout << " " << integer << " ";
        }
        cout << "]," << endl;
    }

    int findUnsortedSubarray(vector<int>& nums) 
    {
        int numSize = nums.size();
        int previousMax = nums[0];
        int afterMin = nums[numSize - 1];
        
        int start = -1;
        int end = -1;
        for (int i = 1; i < numSize; i++)
        {
            if (nums[i] < previousMax)
            {
                start = i;
                break;
            }
            else
            {
                previousMax = nums[i];
            }
        }
        
        for (int i = numSize - 1; i>= 0; i--)
        {
            if (nums[i] > afterMin)
            {
                end = i;
                break;
            }
            else
            {
                afterMin = nums[i];
            }
        }
        
        if (start >= end || start == -1 || end == -1)
        {
            return 0;
        }
        
        int subarrayMin = INT_MAX;
        int subarrayMax = INT_MIN;
        
        for (int i = start; i <= end; i++)
        {
            subarrayMin = std:min(unsoredSubarrayMin, nums[i]);
            subarrayMax = std:max(unsoredSubarrayMax, nums[i]);
        }

        for (int i = start - 1; i >= 0; i--)
        {
            if (subarrayMin >= nums[i])
            {
                start = i + 1;
                break;
            }
        }

        for (int i = end + 1; i < numSize; i++)
        {
            if (subarrayMax <= nums[i])
            {
                end = i - 1;
                break;
            }
        }
        
        return end - start + 1;
        
    }
};
// @lc code=end
int main(int argc, char *argv[])
{
    vector<int> input = {1, 2, 3, 6, 8, 4, 2};

    Solution solution;
    int result = solution.findUnsortedSubarray(input);
    std::cout << result << std::endl;

    return 0;
}

