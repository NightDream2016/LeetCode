#include "GlobalInclude.cpp"

/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int traveler = 0;

        int bottomIndex = 0;
        int midIndex = 0;
        int topIndex = nums.size() - 1;
        
        // bottom = 0 mid = 1 top = 2
        // 1.被交換到bottomIndex的元素一定要是bottom值。
        // 2.被交換到topIndex的元素一定要是top值。
        // 3.bottomIndex <= midIndex <= topIndex。
        // 本題最大的問題在於如何滿足條件3.
        // 而具體做法為: 
        // mid遇到bottom時交換nums[mid], nums[bottom]，且"mid bottom 一起動"
        // mid遇到top時 交換nums[mid], nums[top], 然後"只動top"
        // mid遇到mid時 "只動mid"
        // 因為bottom應該要在mid後面，所以如果1.swap完動了bottom卻沒有動mid -> mid < bottom;
        // 而mid要在top後面，所以交𢰼完只能動top(否則會讓top被交換到mid的元素被略過)
        // 學理上稱為"荷蘭國旗問題" (Dutch national flag problem) 
        // https://en.wikipedia.org/wiki/Dutch_national_flag_problem
        // ======
        // 另一種解釋 : 先考慮只有0和1的情況
        // 0 1 0 1 1 0 1 0...
        // 這個演算法就會在遇到0的時候兩個一起往前，1的時候只有mid往前，而把bottom留在1的位置。
        // 這時mid無論何時再遇到0就會把0丟回bottom的位置，而後bottom和mid都往前，
        // 這時對num[mid]來說被調成到1沒差，因為mid的行為一樣是往前進。
        // 而當mid到結尾以後就收工。
        // 之後再回來考慮有2的情況，mid之所以遇到2不動的理由就是要確保mid所在的位置會吸收所有的0和1
        // (因為只要topIndex有經過0和1就會通通被丟到mid)
        // 而2通通被丟到陣列尾巴，所以midIndex只要做到 = topIndex為止那就和那個只有0和1的情況一樣了。

        while (midIndex <= topIndex)
        {
            if (nums[midIndex] == 0)
            {
                swap(nums[midIndex], nums[bottomIndex]);
                bottomIndex += 1;
                midIndex += 1;
            }
            else if (nums[midIndex] == 2)
            {
                swap(nums[midIndex], nums[topIndex]);
                topIndex -= 1;
            }
            else
            {
                midIndex += 1;
            }
        }
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {0,1,2,0,1,2,1,1};
    Solution solution;
    solution.sortColors(vectorInput);
}
