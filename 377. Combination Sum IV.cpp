#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    void output(vector<int> vector)
    {
        cout << "[";
        for (auto &integer : vector)
        {
            cout << " " << integer << " ";
        }
        cout << "]," << endl;
    }

    void outputVector(vector<vector<int>> vectors)
    {
        cout << "[" << endl;
        for (auto &vector : vectors)
        {
            output(vector);
        }
        cout << "]" << endl;
    }

    vector<vector<int>> combine(vector<int> nums, int k)
    {

        vector<vector<int>> results;

        if (k == 1)
        {
            // set with single element
            for (auto &integer : nums)
            {
                vector<int> singleNumVector;
                singleNumVector.push_back(integer);
                results.push_back(singleNumVector);
            }

            return results;
        }

        if (nums.size() == k)
        {
            results.push_back(nums);
            return results;
        }

        int firstNum = nums[0];
        // cout << " N = " << N << "Find Result With N==================" << endl;
        nums.erase(nums.begin());
        vector<vector<int>> resultsWithN = combine(nums, k - 1);
        for (auto &result : resultsWithN)
        {
            result.insert(result.begin(), firstNum);
        }

        // cout << " resultsWithN: ";
        // outputVector(resultsWithN);

        vector<vector<int>> resultsWithoutN = combine(nums, k);

        // cout << " resultsWithoutN: ";
        // outputVector(resultsWithoutN);

        resultsWithN.insert(resultsWithN.end(), resultsWithoutN.begin(), resultsWithoutN.end());

        // cout << " resultsWithN: ";
        // outputVector(resultsWithN);

        // cout << "=======================" << endl;

        return resultsWithN;
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums;

        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }

        return combine(nums, k);
    }
};

int main(int argc, char *argv[])
{
    vector<int> input = {1, 2, 3};

    Solution solution;
    solution.combine(8, 4);
    // std::cout << solutionResult << std::endl;

    return 0;
}