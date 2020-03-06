// you can write to stdout for debugging purposes, e.g.
// printf('this is a debug message\n');
#include <string.h>
#include <math.h>

char * solution(char *S, char *T) 
{
    // write your code in C99 (gcc 6.2.0)
    int slength = strlen(S);
    int tlength = strlen(T);
    
    int lengthDiff = slength - tlength;
    if (abs(lengthDiff) >= 2)
    {
        return "IMPOSSIBLE";
    }
    
    char *result = (char *)malloc(sizeof(char) * 9);
 
    if (lengthDiff == 0) //  MAYBE SWAP
    {
        int swapCharIndex[2];
        int numOfSwapIndex = 0;
        for (int i = 0; i < slength; i++)
        {
            if (S[i] != T[i])
            {
                if (numOfSwapIndex >= 2) // Stack Full, Impossbiel
                {
                    return "IMPOSSIBLE";
                }
                
                swapCharIndex[numOfSwapIndex] = i;
                numOfSwapIndex++;
            }
        }
        
        if (numOfSwapIndex == 0) // No Need Swap, Equal
        {
            return "EQUAL";
        }
        
        int swapIndex0 = swapCharIndex[0];
        int swapIndex1 = swapCharIndex[1];
        if (S[swapIndex0] == T[swapIndex1] && S[swapIndex1] == T[swapIndex0] && (swapCharIndex[1] == swapCharIndex[0] + 1))
        {
            char swapCharA = S[swapIndex0];
            char swapCharB = S[swapIndex1];
            
            strcpy(result , "SWAP    ");
            result[5] = swapCharA;
            result[7] = swapCharB;
            return result;
        }
        else
        {
            return "IMPOSSIBLE";
        }
    }
    else
    {
        if (lengthDiff < 0) // INSERT
        {
            for (int i = 1; i < tlength; i++)
            {
                if(T[i] != S[i-1])
                {
                    return "IMPOSSIBLE";
                }
            }
            
            char insertChar = T[0];
            strcpy(result , "INSERT  ");
            result[7] = insertChar; 
            return result;
            
        }
        else // DELETE
        {
            for (int i = 0; i < tlength; i++)
            {
                if(S[i] != T[i])
                {
                    return "IMPOSSIBLE";
                }
            }
            
            char deleteChar = S[slength - 1];
            strcpy(result , "DELETE  ");
            result[7] = deleteChar;
            return result;
        }
    }
}


int main()
{
    char *result1 = solution("gain", "again");
    char *result2 = solution("patts", "parrs");
    char *result3 = solution("form", "fomr");
    char *result4 = solution("o", "odd");
    char *result5 = solution("abcdefghijklmnopqrstuvwxyzabcdefghijklm", "aabcdefghijklmnopqrstuvwxyzabcdefghijklm");

    printf("%s %s %s %s", result1, result2, result3, result4);

    return 0;
}
