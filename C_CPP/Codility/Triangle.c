// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdint.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int A[], int N)
{
    int left = 0;
    int right = N - 1;
    
    if (N <= 1)
    {
        return;
    }
    
    while (left < right)
    {
        if (A[left] > A[0])
        {
            swap(&A[left], &A[right]);
            right--;
        }
        else
        {
            left++;
        }
    }
    
    if (A[left] > A[0])
    {
        left--;    
    }
    
    swap(&A[left], &A[0]);
    
    quickSort(A, left);
    quickSort(A + (left + 1), N - (left + 1));
}



int solution(int A[], int N) 
{

    quickSort(A, N);
    
    int result = 0;
    for (int i = 0 ; i < N - 2; i++)
    {
        if ((int64_t)A[i] + (int64_t)A[i+1] > (int64_t)A[i+2])
        {
            result = 1;
            break;
        }
    }
    
    return result;
}


int main()
{
    int testA[6] = {10, 2, INT32_MAX, INT32_MAX, 8, 20};
    int testB[4] = {10, 50, 5, 1};

    int result =  solution(testA, 6);
    int result2 =  solution(testA, 4);

    return 0;
}