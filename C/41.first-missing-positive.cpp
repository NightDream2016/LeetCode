#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int maxPositive = 1;
        int minPositive = INT_MAX;
        
        // 先試著求出陣列當中正整數的最大和最小值
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                maxPositive = max(maxPositive, nums[i]);
                minPositive = min(minPositive, nums[i]);
            }
        }

        // MinPostive > 1直接濾掉; 另外也可以順便濾掉全部都<=0的Edge Case
        if (minPositive > 1)
        {
            return 1;
        }

        // 基本原理就是把input array當hashTable用，minPositive放1，
        // 然後盡可能構建出一個嚴格遞增，且nums[i] == 1 + i的array。
        // 陣列One Pass過一次，將 > 0 的Num值Swap到正確的Index 
        // Index為 (nums[i] - 1)，也就是將1擺在第一個，接著的依序擺下去
        // 如果nums[i]大到超過陣列範圍，那也就不可能跟解答有關了，就會直接擺著當不合法值用。
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                // 計算出這個數應該要擺到哪個Index
                int newIndex = nums[i] - 1;
                // 太大的nums[i]就不swap，擺在那邊當不合法值
                if (newIndex < nums.size() && nums[newIndex] != nums[i])
                {
                    swap(nums[i], nums[newIndex]);
                    i--;
                }
            }
        }
    
        int result = -1; // 這裡不能直接用maxPositive + 1, 不然可能會溢位:P
        
        // 依序Check已經swap完的陣列，如果陣列是嚴格遞增，
        // 那理想上我們就會製造出一個所有nums[i] == minPositive + i的array
        // 所以如果nums[i] != minPositive + 1那就可得出結果。
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 1 + i)
            {
                result = 1 + i;
                break;
            }
        }

        if (result == -1)
        {
            // result == -1表示陣列真的是嚴格遞增，那最大值確實就是maxPositive + 1
            result = maxPositive + 1;
        }
        
        return result;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {1,2,3,10,2147483647,9};
    Solution solution;
    int result  = solution.firstMissingPositive(vectorInput);
    return 0;
}
