#include <stdint.h>
#include <stdbool.h>
#define MAXSTACKSPACE 20

char stack[MAXSTACKSPACE];
int stacktop = -1;

int64_t int64abs(int64_t a, int64_t b)
{
    int64_t result = a - b;

    if (a < b)
    {
        result = b - a;
    }
    
    return result;
}

#pragma region Stack Utility

void stackFlush()
{
    for (int i = 0; i < MAXSTACKSPACE; i++)
    {
        stack[i] = '\0';
    }
    
    stacktop = -1;
}

void stackPush(char n)
{
    if (stacktop == MAXSTACKSPACE -1 )
    {
        // Full
        return;
    }
    
    stacktop+=1;
    stack[stacktop] = n;
}

char stackPop()
{
    if (stacktop == -1 )
    {
        // Full
        return '\0';
    }
   
    char result = stack[stacktop];
    stacktop -= 1;
    return result;
}

#pragma endregion

#pragma region Digit Handling Utlity

// 字元 - 1
char digitMinusOne(char oriDigit)
{
    char resultDigit = oriDigit - 1;
    
    if (oriDigit == '0')
    {
        resultDigit = '9';
    }
    
    return resultDigit;
}

// 字元 + 1
char digitPlusOne(char oriDigit)
{
    char resultDigit = oriDigit + 1;
    
    if (oriDigit == '9')
    {
        resultDigit = '0';
    }
    
    return resultDigit;
}

// 字串轉int64整數
int64_t digitStringToInteger(char *digitString)
{
    int strLength = 0;
    while(digitString[strLength] != '\0')
    {
        strLength++;
    }
    
    int64_t tenPower = 1;
    int64_t result = 0;
    for (int i = strLength - 1; i >= 0; i--)
    {
        int digit = digitString[i] - 48;
        result += digit * tenPower;
        tenPower *= 10;
    }

    return result;
}

#pragma endregion

#pragma region AllNine / OneZeroOne Special Case
// 是否為1000...0001型式的整數字串 (因為會影響到"下一個回文整數"的判斷)
bool isOneZeroOneStr(char *digitString, int strLength)
{
    bool isOneZeroOne = true;
    
    // 長度只有1的話肯定不是
    if (strLength == 1)
    {
        return false;
    }
    
    for (int i = 0; i < strLength; i++)
    {
        if (i == 0 || i == strLength - 1)
        {
            if (digitString[i] != '1')
            {
                isOneZeroOne = false;
                break;
            }
        }
        else
        {
            if (digitString[i] != '0')
            {
                isOneZeroOne = false;
                break;
            }
        }
    }
    
    return isOneZeroOne;
}

// 是否為999...999型式的整數字串 (因為會影響到"下一個回文整數"的判斷)
bool isAllNineStr(char *digitString, int strLength)
{
    bool isAllNine = true;
    
    for (int i = 0; i < strLength; i++)
    {
        if (digitString[i] != '9')
        {
            isAllNine = false;
            break;
        }
    }
    
    return isAllNine;
}

// 1000...0001轉成對應的999...999 ("取上一個回文整數"時用到)
char *oneZeroOneToAllNine(char *digitString, int strLength)
{
    char *resultStr = (char *)malloc(sizeof(char) * strLength);
    
    for (int i = 0; i < strLength - 1; i++)
    {
        resultStr[i] = '9';
    }
    
    resultStr[strLength - 1] = '\0';
    
    return resultStr;
}

// 999...999轉成對應的1000...0001 ("取下一個回文整數"時用到)
char *allNineToOneZeroOne(char *digitString, int strLength)
{
    char *resultStr = (char *)malloc(sizeof(char) * (strLength + 2));
    
    for (int i = 0; i < strLength + 1; i++)
    {
        if (i == 0 || i == strLength)
        {
            resultStr[i] = '1';
        }
        else
        {
            resultStr[i] = '0';
        }
    }
    
    resultStr[strLength + 1] = '\0';
    
    return resultStr;
}

#pragma endregion

#pragma region Parlindromic
// 從一個回文整數取下一個回文整數 (ex 12321 -> 12421, 10901 -> 11011)
char *nextParlindromic(char *digitString, int strLength)
{
    char *resultStr = NULL;

    // 如果是999...999，就轉成1000...0001
    bool isAllNine = isAllNineStr(digitString, strLength);
    if (isAllNine)
    {
        resultStr = allNineToOneZeroOne(digitString, strLength);
        return resultStr;
    }

    resultStr = (char *)malloc(sizeof(char) * (strLength + 1));
    for (int i = 0; i < strLength; i++)
    {
        resultStr[i] = digitString[i];
    }

    resultStr[strLength] = '\0';
    int midIndex = strLength / 2;

    if (digitString[midIndex] == '9') 
    {
        // 中央的數字是9時，取下一個回文要多考慮前後各一個數字
        // ex 1299921 下一個數字會是1300031
        // 所以要多考慮兩邊的2

        int midLeft = midIndex;
        int midRight = midIndex;
        while (digitString[midLeft] == '9' && midLeft >= 0)
        {
            resultStr[midLeft] = digitPlusOne(digitString[midLeft]);
            midLeft--;
        }

        if (midLeft >= 0)
        {
            resultStr[midLeft] = digitPlusOne(digitString[midLeft]);
        }
        
        while (digitString[midRight] == '9' && midRight < strLength)
        {
            resultStr[midRight] = digitPlusOne(digitString[midRight]);
            midRight++;
        }

        if (midRight < strLength)
        {
            resultStr[midRight] = digitPlusOne(digitString[midRight]);
        }
    }
    else
    {
        // 單純的把中間的數字 + 1
        // ex 121 -> 131
        resultStr[midIndex] = digitPlusOne(digitString[midIndex]); 

        bool isStrLengthOdd = (strLength % 2);
        if (isStrLengthOdd == false) 
        {
            // 若數字字串長度為偶數，則要將兩個數字 + 1
            // ex 1221 -> 1331
            resultStr[midIndex - 1] = digitPlusOne(digitString[midIndex - 1]);
        }
    }

    return resultStr;
}

// 從一個回文整數取上一個回文整數 (ex 12421 -> 12321, 11011 -> 10901)
char *previousParlindromic(char *digitString, int strLength)
{
    char *resultStr = NULL;

    bool isTenPower = isOneZeroOneStr(digitString, strLength);
    if (isTenPower)
    {
        resultStr = oneZeroOneToAllNine(digitString, strLength);
        return resultStr;
    }

    resultStr = (char *)malloc(sizeof(char) * (strLength + 1));
    for (int i = 0; i < strLength; i++)
    {
        resultStr[i] = digitString[i];
    }

    resultStr[strLength] = '\0';
    int midIndex = strLength / 2;

    if (digitString[midIndex] == '0') 
    {
        // 中央的數字是0時，取上一個回文要多考慮前後各一個數字
        // ex 1200021 上一個數字會是1199911
        // 所以要多考慮兩邊的2

        int midLeft = midIndex;
        int midRight = midIndex;
        while (digitString[midLeft] == '0' && midLeft >= 0)
        {
            resultStr[midLeft] = digitMinusOne(digitString[midLeft]);
            midLeft--;
        }

        if (midLeft >= 0)
        {
            resultStr[midLeft] = digitMinusOne(digitString[midLeft]);
        }

        while (digitString[midRight] == '0' && midRight < strLength)
        {
            resultStr[midRight] = digitMinusOne(digitString[midRight]);
            midRight++;
        }

        if (midRight < strLength)
        {
            resultStr[midRight] = digitMinusOne(digitString[midRight]);
        }
    }
    else
    {
        // 單純的把中間的數字 - 1
        // ex 121 -> 131
        resultStr[midIndex] = digitMinusOne(digitString[midIndex]); // xAx pattern, result is x(A-1)x

        bool isStrLengthOdd = (strLength % 2);
        if (isStrLengthOdd == false) // xAAx pattern, result is x(A-1)(A-1)x
        {
            // 若數字字串長度為偶數，則要將兩個數字 - 1
            // ex 1221 -> 1331
            resultStr[midIndex - 1] = digitMinusOne(digitString[midIndex - 1]);
        }
    }

    return resultStr;
}

// 找出 (可能的) 最近回文整數，也就是取前半段，然後鏡射到右半段 (ex 12345 -> 12321)
char *rawFindParlindromic(char *digitString, int strLength)
{
    // 用Stack來產生回文整數
    for (int i = 0; i < strLength; i++)
    {
        stackPush(digitString[i]);
    }

    char *resultStr = (char *)malloc(sizeof(char) * (strLength + 1));
    
    for (int i = 0; i < strLength; i++)
    {
        char popDigit = stackPop();
        
        // 前半段直接複製，後半段用stack pop出來的digit, 也就是鏡像字串
        if (i < strLength / 2)
        {
            resultStr[i] = digitString[i];
        }
        else
        {
            resultStr[i] = popDigit;
        }
    }
    
    resultStr[strLength] = '\0';
        
    stackFlush();

    return resultStr;
}

#pragma endregion

char *nearestPalindromic(char * n)
{
    // Calcualte string length
    int strLength = 0;
    while(n[strLength] != '\0')
    {
        strLength++;
    }

    // 先找出可能回文整數
    char *rawFindNumberString = rawFindParlindromic(n, strLength);

    // 然後利用這個可能回文整數，取下一個或上一個
    char *nextNumberString = nextParlindromic(rawFindNumberString, strLength);
    char *previousNumberString = previousParlindromic(rawFindNumberString, strLength);

    // 接著再分別計算哪一個離原數最近
    int64_t rawFindNumber = digitStringToInteger(rawFindNumberString);
    int64_t currentNumber = digitStringToInteger(n);
    int64_t nextNumber = 0;
    int64_t previousNumber = 0;

    if (rawFindNumber < currentNumber)
    {
        // 可能回文整數比原數小
        // 表示順序為 可能回文整數 - 原數 - 下一個
        previousNumber = rawFindNumber;
        previousNumberString = rawFindNumberString;
        nextNumber = digitStringToInteger(nextNumberString);
    }
    else if (rawFindNumber > currentNumber)
    {
        // 可能回文整數比原數大
        // 表示順序為 上一個回文整數 - 原數 - 可能回文整數
        previousNumber = digitStringToInteger(previousNumberString);
        nextNumber = rawFindNumber;
        nextNumberString = rawFindNumberString;
    }
    else
    {
        // 原文本身就是回文整數
        // 那順序就是 上一個回文整數 - 原數 - 下一個回文整數
        previousNumber = digitStringToInteger(previousNumberString);
        nextNumber = digitStringToInteger(nextNumberString);
    }
    
    // 最後再判斷哪個數離原數在數線上最近即大功造成
    char *resultString = previousNumberString;
    int64_t result = int64abs(nextNumber, currentNumber) - int64abs(currentNumber, previousNumber);
    if (result < 0)
    {
        resultString = nextNumberString;
    }

    // 懶人包 : 簡單的說就是先找出該數的前後回文數，再來判斷哪一個離原數比較近。
    // 而其他的Method都是用來從一個回文數找"上一個回文數""下一個回文數"，或是對原數做鏡射來找一個接近的回文數用的
    // 比如原數是12345，那先用鏡射法找一個最接近的12321
    // 12321 < 12345，也就是我們要找12321的下一個回文數，12421
    // 而最後判斷出來 12345 - 12321 = 34, 12421 - 12345 = 76, 答案就是12321。
    // 比較要注意的點是像99999這種回文數的下一個回文數是1000001，反之1000001的上一個回文數是99999
    // 或是 1299921的下一個回文數是1300031，這種有進位的情況要另外處理比較麻煩，完。

    return resultString;
}

int main()
{

    char resultArray[][6] = {"0","1","12345","1283"};
    int i = 0;
    for (int i = 0; i < 4; i++)
    {
        char *result = nearestPalindromic(resultArray[i]);

        printf("%s\n", result);        
    }
    printf("stop.");
}