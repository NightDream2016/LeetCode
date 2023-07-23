#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        if (matrix.size() <= 1)
        {
            return;
        }

        int circleDepth = 0;

        int n = matrix.size() - 1;
        while (circleDepth < matrix.size() / 2)
        {
            for (int shift = 0; shift < n - circleDepth; shift++)
            {
                pair<int, int> leftTop = {circleDepth + shift, circleDepth};
                pair<int, int> rightTop = {(n - circleDepth), circleDepth + shift};
                pair<int, int> rightDown = {(n - circleDepth) - shift, n - circleDepth};
                pair<int, int> leftDown = {circleDepth, (n - circleDepth) - shift};
                swap(matrix[leftTop.second][leftTop.first], matrix[leftDown.second][leftDown.first]);
                swap(matrix[leftDown.second][leftDown.first], matrix[rightDown.second][rightDown.first]);
                swap(matrix[rightDown.second][rightDown.first], matrix[rightTop.second][rightTop.first]);
            }

            circleDepth++;
        }
    }
};
// @lc code=end
