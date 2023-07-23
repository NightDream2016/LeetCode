#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (49.46%)
 * Likes:    4061
 * Dislikes: 185
 * Total Accepted:    734.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int countOfDays = prices.size();
        if (countOfDays == 0)
        {
            return 0;
        }
        
        int maximumAfterDay[countOfDays];

        for (int i = countOfDays - 1; i >= 0 ; i--)
        {
            if (i == countOfDays - 1)
            {
                maximumAfterDay[i] = prices[i];
            }            
            else
            {
                maximumAfterDay[i] = max(prices[i], maximumAfterDay[i + 1]);
            }
        }

        int maximum = 0;
        for (int i = 0; i < countOfDays; i++)
        {
            int localMaximum = maximumAfterDay[i] - prices[i];
            if (localMaximum > maximum)
            {
                maximum = localMaximum;
            }
        }

        return maximum;
    }
};
// @lc code=end

int main(int argc, const char** argv) 
{  
    Solution solution;
    vector <int> input= {7,1,5,3,6,4};
    solution.maxProfit(input);
    return 0;
}