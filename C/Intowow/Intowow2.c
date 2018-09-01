// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) 
{
    // write your code in C99 (gcc 6.2.0)
    int start = 0;
    int end = 0;
    
    int maximumValue = -1;
    
    int currentSum = 0;
    while (start < N)
    {
        if (A[start] < 0)
        {
            start++;
            end = start;
            continue;
        }
        
        currentSum += A[end];
        end++;

        if (end >= N || A[end] < 0)
        {
            start = end;
            if (maximumValue < currentSum)
            {
                maximumValue = currentSum;
            }
            currentSum = 0;
        }
    }
    
    return maximumValue;
    
}


int main()
{
    int testA[] = {-1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1};

    int result = solution(testA, 14);


    return 0;
}