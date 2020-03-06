#include "stdio.h"
#include "stdlib.h"
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int allPreiodCountFromSingleLongPreiod (int preiodLength)
{
    if (preiodLength == 0)
    {
        return 0;
    }

    return (1 + (preiodLength - 1)) * (preiodLength - 1) / 2;
}

int isCurrentPreiodStable (int startLocation, int midLocation, int endLocation)
{
    if ((midLocation - startLocation) == (endLocation - midLocation))
    {
        return 1;
    }
    
    return 0;
}


int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    int startTime = 0;
    int midTime = 1;
    int endTime = 2;
   
    int currentStablePreiodLength = -1;
    int result = 0;
    while (endTime < N)
    {
        if(isCurrentPreiodStable(A[startTime], A[midTime], A[endTime]))
        {
            if (currentStablePreiodLength == -1)
            {
                currentStablePreiodLength = 2;
            }
            else
            {
                currentStablePreiodLength++;
            }
        }
        else
        {
            if (currentStablePreiodLength == -1)
            {
                // do Nothing
            }
            else
            {
                result += allPreiodCountFromSingleLongPreiod(currentStablePreiodLength);
                currentStablePreiodLength = -1;
            }
        }

        startTime++;
        midTime++;
        endTime++;
    }

    if (currentStablePreiodLength != -1)
    {
        result += allPreiodCountFromSingleLongPreiod(currentStablePreiodLength);
    }

    return result;
}


int main(int argc, char ** argv)
{
    int input1[10] = {-1, 1, 3, 3, 3, 2, 3, 2, 1, 0};

    int result = solution(input1, 10);
    
    return 0;
}

