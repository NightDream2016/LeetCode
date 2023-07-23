#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.63%)
 * Likes:    3867
 * Dislikes: 405
 * Total Accepted:    587.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {    
        int left = 0, right = nums.size() - 1;
        int resultIndex = -1;
        while (left <= right)
        {
            // 針對left == right或left跟right剛好差1的Edge Case做處理
            if (left == right || left == right - 1)
            {
                if (nums[left] == target)
                {
                    resultIndex = left;
                }

                if (nums[right] == target)
                {
                    resultIndex = right;
                }

                break;
            }

            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                resultIndex = mid;
                break;
            }

            // 原則就是: 只要能一次排除一半的元素，就贏了。
            // 然後已知原陣列是升序排列
            // 所以要嘛就是nums[left] ~ nums[mid]是升序排列
            // 要嘛就是nums[mid] ~ nums[left]是升序排列
            // 簡單的說: 就算旋轉過，也一定至少有一半的陣列是升序排列。
            // 而這可以透過比較nums[mid]和nums[left] / nums[right]的值得出

            // 知道其中半邊是升序 / 降序就簡單了，因為就可以檢測target是不是在那個Range裡面。
            // 不在的話就在另外一邊。

            if (nums[left] < nums[mid])
            {
                // nums[left] <= target < nums[mid]，取左半邊
                // 這裡要有=，不然會漏掉nums[left] = target的情況。
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            
            if (nums[mid] < nums[right])
            {
                // nums[mid] < target <= nums[right]，取右半邊
                // 這裡要有=，不然會漏掉nums[right] = target的情況。
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return resultIndex;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> input = {3, 1};

    Solution solution;
    int result = solution.search(input, 0);

    return 0;
}

