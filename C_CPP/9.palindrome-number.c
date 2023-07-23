/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (37.49%)
 * Total Accepted:    366.6K
 * Total Submissions: 977.9K
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
int reverseInteger(int x)
{

    unsigned long long result = 0;
    int i = 1;
    do
    {
        int remain = x % 10;
        result = result * 10 + remain;
        x = (x - remain) / 10;
    }
    while (x > 0);

    return result;
}

int isPalindrome(int x) 
{
    if (x < 0)
    {
        return 0;
    }

    if (x == 0)
    {
        return 1;
    }

    int reverseResult = reverseInteger(x);

    return (reverseResult == x);

}


int main(int argc, char ** argv)
{
    int result = isPalindrome(12321);
    
    return 0;
}



