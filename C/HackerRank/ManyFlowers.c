#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// 花朵品種
typedef struct spice
{
    int spiceNumber;    // 品種編號
    int firstIndexOfSpiceNumber;    // 該品種第一次出現的Index
    int lastIndexOfSpiceNumber;    // 該品種最後一次出現的Index
    int num;    // 品種在花園裡的數量
}
Spice;

// 用來將Spice出現的次數加一
void plusSpiceCount(Spice *spiceTable, int n, int spiceNumber, int index)
{
    int spiceIndex = spiceNumber % n; // Hash Function, 先用Mod做

    // Conflict，往陣列下一個找，直到找到空的Table(SpiceNumber為-1)，或是spiceNumber一樣
    while (spiceTable[spiceIndex].spiceNumber != -1 && spiceTable[spiceIndex].spiceNumber != spiceNumber) 
    {
        spiceIndex += 1;
        spiceIndex = spiceIndex % n;
    }

     // 第一次遇到的Spice(SpiceNumber為-1)，那就將spiceNumber指定進去，並順便記下第一次出現此Spice的index
    if (spiceTable[spiceIndex].spiceNumber == -1)  
    {
        spiceTable[spiceIndex].spiceNumber = spiceNumber;
        spiceTable[spiceIndex].firstIndexOfSpiceNumber = index;
    }

    // 品種出現次數加一
    spiceTable[spiceIndex].num += 1;
    spiceTable[spiceIndex].lastIndexOfSpiceNumber = index;
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;

    scanf("%d", &n);

    // int *a = malloc(sizeof(int) * n); 

    // 用來記錄各種Spice出現次數的HashTable
    Spice *spiceTable = malloc(sizeof(Spice) * n);

    // 初始化品種記錄表，空品種的話spiceNumber會是-1
    for (int i = 0; i < n; i++)
    {
        Spice emptySpice;
        emptySpice.num = 0;
        emptySpice.firstIndexOfSpiceNumber = -1;
        emptySpice.lastIndexOfSpiceNumber = -1;
        emptySpice.spiceNumber = -1;
        spiceTable[i] = emptySpice;
    }

    // 讀進來的時候就直接將表建完了
    for (int i = 0; i < n; i++ )
    {
        int input = 0;
        scanf("%d", &input);
        // a[i] = input;
        plusSpiceCount(spiceTable, n , input, i);
    }

    // Debug用，輸出SpiceTable記錄的結果
    // for (int i = 0; i < n; i++ )
    // {
    //     printf("spiceTable Index:%d, spiceNumber:%d, num:%d, firstIndex:%d\n", i, spiceTable[i].spiceNumber, spiceTable[i].num, spiceTable[i].firstIndexOfSpiceNumber);
    // }

    int maximumCount = 0;
    int legnthOfGarden = n;
    int firstIndexOfSpice = n;
    int spiceForResultIndex = -1;

    // 找出出現次數最多的Spice
    for (int i = 0; i < n; i++)
    {
        int legnthOfCurrentSpice = spiceTable[i].lastIndexOfSpiceNumber - spiceTable[i].firstIndexOfSpiceNumber + 1;
        if (spiceTable[i].spiceNumber == -1)
        {
            continue;
        }

        if (spiceTable[i].num > maximumCount)
        {
            maximumCount = spiceTable[i].num;
            legnthOfGarden = legnthOfCurrentSpice;
            firstIndexOfSpice = spiceTable[i].firstIndexOfSpiceNumber;
            spiceForResultIndex = i;
            continue;
        }

        if (spiceTable[i].num == maximumCount)  // 數量一樣，選長度短的
        {
            if (legnthOfCurrentSpice < legnthOfGarden)
            {
                legnthOfGarden = legnthOfCurrentSpice;
                spiceForResultIndex = i;
            }
            else
            {
                if (legnthOfCurrentSpice == legnthOfGarden) // 數量長度都一樣，選在前面的
                {
                    if (spiceTable[i].firstIndexOfSpiceNumber < firstIndexOfSpice)
                    {
                        firstIndexOfSpice = spiceTable[i].firstIndexOfSpiceNumber;
                        spiceForResultIndex = i;
                    }
                }
            }
            continue;
        }
    }

    Spice spiceOfResult = spiceTable[spiceForResultIndex];


    // 因為是用陣列Index去記所以輸出時加一
    printf("%d %d", spiceOfResult.firstIndexOfSpiceNumber + 1, spiceOfResult.lastIndexOfSpiceNumber + 1);

    return 0;
}