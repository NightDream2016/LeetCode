#include <stdlib.h>
#include <stdio.h>
/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.47%)
 * Total Accepted:    280.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void outputArray(int array[], int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf(" %d ,", array[i]);
    }
    printf("]\n");
}

// 找兩個已排序的陣列，所有元素的集合中，第K個大的元素值(K從0開始計算)
int findKLargest(int *nums1, int nums1Size, int *nums2, int nums2Size, int k)
{
    if (nums1Size == 0)
    {
        return nums2[k];
    }

    if (nums2Size == 0)
    {
        return nums1[k];
    }

    if (k == 0)
    {
        return min(nums1[0], nums2[0]);
    }

    int mid1 = nums1Size / 2;
    int mid2 = nums2Size / 2;

    //陣列的mid值本身也要濾掉(重要！！！！不然會導致無窮遞迴)
    if (mid1 + mid2 < k)    // 陣列一的中央值 + 陣列二的中央值 < K值
    {
        // MARK: mid和陣列Index一樣是從0開始起算，所以在取陣列邊界時要把mid對應的陣列值排除
        // 也就是取[mid + 1, size - (mid + 1)]的Range
        // 若是取錯就有可能導致無窮遞迴
        if (nums1[mid1] < nums2[mid2])    // mid1 -> mid2 -> k，濾掉nums[mid1](含)以前的值
        {
            nums1 += (mid1 + 1);    
            nums1Size -= (mid1 + 1);
            k -= (mid1 + 1); 
        }
        else // mid2 -> mid1 -> k，濾掉nums[mid2](含)以前的值
        {
            nums2 += (mid2 + 1);
            nums2Size -= (mid2 + 1);
            k -= (mid2 + 1);
        }
    }
    else
    {
        //因為mid一樣是從0開始起算，所以直接把size設成mid值就可以把mid對應的值排除了。
        //ex 長3的陣列 [0,1,2] mid為 3 / 2 = 1 nums1[mid]為 nums[1] = 1
        //nums1Size = 1的話就會剩下[0]
        if (nums1[mid1] >= nums2[mid2]) // k -> mid2 -> mid1
        {
            nums1Size = mid1;   
        }
        else    // k -> mid1 -> mid2
        {
            nums2Size = mid2;
        }
    }

    return findKLargest(nums1, nums1Size, nums2, nums2Size, k);
}


double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int k = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) % 2 == 0)
    {
        int kLargest = findKLargest(nums1, nums1Size, nums2, nums2Size, k);
        
        int kMinus1Largest = findKLargest(nums1, nums1Size, nums2, nums2Size, k - 1);
        return (double)(kLargest + kMinus1Largest)/2;
    }
    else
    {
        return (double)findKLargest(nums1, nums1Size, nums2, nums2Size, k);
    }
}

// int main(int argc, char const *argv[])
// {
//     int nums1[] = {1, 2};
//     int nums2[] = {1, 2, 3};

//     double result = findMedianSortedArrays(nums1, 2, nums2, 3);

//     return 0;
// }
