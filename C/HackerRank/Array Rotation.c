// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Results 
{
  int * A;
  int N; // Length of the array
}
RESULT;


struct Results solution(int A[], int N, int K) 
{
    struct Results result;

    result.N = N;
    if (N == 0)
    {
        result.A = A;
        return result;
    }

    K = K % N;
    
    if (K == 0) 
    {
        result.A = A;
        return result;
    }
    

    int *resultA = (int *)malloc(sizeof(int) * N);

    memcpy (resultA, A + (N - K), sizeof(int) * K);
    memcpy (resultA + K, A, sizeof(int) * (N - K));

    result.A = resultA;
    result.N = N;

    return result;
}


void outputArray(struct Results result)
{
    printf("[");
    for (int i = 0; i < result.N; i++)
    {
        printf("%d", result.A[i]);
    }

    printf("]\n");
}


int main(int argc, char **argv)
{
    
    int A1[] = {1,2,3,4,5};
    int A2[] = {};
    RESULT result1 = solution(A1, 5, 2);
    RESULT result2 = solution(A1, 5, 5);
    RESULT result3 = solution(A1, 0, 0);
    outputArray(result1);
    outputArray(result2);
    outputArray(result3);

    return 0;
}
