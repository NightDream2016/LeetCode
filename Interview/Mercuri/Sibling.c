#include "stdio.h"
#include "stdlib.h"
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int N) 
{
    if (N < 10)
    {
        return N;
    }

    // Using -1 As Empty For Array Saving Digits
    int digitList[5] = {-1,-1,-1,-1,-1};
    int resultDigitList[5] = {-1,-1,-1,-1,-1};

    int avaibleDigitInDecimal[10] = {9,8,7,6,5,4,3,2,1,0};
    
    // write your code in C99 (gcc 6.2.0)
    int currentPowerOfDecimal = 1;
    int currentDigitIndex = 0;
    while (currentPowerOfDecimal <= N)
    {
        int currentDigit = N % (currentPowerOfDecimal * 10) / currentPowerOfDecimal;
        digitList[currentDigitIndex] = currentDigit;
        currentDigitIndex++;
        currentPowerOfDecimal *= 10;
    }

    int currentResultDigitIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < currentDigitIndex; j++)
        {
            if (digitList[j] == avaibleDigitInDecimal[i])
            {
                resultDigitList[currentResultDigitIndex] = digitList[j];
                currentResultDigitIndex++;
            }
        }
    }

    int result = 0;
    currentResultDigitIndex--;
    currentPowerOfDecimal = 1;
    while (currentResultDigitIndex >= 0)
    {
        result += currentPowerOfDecimal * resultDigitList[currentResultDigitIndex];
        currentResultDigitIndex--;
        currentPowerOfDecimal *= 10;
    }

    return result;
}


int main(int argc, char ** argv)
{

    int result = solution(59948);
    
    return 0;
}

