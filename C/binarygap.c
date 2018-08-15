#include <stdio.h>
#include <stdlib.h>

int solution(int N) 
{
    // write your code in C99 (gcc 6.2.0)
    int maximumBinaryGap = 0;

    int currentBitBask = 1;
    int lastBinary = 0;
    int currentBinaryGap = 0;
    int isInBinaryGap = 0;
    while (N != 0)
    {
        int currentBinary = N & currentBitBask;
        if (lastBinary == 1 && currentBinary == 0)
        {
            // BinaryGap Start
            isInBinaryGap = 1;
        }
        
        if (lastBinary == 0 && currentBinary == 1)
        {
            // BinaryGap End
            if (maximumBinaryGap < currentBinaryGap)
            {
                maximumBinaryGap = currentBinaryGap;
            }

            currentBinaryGap = 0;
            isInBinaryGap = 0;
        }

        if (isInBinaryGap)
        {
            currentBinaryGap++;
        }

        lastBinary = currentBinary;
        N = N >> 1;
    }

    return maximumBinaryGap;
}


int main(int argc, char ** argv)
{
    int result1 = solution(529);
    int result2 = solution(9);
    int result3 = solution(20);
    int result4 = solution(2147483647);

    
    return 0;
}
