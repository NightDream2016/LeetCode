#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
        
    void combinationSumDFS(vector<int> &nums, int sum, int currentIndex, int *result)
    {
        int currentNum = nums[currentIndex];
        if (currentIndex == (nums.size() - 1))
        {   
            if (sum == currentNum)
            {
                (*result) += 1;
            }

            return;
        }
        
        combinationSumDFS(nums, sum, currentIndex + 1, result);
        combinationSumDFS(nums, sum - currentNum, currentIndex + 1, result);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        sort(nums.begin(), nums.end());
        
        int countOfZero = 0;
        
        int sumOfNums = 0;
        for (int num: nums)
        {
            sumOfNums += num;
            if (num == 0)
            {
                countOfZero += 1;
            }
        }
        
        if (sumOfNums < S)
        {
            return 0;
        }

        int result = pow(2, countOfZero);
        
        if (sumOfNums == S)
        {
            return result;
        }
        
        int sumOfMinus = sumOfNums - S;
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
        combinationSumDFS(numsTrimmed, sumOfMinus, 0, &resultOfCombinationSum);
        
        result *= resultOfCombinationSum;

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    vector <int> input = {1,1,1,1,1};
    int result = solution.findTargetSumWays(input, 3);
    
    cout << result;
    return 0;
}