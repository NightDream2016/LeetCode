#include <stdio.h>
#include <stdlib.h>

#define bool int;

/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.38%)
 * Total Accepted:    216.1K
 * Total Submissions: 886.6K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// 配上Dyanmic Programming的做法
int isMatchWithDPTable(char *s, char *p, int stringIndex, int patternIndex, int **dptable, int dpTableRow, int dpTableColumn)
{
    
    // 全部為空 ->回傳1
    if (*s == '\0' && *p == '\0')
    {
        if (stringIndex < dpTableRow && patternIndex < dpTableColumn)
        {
            dptable[stringIndex][patternIndex] = 1;
        }
        
        return 1;
    }

    if (stringIndex < dpTableRow && patternIndex < dpTableColumn && dptable[stringIndex][patternIndex] != -1)
    {
        // printf("DPTable:%d OfStringIndex:%d, PatternIndex:%d\n", dptable[stringIndex][patternIndex], stringIndex, patternIndex);
        return dptable[stringIndex][patternIndex];
    }

    // 帶星號的情況要比不帶星號的情況優先核對。因為帶星號可以視為空字串，所以看到有星號就一定要先看下一個pattern。
    // 以這個為原則下去思考即可。
    if (p[1] == '*')
    {   
        // p[1]帶星號的情況，這裡要先確定s跟下一個pattern對不對的上。
        // 也就是，在每一個後續的遞迴內，都要確認"目前的string能不能夠被後面的pattern對掉"，再來確認string跟目前的pattern符不符合
        // 如果string可以對的上後面的pattern，就要直接回傳1，不需要管跟目前的pattern如何核對
        // (因為目前的pattern是帶星號的，可以直接視為長度0)
        // 否則要是先讓string跟目前的pattern核對完再去對後面的pattern，那有可能發生
        // "目前的string對完目前的pattern以後卻反而跟後面的pattern的對不上了"，導致本來可以對上的pattern沒確認到。
        // (例如 ["aaa", "a*a"] 這種例子，要是這裡不先做的話對到最後會變成 ["", "a"]，就GG了)

        int isNextPatternMatch = isMatchWithDPTable(s, p + 2, stringIndex, patternIndex + 2, dptable, dpTableRow, dpTableColumn);
        if (stringIndex < dpTableRow && patternIndex + 2 < dpTableColumn)
        {
            dptable[stringIndex][patternIndex + 2] = isNextPatternMatch;
        }

        if(isNextPatternMatch == 0)
        {
            // 因為有包含p[0] == '.'的情況，所以要把s為空字串的情況考慮進去 
            // (不然就會一律看到p[0] == '.'就給過，而s為空字串時邏輯就錯了)
            if (*s != '\0' && (s[0] == p[0] || p[0] == '.'))
            {
                int isCurrentPatternMatch = isMatchWithDPTable(s + 1, p, stringIndex + 1, patternIndex, dptable, dpTableRow, dpTableColumn); 

                if (stringIndex + 1 < dpTableRow && patternIndex < dpTableColumn)
                {
                    dptable[stringIndex + 1][patternIndex] = isCurrentPatternMatch;
                }

                return isCurrentPatternMatch;
            }
        }

        if (stringIndex < dpTableRow && patternIndex < dpTableColumn)
        {
            dptable[stringIndex][patternIndex] = isNextPatternMatch;
        }
        
        return isNextPatternMatch;

    }

    // 同上面的註解，都一定要把s為空字串的情況考慮進去
    if (*s != '\0' && (s[0] == p[0]  || p[0] == '.'))
    {
        int isCurrentPatternMatch = isMatchWithDPTable(s+1, p+1, stringIndex + 1, patternIndex + 1, dptable, dpTableRow, dpTableColumn);

        if (stringIndex + 1 < dpTableRow && patternIndex + 1 < dpTableColumn)
        {
            dptable[stringIndex + 1][patternIndex + 1] = isCurrentPatternMatch;
        }
        
        return isCurrentPatternMatch;
    }
    
    // 以上條件全都不符合，就丟0
    if (stringIndex < dpTableRow && patternIndex < dpTableColumn)
    {
        dptable[stringIndex][patternIndex] = 0;
    }

    return 0;

}


bool isMatch(char* s, char* p) 
{
    // Dynamic Programming, 用動態二維陣列去記結果
    int slength = strlen(s) + 1;
    int plength = strlen(p) + 1;

    int **dpTable = (int **)malloc(sizeof(int *) * slength);

    for (int i = 0; i < slength; i++)
    {
        int *currentDPRowArray = (int *)malloc(sizeof(int) * plength);
        memset(currentDPRowArray, -1, sizeof(int) * plength);
        dpTable[i] = currentDPRowArray;
    }

    int result = isMatchWithDPTable(s, p, 0, 0, dpTable, slength, plength);
    
    for (int i = 0; i < slength; i++)
    {
        int *currentPtr= dpTable[i];
        free(currentPtr);
    }
    
    return result;  
}


// int main(int argc, char ** argv)
// {
//     int result1 = isMatch("","..*");
//     int result2 = isMatch("aaa","aaaa*b*c*");
//     int result3 = isMatch("mississippi","mis*is*ip*.");
//     int result4 = isMatch("aa",".");
//     int result5 = isMatch("aab","c*a*b*");

    
//     return 0;
// }
