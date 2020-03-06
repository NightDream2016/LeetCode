#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int A[], int N)
{
    int left = 1;
    int right = N - 1;
    
    if (N <= 1)
    {
        return;
    }
    
    printf("Current Round Start: \n");
    outputResult(A, N);

    while (left < right)
    {
        if (A[left] > A[0])
        {
            swap(&(A[left]), &(A[right]));
            right--;
        }
        else
        {
            left++;
        }
        
        outputResult(A, N);
    }

    int midIndex = left;
    if (A[left] > A[0])
    {
        midIndex--;
    }
    
    swap(&(A[0]), &(A[midIndex]));    
    
    printf("Current Round Result:\n");
    outputResult(A, N);

    quickSort(A, midIndex);
    quickSort(A + (midIndex + 1), N - (midIndex + 1));
    
}


void outputResult (int resultArray[], int resultCount)
{
    printf("[");
    for (int i = 0; i < resultCount; i++)
    {
        printf("%d ,", resultArray[i]);
    }
    printf("]\n");
}


int main()
{
    int testA[10] = {6,30,29,77,10,52,49,320,123923913,23921};

    quickSort(testA, 10);
    outputResult(testA, 10);


    return 0;

    
}
