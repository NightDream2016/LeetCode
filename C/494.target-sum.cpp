#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int combinationSumDFS(vector<int> nums, int sum)
    {
        int *dpTable[nums.size()];

        for (int i = 0; i < nums.size(); i++)
        {
            dpTable[i] = new int[sum + 1];
            for (int j = 0; j < (sum + 1); j++)
            {
                dpTable[i][j] = 0;
            } 
        }

        dpTable[0][0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];

            if (i == 0)
            {
                dpTable[i][currentNum] = 1;
                continue;
            }
            for (int j = 0; j < (sum + 1); j++)
            {
                cout <<"i: " << i << " j: " << j << " currentNum:" << currentNum << endl;
                if (j < currentNum)
                {
                    cout << "dpTable[i][j]: " << dpTable[i][j] << " dpTable[i - 1][j]: " << dpTable[i - 1][j] << endl;
                    dpTable[i][j] = dpTable[i - 1][j];
                }
                else
                {
                    cout << "dpTable[i][j]: " << dpTable[i][j] << " dpTable[i - 1][j]: " << dpTable[i - 1][j] << " dpTable[i - 1][j - currentNum]: " << dpTable[i - 1][j-currentNum] << endl;
                    dpTable[i][j] = dpTable[i - 1][j] + dpTable[i - 1][j - currentNum];
                }
            }
        }

        return dpTable[nums.size() - 1][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> hashMap;
        
        int sumOfNums = 0;
        for (int num: nums)
        {
            sumOfNums += num;
            if (num == 0)
            {
                hashMap[num] += 1;
            }
        }
        
        if (sumOfNums < S)
        {
            return 0;
        }

        int result = pow(2, hashMap[0]);
        
        if (sumOfNums == S)
        {
            return result;
        }
        
        int sumOfMinus = sumOfNums - S;

        if (sumOfMinus % 2)
        {
            return 0;
        }

        sumOfMinus /= 2;

        int lastIndexSmallerThenS = 0;
        int lastIndexBiggerThenZero = 0;
        
        vector<int> numsTrimmed;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                numsTrimmed.push_back(nums[i]);
            }
            
            if (nums[i] > sumOfMinus)
            {
                break;
            }
        }
        
        int resultOfCombinationSum = 0;
        resultOfCombinationSum = combinationSumDFS(numsTrimmed, sumOfMinus);
        
        result *= resultOfCombinationSum;

        return result;
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    Solution solution;
    vector <int> input = {1,2,1};
    int result = solution.findTargetSumWays(input, 0);
    
    cout << result;
    return 0;
}

