#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
typedef struct discRange
{
    int64_t start;
    int64_t end;
}
DiscRange;


void outputRange(DiscRange range)
{
    printf("[ %I64d, %I64d ]", range.start, range.end);
}


void outputRangeArray(DiscRange rangeList[], int N)
{
    printf("Result:\n");
    printf("{");
    for (int i = 0; i < N; i++)
    {
        outputRange(rangeList[i]);
        printf(" ,");
    }

    printf("}\n");
}


int compareRange(DiscRange a, DiscRange b)
{
    if (a.start < b.start)
    {
        return -1;
    }
    else if (a.start > b.start)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


void swapRange(DiscRange *a, DiscRange *b)
{
    DiscRange temp = *a;
    *a = *b;
    *b = temp;
}


void quickSortDiscRange(DiscRange A[], int N)
{
    int left = 1;
    int right = N - 1;
    
    if (N <= 1)
    {
        return;
    }

    while (left < right)
    {
        if (compareRange(A[left] , A[0]) == 1)
        {
            swapRange(&(A[left]), &(A[right]));
            right--;
        }
        else
        {
            left++;
        }   
    }

    int midIndex = left;
    if (compareRange(A[left] , A[0]) == 1)
    {
        midIndex--;
    }
    
    swapRange(&(A[0]), &(A[midIndex]));    

    quickSortDiscRange(A, midIndex);
    quickSortDiscRange(A + (midIndex + 1), N - (midIndex + 1));
}


// 用BinarySearch對已經依startPoint座標排序的DiscRangeList找出「最後一個和此點交錯的Range」
int searchLastRangeIntersected(DiscRange rangeList[], int rangeListCount,int64_t point)
{
    if (rangeListCount == 0)
    {
        return -1;
    }

    int left = 0;
    int right = rangeListCount - 1;
    int mid = (left + right) / 2;
    int isFindRangeStartEqualToPoint = 0;

    while(left < right)
    {
        // printf("point:%d\n", point);
        // printf("mid:%d rangeList[mid]: ",mid);
        // outputRange(rangeList[mid]);
        // printf("\n");
        // printf("rangeList[mid + 1]: ");
        // outputRange(rangeList[mid+1]);
        // printf("\n");

        if (rangeList[mid].start == point)
        {
            isFindRangeStartEqualToPoint = 1;
            break;
        }

        if (rangeList[mid].start < point && rangeList[mid + 1].start > point)
        {
            break;
        }
        else if (rangeList[mid].start > point && rangeList[mid + 1].start > point)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }

        mid = (left + right) / 2;
        
    }
    
    // 檢查是否為特殊情況，List中沒有Range和point有交集
    if (mid == 0)
    {
        if (rangeList[mid].start > point)
        {
            return -1;
        }
    }
    
    // 檢查是否為許多Range的Start都和Point重複
    if (isFindRangeStartEqualToPoint)
    {
        while (mid + 1 < rangeListCount && rangeList[mid + 1].start == point)
        {
            mid++;
        }
    }

    return mid;
}


int solution(int A[], int N) 
{
    // write your code in C99 (gcc 6.2.0)

    DiscRange *rangeList = (DiscRange *)malloc(sizeof(DiscRange) * N);
    for (int64_t i = 0; i < N; i++ )
    {
        DiscRange range;
        range.start = i - A[i];
        range.end = i + A[i];
        rangeList[i] = range;
    }

    // 將圓形在數線上的Range依據起始座標排列
    quickSortDiscRange(rangeList, N);
    // outputRangeArray(rangeList, N);

    int result = 0;
    for (int i = 0 ; i < N; i++)
    {
        int64_t currentDiscRangeEnd = rangeList[i].end;
        int upperDiscStartIndex = i + 1;
        int upperDiscCount = N - upperDiscStartIndex;
        int indexOfLastRangeIntersected = searchLastRangeIntersected( rangeList + upperDiscStartIndex, 
                                                upperDiscCount, 
                                                currentDiscRangeEnd);

        // printf("\ncurrentRange:\n");
        // outputRange(rangeList[i]);
        // printf("\ncountOfIntersected:%d\n", indexOfLastRangeIntersected + 1);
        result += (indexOfLastRangeIntersected + 1);

        if (result > 10000000)
        {
            result = -1;
            break;
        }
    }

    return result;
    
}

int main()
{
   
    int test1[] = { 1, 2147483647, 0 };

    int result = solution(test1, 3);

    return 0;

    
}
