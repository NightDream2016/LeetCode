#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 做法範例
// ex 假設要計算的目標是7987
// 先計算 0 ~ 6999 所有的 7 數量
// ->首位數為 0~6, 其他位數為000~999
// ->可視為 0~6(7個可能) * count7(1000) (0~999中所有的7數)
// 7000 ~ 7987 ，一共有987 = 7987 % (10^3)個首位數的7
// ->將首位數去掉
// 換成計算 0 ~ 987 的7數量
// ->依此類推

int count7(int N)
{
    if (N == 0)
    {
        return 0;
    }

    if (N < 0)
    {
        return count7(abs(N));
    }

    // 計算位數
    double numberOfDigit = ceil(log10(N));

    int result = 0;
    int currentTenPower = pow(10.0, numberOfDigit - 1);
    while (currentTenPower >= 1)
    {
        // 計算目前首位數
        int digit = N / currentTenPower;

        // (0 ~ 999...999) * 目前首位數 (計算非首位數的7數量)
        result += digit * count7(currentTenPower);
        
        // 計算首位數7的數量(首位數小於7->不用考慮) 
        if (digit == 7) 
        {
            // 若首位數本身是7，形式為7xxx...xxx，那就是有(xxx...xxx + 1)個7
            result += (N % currentTenPower + 1);
        }
        else if (digit > 7)
        {
            // 首位數大於7，那就是直接加上10^(位數-1)個(因為包含7000...000~7999...999))
            result += currentTenPower;
        }

        // 去掉首位數，繼續計算剩下的位數
        N -= digit * currentTenPower;
        currentTenPower /= 10;
    }
    
    return result;
}

int main()
{
    int inputArray[] = {1,10,100,1000,10000,100000,1000000,2147483647};
    
    for (int i = 0; i < 8; i++)
    {
        printf("count7(%d):%d\n", inputArray[i], count7(inputArray[i]));
    }

    system("pause");
}