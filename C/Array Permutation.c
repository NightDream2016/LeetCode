#include <string.h>
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) 
{
    // write your code in C99 (gcc 6.2.0)
    int *checkTable = (int *)malloc(sizeof(int) * N);
    memset(checkTable , 0, sizeof(int) * N);
    
    int result = 1;
    for (int i = 0; i < N; i++)
    {
        int tableIndex = A[i];
        if (tableIndex > N || tableIndex <= 0)
        {
            result = 0;
            break;
        }
        
        if (checkTable[tableIndex - 1]) // duplicate
        {
            result = 0;   
            break;
        }
        
        checkTable[tableIndex - 1] = 1;
    }
    
    return result;
}