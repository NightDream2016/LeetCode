#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    
    typedef pair<int, int> Point;
    
    bool findWordWithLocation(vector<vector<char>>& board, 
                              int xSize, 
                              int ySize, 
                              Point location, 
                              string word, 
                              int currentIndex)
    {
        if (currentIndex == word.length())
        {
            return true;
        }
        
        char searchChar = word[currentIndex];
        
        Point left = {location.first, location.second}''
        
        bool result = false;
        if (x > 0 && board[x - 1][y] == searchChar)
        {
            result = findWordWithLocation(board, xSize, ySize, p)
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        char firstChar = word[0];
        int ySize = board.size();
        int xSize = board[0].size();
        
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                
            }
        }
    }
};
// @lc code=end

