#include "GlobalInclude.cpp"

/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        unordered_map <int ,int> heightMap;
        
        for(vector<int> person : people)
        {
            heightMap[person[0]] += 1;
        }
        
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<vector<int>> vectorInput ={{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution solution;
    solution.reconstructQueue(vectorInput);
}

