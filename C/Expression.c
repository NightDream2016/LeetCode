#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// Define ( = 0 , + = 1, ) = 2
int expression(char *input, int start, int end, int n)
{
    if (input[start] == '(')
    {
        int rightQuotaIndex = -1; 
        for (int i = start; i < n; i++)
        {
            if (input[i] == ')')
            {
                rightQuotaIndex = i;
                break;
            }
        }
        int postResult = expression(input, start + 1, rightQuotaIndex - 1, n);
        
        return postResult;
    }
    else if (input[start] == '+')
    {
        int postResult = expression(input, start + 1, end, n);
        return 1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    char input[10000];
    scanf("%s", input);
    
    int result = expression(input, 0);

    if (result == 0)
    {
        printf("Impossible");
    }
    else
    {
        printf("Possibile");
    }

    return 0;
}