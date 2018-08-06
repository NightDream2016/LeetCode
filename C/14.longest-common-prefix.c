/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.78%)
 * Total Accepted:    301.1K
 * Total Submissions: 947.5K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char* longestCommonPrefix(char** strs, int strsSize) 
{
    int longestCommonPrefixLength = 0;

    char currentStrChar = strs[0][longestCommonPrefixLength];
    int indexOfCurrentCheckStr = 0;
    
    int isDetectNoCommonChar = 0;

    while(currentStrChar  != '\0')
    { 
        
        while (indexOfCurrentCheckStr < strsSize)
        {
            char *currentStr = strs[indexOfCurrentCheckStr];
            
            if (currentStrChar != currentStr[longestCommonPrefixLength])
            {
                isDetectNoCommonChar = 1;
                break;
            }
            
            indexOfCurrentCheckStr++;
        }

        if (isDetectNoCommonChar)
        {
            break;
        }

        longestCommonPrefixLength++;
        indexOfCurrentCheckStr = 0;
        currentStrChar = strs[indexOfCurrentCheckStr][longestCommonPrefixLength];
        
    }
    
    
    char *result = (char *)malloc(sizeof(char) * longestCommonPrefixLength + 1);
    memcpy (result, strs[indexOfCurrentCheckStr], longestCommonPrefixLength);
    result[longestCommonPrefixLength] = '\0';

    return  result;
    
}


// int main(int argc, char ** argv)
// {

//     char *input[3] =  {"","aaa","aa"};
//     char *result = longestCommonPrefix(input, 3);

//     printf("%s", result);

//     return 0;
// }