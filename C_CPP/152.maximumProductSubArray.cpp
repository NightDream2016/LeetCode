#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:

    int maxProduct(vector<int> &nums)
    {
        int count = nums.size();
        int globalMax = INT_MIN;
        int globalMin = INT_MAX;
        int previousLocalMax = 1;
        int previousLocalMin = 1;

        bool hasMinusAbsMax = false;

        for (int end = 0; end < count; end++)
        {
            int localMax = max(nums[end], nums[end] * previousLocalMax);
            int localMin = min(nums[end], nums[end] * previousLocalMin);
            if (nums[end] < 0)
            {
                // 1. 當nums[i] < 0，A[i]的最大值會從A[i-1]的最小值而來，反之亦然。
                // 簡單的說可寫成
                // if (nums[i] < 0)
                // max of A[i] = nums[i] * min of A[i - 1]
                // min of A[i-1] = nums[i] * max of A[i - 1]
                // 2. 需要比nums[end]是因為要考慮有0的情況
                // (max of A[i-1]可能是0，而這時nums[i]如果有值，就必須作為最大值))
                localMax = max(nums[end], nums[end] * previousLocalMin);
                localMin = min(nums[end], nums[end] * previousLocalMax);
            }

            previousLocalMax = localMax;
            previousLocalMin = localMin;

            if (localMax > globalMax)
            {
                globalMax = localMax;
            }
        }

        return globalMax;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    vector<int> testCase{-1, -2, -9, -6};

    int result = solution.maxProduct(testCase);
    std::cout << result << std::endl;

    return 0;
}