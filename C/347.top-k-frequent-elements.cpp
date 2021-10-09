#include "GlobalInclude.cpp"

/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (59.00%)
 * Likes:    2435
 * Dislikes: 165
 * Total Accepted:    321.6K
 * Total Submissions: 544.6K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    static bool pairCompare(pair<int, int> pairA, pair<int, int> pairB)
    {
        return pairA.second < pairB.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> hashmap;
        vector<int> result;
        for (auto& num : nums)
        {
            hashmap[num] = hashmap[num] + 1;
        }

        vector<pair<int, int>> kList;
        for (pair<int, int> element: hashmap)
        {
            kList.push_back(element);
        }

        make_heap (kList.begin(), kList.end(), pairCompare);

        for (int i = 0; i < k; i++)
        {
            result.push_back(kList.front().first);
            pop_heap(kList.begin(), kList.end(), pairCompare);
            kList.pop_back();
        }

        return result;

    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> input = {1,1,1,1,2,2,2,3,3,4};

    Solution solution;
    vector<int> result = solution.topKFrequent(input, 2);
    Output:: outputVector(result);

    return 0;
}
