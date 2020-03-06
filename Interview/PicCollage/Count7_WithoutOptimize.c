#include <stdio.h>
#include <stdlib.h>

// 最原始的計算方式，只用DP做，超過一定程度記憶體會爆掉。
int *count7Table;

int count7WithInteger(int n)
{
    int result = 0;
    while (n > 0)
    {
        int remain = n % 10;
        if (remain == 7)
        {
            result++;
        }
        n = n / 10;
    }
    return result;
}

int count7(int N)
{
    if (N == 0)
    {
        return 0;
    }

    int result = count7WithInteger(N);
    
    if (count7Table[N - 1] != 0)
    {
        result += count7Table[N - 1];
        count7Table[N] = result;
        return result;
    }

    return result + count7(N-1);
}

int main()
{
    count7Table = (int *)malloc(sizeof(int) * 100001);
    memset(count7Table, 0, sizeof(int) * 100001);

    int inputArray[] = {6,7,20,70,100,1487,10000,2787,7777,9999};
    
    for (int i = 0; i < 10; i++)
    {
        printf("count7(%d):%d\n", inputArray[i], count7(inputArray[i]));
    }

    system("pause");
}