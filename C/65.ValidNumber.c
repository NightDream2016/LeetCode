#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INDEX_INAVLID -100
#define INDEX_NOT_FOUND -1

typedef bool (*CharaterUtility)(char element);

typedef enum numberType
{
    INVALID_TYPE = -1,
    INTEGER = 0,
    DECIMAL = 1,
    EXPONENT = 2
} NumberType;

/////////////////////////////////////////////////
// Character Utility
bool isSpace(char element)
{
    if (element == ' ')
    {
        return true;
    }

    return false;
}

bool isDigit(char element)
{
    return (element >= '0' && element <= '9');
}

bool isExponent(char element)
{
    return element == 'e';
}

bool isSign(char element)
{
    return (element == '+' || element == '-');
}

bool isDecimalPoint(char element)
{
    return element == '.';
}

bool isElementValid(char element)
{
    if (isDigit(element) || isExponent(element) || isSign(element) || isDecimalPoint(element))
    {
        return true;
    }

    return false;
}

/////////////////////////////////////////////////
// Index Utlity
void checkIndexOfCharacterWithUtility(char *s, CharaterUtility utility, int *elementIndex, int *elementCount, int *strLength)
{
    int index = 0;
    int digitCount = 0;
    *elementIndex = INDEX_NOT_FOUND;
    *elementCount = 0;
    while (s[index] != '\0')
    {
        if (utility(s[index]))
        {
            *elementIndex = index;
            *elementCount = *elementCount + 1;
        }

        if (isDigit(s[index]))
        {
            digitCount++;
        }

        if (isElementValid(s[index]) == false)
        {
            *elementIndex = INDEX_INAVLID;
            break;
        }

        index++;
    }

    if (digitCount <= 0)
    {
        *elementIndex = INDEX_INAVLID;
    }

    *strLength = index;
}

int exponentIndexOfNumber(char *s)
{
    int strLength = 0;
    int exponentIndex = INDEX_NOT_FOUND;
    int exponentCount = 0;

    checkIndexOfCharacterWithUtility(s, isExponent, &exponentIndex, &exponentCount, &strLength);

    if (exponentIndex == INDEX_NOT_FOUND)
    {
        return exponentIndex;   
    }

    // Invalid State
    if (exponentCount > 1)
    {
        exponentIndex = INDEX_INAVLID;
    }

    if (exponentIndex == 0 || exponentIndex == (strLength - 1))
    {
        exponentIndex = INDEX_INAVLID;
    }

    return exponentIndex;
}

int decimalPointIndexOfNumber(char *s)
{
    int strLength = 0;
    int decimalPointIndex = INDEX_NOT_FOUND;
    int decimalPointCount = 0;

    checkIndexOfCharacterWithUtility(s, isDecimalPoint, &decimalPointIndex, &decimalPointCount, &strLength);

    if (decimalPointIndex == INDEX_NOT_FOUND)
    {
          
    }
    else
    {
        if (decimalPointCount > 1 || strLength == 1)
        {
            decimalPointIndex = INDEX_INAVLID;
        }
    }
    
    return decimalPointIndex;
}

int signIndexOfNumber(char *s)
{
    int strLength = 0;
    int signCount = 0;
    int signIndex = INDEX_NOT_FOUND;

    checkIndexOfCharacterWithUtility(s, isSign, &signIndex, &signCount, &strLength);

    if (signIndex == INDEX_NOT_FOUND)
    {

    }
    else
    {
        // Invalid State
        if (signCount > 1 || signIndex > 0 || strLength == 1)
        {
            signIndex = INDEX_INAVLID;
        }
    }

    return signIndex;
}

/////////////////////////////////////////////////
// Check Valid
NumberType numberTypeChecking (char *s)
{
    int exponentIndex = exponentIndexOfNumber(s);
    NumberType result = EXPONENT;
    
    if(exponentIndex == INDEX_INAVLID)
    {
        result = INVALID_TYPE;
    }
    else if (exponentIndex == INDEX_NOT_FOUND)
    {
        int decimalPointIndex = decimalPointIndexOfNumber(s);
        int signIndex = signIndexOfNumber(s);

        if (decimalPointIndex == INDEX_INAVLID || signIndex == INDEX_INAVLID)
        {
            result = INVALID_TYPE;
        }
        else
        {
            if (decimalPointIndex == INDEX_NOT_FOUND)
            {
                result = INTEGER;
            }
            else
            {
                result = DECIMAL;
            }
        }
    }

    return result;
}

/////////////////////////////////////////////////
// Space Trimming
char *trimmingSpaceOfString(char *s)
{
    int strLength = strlen(s);

    if (strLength == 0)
    {
        return s;
    }

    int leftIndex = 0;
    while (leftIndex < strLength)
    {
        if (isSpace(s[leftIndex]) == false)
        {
            break;
        }
        leftIndex++;
    }

    int rightIndex = strLength - 1;
    while(rightIndex >= 0)
    {
        if (isSpace(s[rightIndex]) == false)
        {
            break;
        }
        rightIndex--;
    }

    if (rightIndex < leftIndex) // String is Full of Space
    {
        return "";
    }

    int resultStrLength = (rightIndex - leftIndex) + 1;
    char *resultStr = (char *)malloc(sizeof(char) * resultStrLength + 1);

    strncpy(resultStr, s + leftIndex, resultStrLength);
    resultStr[resultStrLength] = '\0';

    // printf("resultStr:%s\n", resultStr);
    return resultStr;
}


/////////////////////////////////////////////////
// Main Solution Function
bool isNumber(char * s)
{
    char *numberWithoutSpace = trimmingSpaceOfString(s);
    // printf("numberWithoutSpace:%s\n", numberWithoutSpace);
    if (strlen(numberWithoutSpace) == 0)
    {
        return false;
    }

    NumberType numberType = numberTypeChecking (numberWithoutSpace);

    bool result = true;

    if (numberType == INVALID_TYPE)
    {
        result = false;
    }
    else if (numberType == EXPONENT)
    {
        // printf("exponent\n");
        int exponentIndex = exponentIndexOfNumber(numberWithoutSpace);
        int strLength = strlen(numberWithoutSpace);
        // printf("exponentIndex:%d, strLength:%d\n", exponentIndex, strLength);
        int baseStrLength = exponentIndex + 1;
        int expStrLength = (strLength - exponentIndex);
        char *baseNumber = (char *)malloc(sizeof(char) * baseStrLength); 
        char *expNumber = (char *)malloc(sizeof(char) * expStrLength); 

        strncpy(baseNumber, numberWithoutSpace, baseStrLength - 1);
        baseNumber[baseStrLength - 1] = '\0';

        strncpy(expNumber, numberWithoutSpace + exponentIndex + 1, expStrLength - 1);
        expNumber[expStrLength - 1] = '\0';

        // printf("baseNumber:%s expNumber:%s \n", baseNumber, expNumber);

        NumberType baseNumberType = numberTypeChecking (baseNumber);
        NumberType expNumberType = numberTypeChecking (expNumber);

        if (expNumberType == DECIMAL || expNumberType == INVALID_TYPE)
        {
            result = false;
        }        

        if (baseNumberType == INVALID_TYPE)
        {
            result = false;
        }

        free(baseNumber);
        free(expNumber);
    }

    free(numberWithoutSpace);

    return result;
    
}

int main()
{
    char resultArray[][40] = {"-.",
                    "-",
                    ".",
                    "   ",
                    "2e10",
                    " -90e3   ",
                    " 1e",
                    "e3",
                    " 6e-1",
                    " 99e2.5 ",
                    "53.5e93",
                    " --6 ",
                    "-+3",
                    "95a54e53"};
    int i = 0;
    for (int i = 0; i < 14; i++)
    {
        bool result = isNumber(resultArray[i]);
        if (result == false)
        {
            printf("%s => false\n", resultArray[i]);
        }
        else
        {
            printf("%s => true \n", resultArray[i]);
        }        
    }
    printf("stop.");
}