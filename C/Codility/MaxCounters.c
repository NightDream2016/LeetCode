#include <string.h>
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int N, int A[], int M) {
    struct Results result;
    
    int currentMaximum = 0;
    int lastMaximum = 0;
    int *counterArray = (int *)malloc(sizeof(int) * N);
    int *emptyArray = (int *)malloc(sizeof(int) * N); 
    memset(counterArray, 0, sizeof(int) * N);
    for (int i = 0; i < M; i++)
    {
        int currentCounterIndex = A[i] - 1;
        if (currentCounterIndex < N)
        {
            counterArray[currentCounterIndex]++;
            if (currentMaximum < lastMaximum + counterArray[currentCounterIndex])
            {
                currentMaximum = lastMaximum + counterArray[currentCounterIndex];
            }   
        }
        else
        {
            // 測資特化：如果全都是maximum counter那一直memset也有點慢
            // 偵測出這情況可以early termination, 降低極端情形。
            if (lastMaximum == currentMaximum)
            {
                continue;
            }

            memset(counterArray, 0, sizeof(int) * N);
            lastMaximum = currentMaximum;
        }
        
        // printf("currentMaximum: %d ", currentMaximum);
        // printf("plusCounterValue: %d\n", counterArray[currentCounterIndex]);
    }
    
    for (int i = 0; i < N; i++)
    {
        counterArray[i] += lastMaximum;
    }
    
    result.C = counterArray;
    result.L = N;
    
    return result;
}