#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

typedef struct rangeResult
{
    int start;
    int end;
    long result;
}
RangeResult;

enum RangeRelation
{
    noRelation = 0,
    equal,
    crossLeft, // 交集，A左B右
    crossRight, // 交集，A右B左
    subset, // A為B子集
    superset // A為B超集
};

// 回傳RangeA和B的關係
// "RangeA是B的...."
RangeRelation relationOfRange(RangeResult rangeA, RangeResult rangeB)
{
    if (rangeA.start > rangeB.start)
    {
        if (rangeA.start > rangeB.end)
        {
            return noRelation;   
        }
        
        if (rangeA.end <= rangeB.end)
        {
            return subset;
        }
        else
        {
            return crossLeft;
        }
    }
    else if (rangeA.start == rangeB.start)
    {
        if (rangeA.end > rangeB.end)
        {
            return superset;
        }
        else if (rangeA.end == rangeB.end)
        {
            return equal;
        }
        else
        {
            return subset;
        }
    }
    else
    {
        if (rangeA.end < rangeB.start)
        {
            return noRelation;   
        }

        if (rangeA.end >= rangeB.end)
        {
            return superset;
        }
        else
        {
            return crossRight;
        }   
    }
}

RangeResult *addRange(RangeResult resultArray[], int *rangeResultCount, RangeResult newRange)
{
    int newResultCount = *rangeResultCount;
    for (int i = 0; i < *rangeResultCount; i++)
    {
        RangeResult currentRange = resultArray[i];
        RangeRelation relation = RangeRelation(currentRange, newRange);

        if (relation == noRelation)
        {
            continue;
        }

        if (relation == equal)
        {
            currentRange.result += newRange.result;
            resultArray[i] = currentRange;
            break;
        }

        if (relation == cross)
        {

        }
    }
}


// Complete the arrayManipulation function below.
long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {

    RangeResult *resultArray = (RangeResult *)malloc(sizeof(RangeResult) * n);
    // memset(resultArray, 0, sizeof(RangeResult) * n);
    RangeResult initRange;
    initRange.start = 0;
    initRange.end = n - 1;
    initRange.result = 0;

    resultArray[0] = initRange;
    int rangeResultNum = 1;
    
    for (int i = 0; i < queries_rows; i++)
    {
        int a = queries[i][0];  //先取出a b k
        int b = queries[i][1];
        long k = (long)queries[i][2];
        
        int rangeStart = a - 1; //新範圍的Start和End，因為輸入是從1起算所以要減1才會變成陣列座標
        int rangeEnd = b - 1;

     
        RangeResult newRangeArray[2];
        for (int j = 0; j < rangeResultNum; j++)
        {
            RangeResult currentRange = resultArray[j];

            // 無交集，搜下一個Range
            if (rangeStart > currentRange.end && rangeEnd < currentRange.start)
            {
                continue;
            }

            // 剛好等同目前Range，直接加目前Range的結果
            if (rangeStart == currentRange.start && rangeEnd == currentRange.end)
            {
                currentRange.result += k;
                resultArray[j] = currentRange;
                break;
            }

            // 為目前Range的子集，目前Range變成2~3個新的Range
            if (rangeStart >= currentRange.start && rangeEnd <= currentRange.end)
            {
                RangeResult newRange;
                newRange.start = rangeStart;
                newRange.end = rangeEnd;
                newRange.result = k + currentRange.result;

                if (rangeStart == currentRange.start)
                {
                    currentRange.start = rangeEnd + 1;
                    resultArray[j] = currentRange;
                    resultArray[rangeResultNum] = newRange;
                    rangeResultNum++;
                    break;
                }

                if (rangeEnd == currentRange.end)
                {
                    currentRange.end = rangeStart - 1;
                    resultArray[j] = currentRange;
                    resultArray[rangeResultNum] = newRange;
                    rangeResultNum++;
                    break;
                }
                
                RangeResult newRangePrev, newRangeNext;
                newRangePrev.start = currentRange.start;
                newRangePrev.end = rangeStart - 1;
                newRangePrev.result = currentRange.result;

                newRangeNext.start = rangeEnd + 1;
                newRangeNext.end = currentRange.end;
                newRangeNext.result = currentRange.result;

                resultArray[j] = newRange;
                resultArray[rangeResultNum] = newRangePrev;
                resultArray[rangeResultNum + 1] = newRangeNext;
                rangeResultNum += 2;
                break;
            }

            // 完全包含目前的Range，這表示目前Range會受影響，但依然要處理交集Range
            if (rangeStart < currentRange.start && rangeEnd > currentRange.end)
            {
                currentRange.result += k;
                resultArray[j] = currentRange;
                continue;
            }

            // 與目前Range在前半部分有交集
            if (rangeStart <= currentRange.end && rangeStart > currentRange.start)
            {
                RangeResult newRangeResult;
                newRangeResult.start = rangeStart;
                newRangeResult.end = currentRange.end;
                newRangeResult.result = currentRange.result + k;

                currentRange.end = rangeStart - 1;

                resultArray[j] = currentRange;
                resultArray[rangeResultNum] = newRangeResult;
                rangeResultNum++;
                continue;
            }

            // 與目前Range在後半部分有交集
            if (rangeEnd >= currentRange.start && rangeEnd < currentRange.end)
            {
                RangeResult newRangeResult;
                newRangeResult.start = currentRange.start;
                newRangeResult.end = rangeEnd;
                newRangeResult.result = currentRange.result + k;

                currentRange.start = rangeEnd + 1;
                
                resultArray[j] = currentRange;
                resultArray[rangeResultNum] = newRangeResult;
                rangeResultNum++;
                continue;
            }
        }

        printf("Round %d\n", i);
        for (int k = 0; k < rangeResultNum; k++)
        {
            RangeResult currentRangeResult = resultArray[k];
            
            printf("Range Result:%d, start:%d, end:%d, result:%ld\n", k, currentRangeResult.start + 1, currentRangeResult.end + 1, currentRangeResult.result);
        }

    }
    
    long maximum = 0;
    
    for (int i = 0; i < rangeResultNum; i++)
    {
        RangeResult currentRangeResult = resultArray[i];
        if (currentRangeResult.result > maximum)
        {
            maximum = currentRangeResult.result;
        }
    }
    
    return maximum;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    int** queries = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(readline());

        for (int j = 0; j < 3; j++) {
            char* queries_item_endptr;
            char* queries_item_str = *(queries_item_temp + j);
            int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

            if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(queries + i) + j) = queries_item;
        }
    }

    int queries_rows = m;
    int queries_columns = 3;

    long result = arrayManipulation(n, queries_rows, queries_columns, queries);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
