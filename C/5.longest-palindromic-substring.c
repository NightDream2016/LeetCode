/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.62%)
 * Total Accepted:    348.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

char* longestPalindrome(char* s) 
{
    int length = strlen(s);

    if (length <= 1)
    {
        return s;
    }

    int longestLength = 0;
    int longestStrStart = -1;
    int longestStrEnd = -1;

    for (int i = 0; i <= length - 1; i++)
    {
        int doubleSideLength = 0;
        
        int strStart = i - doubleSideLength;
        int strEnd = i + 1 + doubleSideLength;

        while (strStart >= 0)
        {
            if (s[strStart] != s[strEnd])
            {
                break;
            }
            doubleSideLength++;
            strStart = i - doubleSideLength;
            strEnd = i + 1 + doubleSideLength;
        }

        strStart += 1;
        strEnd -= 1;
        int currentPalindromeStrLength = strEnd - strStart + 1;
        if (currentPalindromeStrLength > longestLength)
        {
            longestLength = currentPalindromeStrLength;
            longestStrStart = strStart;
            longestStrEnd = strEnd;
        }
    }

    for (int i = 0; i <= length - 1; i++)
    {
        int doubleSideLength = 1;
        
        int strStart = i - doubleSideLength;
        int strEnd = i + doubleSideLength;

        while (strStart >= 0 && strEnd < length)
        {
            if (s[strStart] != s[strEnd])
            {
                break;
            }
            doubleSideLength++;
            strStart = i - doubleSideLength;
            strEnd = i + doubleSideLength;
        }

        strStart += 1;
        strEnd -= 1;
        int currentPalindromeStrLength = strEnd - strStart + 1;
        if (currentPalindromeStrLength > longestLength)
        {
            longestLength = currentPalindromeStrLength;
            longestStrStart = strStart;
            longestStrEnd = strEnd;
        }
    }

    char *result = (char *)malloc(sizeof(char) * (longestLength + 1) );
    s+= longestStrStart;
    strncpy(result, s, longestLength);
    result[longestLength] = '\0';

    return result;
    
}


// int main(int argc, char ** argv)
// {

//     char *result = longestPalindrome("abcdefgfedcba");
//     printf("%s", result);

//     return 0;
// }
