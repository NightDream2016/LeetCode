#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int countOfCoinSet = coins.size();
        int dpTableSize = amount + 1;
        int dpTable[dpTableSize];
        for (int i = 0; i < dpTableSize; i++)
        {
            dpTable[i] = -1;
        }
        
        dpTable[0] = 0;
        for (int currentAmount = 1; currentAmount <= amount; currentAmount++)
        {
            for (int j = 0; j < countOfCoinSet; j++)
            {
                // 這裡有一個關鍵：實際上我們搜尋的時候不需要考慮「目前的硬幣取了幾個」。
                // 因為我們想要的是「最小值」，題目可以理解為「假定某個取法最後一個硬幣為Coin[j]，那麼他會是最小值嗎？」
                // 換言之只需要對所有「種」而非「個」Coin做一次確認就好
                // 也就是「對所有的Coin[j]確認他是否可能是最小值」，即可。
                // ======
                // 或者也可以這樣理解: 對於其中一個目標金額(amount)，他的解dpTable[amount]的值
                // 一定是從某一個之前的dpTable[amount]值「再加一枚硬幣」推導而來
                // 我們現在只是不知道「增加的那枚」硬幣是哪顆
                // 剩下的硬幣早就在取之前那個dpTable[amount]的時候過濾掉了
                // 要是搜了就會變成重複搜尋
                int lastCoin = coins[j];
                if (lastCoin <= currentAmount)
                {
                    int lastAmount = currentAmount - lastCoin;
                    if (dpTable[lastAmount] != -1)
                    {
                        if (dpTable[currentAmount] == -1)
                        {
                            dpTable[currentAmount] = dpTable[lastAmount] + 1;
                        }
                        else
                        {
                            dpTable[currentAmount] = min(dpTable[currentAmount], dpTable[currentAmount - lastCoin] + 1);
                        }
                    }
                }   
            }
        }

        return dpTable[amount];
    }
};
// @lc code=end
int main(int argc, char *argv[])
{
    vector<int> vectorInput = {2, 5, 10, 1};
    int valueInput = 27;
    Solution solution;
    int result = solution.coinChange(vectorInput, valueInput);
    cout << result;
    return 0;
}

