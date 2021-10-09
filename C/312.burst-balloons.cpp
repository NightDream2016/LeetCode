#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        int *dpTable[n]; // dpTable[i][j] 的涵意是，假設第i到第j顆球被刺破時的解
        for (int i = 0; i < n; i++)
        {
            dpTable[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    int leftCoin = 1, rightCoin = 1;
                    if (i > 0)
                    {
                        leftCoin = nums[i - 1];
                    }
                    
                    if (i < n - 1)
                    {
                        rightCoin = nums[i + 1];
                    }
                    
                    dpTable[i][j] = leftCoin * nums[i] * rightCoin;
                }
                else
                {
                    dpTable[i][j] = INT_MIN;
                }
            }
        }

        // 針對每個長度的dpTable[i][j]求解
        // 也就是 連續1顆球被刺破 連續2顆球被刺破 .... 連續n顆汽球被刺破
        for (int length = 2; length <= n; length++)
        {
            for (int start = 0; start <= n - length; start++)
            {
                int end = start + length - 1;
                // 針對每一組解的最後一顆汽球的每個可能性枚舉
                // ex 假設對一個解f(start, end), 他的最後一顆被刺破的汽球為 k
                // 這時這組解的最後一個值就是 num[start - 1] * num[k] * num[end + 1]
                // (因為是最後一顆 也就是(start, k - 1)和(k + 1, end)之間的汽球都被刺了
                // 然後再加上之前用dp記下來的 dp[start, k - 1], dp[k + 1, end] 即可得解
                // cout << "==============================================" << endl;
                for (int lastBallonIndex = start; lastBallonIndex <= end; lastBallonIndex++)
                {
                    int previousBallonCoin = (start > 0) ? nums[start - 1] : 1;
                    int nextBallonCoin = (end < n - 1) ? nums[end + 1] : 1;
                    
                    int previousBurstCoin = (lastBallonIndex > start) ? dpTable[start][lastBallonIndex - 1] : 0;
                    // cout << "previousBurstCoin: " << previousBurstCoin << " :dpTable[" << start << "][" << lastBallonIndex - 1 << "]" <<  endl;
                    
                    int nextBurstCoin = (lastBallonIndex < end) ? dpTable[lastBallonIndex + 1][end] : 0;
                    // cout << "nextBurstCoin: " << nextBurstCoin << " :dpTable[" << lastBallonIndex + 1 << "][" << end << "]" <<  endl;

                    int lastBurstCoin = previousBallonCoin * nums[lastBallonIndex] * nextBallonCoin; 
                    // cout << "lastBurstCoin: " << lastBurstCoin << endl;
                    int otherBurstCoin = previousBurstCoin + nextBurstCoin;
                    // cout << "otherBurstCoin: " << otherBurstCoin << endl;


                    dpTable[start][end] = max(dpTable[start][end], lastBurstCoin + otherBurstCoin);
                }

                // cout << "dpTable[" << start << "][" << end << "]: " << dpTable[start][end] << endl;
                // cout << "==============================================" << endl;
            }
            
        }
        
        return dpTable[0][n - 1];
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {3,1,5,8};
    Solution solution;
    int result = solution.maxCoins(vectorInput);

    return 0;
}