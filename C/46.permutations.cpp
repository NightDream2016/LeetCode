#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include "Output.cpp"

using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (60.44%)
 * Likes:    3141
 * Dislikes: 94
 * Total Accepted:    524.2K
 * Total Submissions: 866.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> results;

    void dfs(vector<int>& nums, int currentNumsLength, vector<int>& result, int currentIndex)
    {
        // 剛好只剩一個Num可以用的時候，就結束遞迴，記錄結果並返回值
        if (currentNumsLength == 1)
        {
            result[currentIndex] = nums[0];
            results.push_back(result);
            return;
        }

        for (int i = 0; i < currentNumsLength; i++)
        {
            result[currentIndex] = nums[i];

            // 算是能在做DFS的時候省記憶體又能做到backtracking，並避免存取到已使用元素的方式。
            // 簡單原理就是把目前的num跟vector尾端的元素交換
            // 然後多一個currentNumsLength的參數去畫定未使用/已使用的陣列元素之邊界
            // 因為dfs進去以後currentNumsLength會-1，所以遞迴做起來就不會存取到已使用的元素
            // (懶人包: 用過的元素丟到vector尾巴，然後把長度縮減！但並不是真的把元素清掉而只是把尾巴長度減掉而已)
            // (其實STL內部的vector，要刪除特定元素時也是用類似做法)
            swap(nums[i], nums[currentNumsLength - 1]);

            dfs(nums, currentNumsLength - 1, result , currentIndex + 1);

            // 這個做法的好處就是backtracking的時候只要再swap回來就好了，非常簡單。
            // 因為元素並沒有被真的清掉，所以swap回來就好！
            swap(nums[i], nums[currentNumsLength - 1]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> result(nums.size());
        dfs(nums, nums.size(), result, 0);
        return results;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> input = {1, 2, 3};

    Solution solution;
    vector<vector<int>> results = solution.permute(input);
    Output::output2DVector(results);

    return 0;
}

