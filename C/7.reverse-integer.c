#include "stdlib.h"
#include "math.h"
#include "stdio.h"
/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.37%)
 * Total Accepted:    442.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
int isOverflow(int result, int previousResult)
{
    if (abs(result) < 10)
    {
        return 0;
    }

    int remainForOverflowCheck = (abs(result) - previousResult) % 10;

    if (remainForOverflowCheck > 0)
    {
        return 1;
    }

    return 0;
}

int reverse(int x)
{
    int abs_x = (int)abs(x);

    int result = 0;
    int previousResult = 0;
    int logFrom10 = floor(log10((double)abs_x)); // 計算輸入值之於10的對數天花板

    int i = pow(10, logFrom10);
    int currentMutiplier = 1;

    while (i >= 1)
    {
        previousResult = result;
        int currentRemain = abs_x % i;
        result += (abs_x - currentRemain) / i * currentMutiplier;

        if (isOverflow(result, previousResult))
        {
            result = 0;
            break;
        }

        i /= 10;
        abs_x = currentRemain;
        currentMutiplier *= 10;
    }

    if (x < 0)
    {
        result = result * -1;
    }

    return result;
}

int main(int argc, char **argv)
{
    int result = reverse(2147483647);
    system("pause");

    return 0;
}
