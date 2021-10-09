#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    
    int binarySearch(vector<int>& sortedList, int element)
    {
        int start = 0;
        int end = sortedList.size() - 1;
        
        int resultIndex = -1;
        while (start <= end)
        {   
            int mid = start + (end - start) / 2;
            if (sortedList[mid] < element)
            {
                start = mid + 1;
            }
            else if (sortedList[mid] > element)
            {
                end = mid - 1;
            }
            else
            {
                resultIndex = mid;
                break;
            }
        }
        
        if (resultIndex == -1)
        {
            resultIndex = start;
        }
        
        return resultIndex;
    }
    
    void insertToSortedList(vector<int>& sortedList, int element)
    {
        if (sortedList.size() == 0)
        {
            sortedList.push_back(element);
            return;
        }
        
        int result = binarySearch(sortedList, element);
        
        sortedList.insert(sortedList.begin() + result, element);
    }
    
    void removeInSortedList(vector<int>& sortedList, int element)
    {
        if (sortedList.size() == 0)
        {
            return;
        }
        
        int result = binarySearch(sortedList, element);
        
        sortedList.erase(sortedList.begin() + result);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> resultList;
        vector<int> sortedList;
        
        for (int i = 0; i < k; i++)
        {
            insertToSortedList(sortedList, nums[i]);
        }
                
        int start = 0;
        int end = start + k - 1;
        while(end < nums.size())
        {
            int currentMaximum = sortedList[k - 1];
            resultList.push_back(currentMaximum);
           
            removeInSortedList(sortedList, nums[start]);
            
            if (end  < nums.size() - 1)
            {
                insertToSortedList(sortedList, nums[end + 1]);
            }
            
            start += 1;
            end += 1;
        }
        
        return resultList;
        
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {1,3,-1,-3,5,3,6,7};
    int valueInput = 3;
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(vectorInput, valueInput);
    outputVector(result);
    return 0;
}
