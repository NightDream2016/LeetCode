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

typedef struct range
{
    int start;
    int end;
    long result;
}
Range;

enum RangeRelation
{
    noRelation = 0,
    equal,
    crossLeft, // 交集，A左B右
    crossRight, // 交集，A右B左
    subset, // A為B子集
    superset // A為B超集
};

typedef enum indexLocationOfRange
{
    NotIn_RightSide = -2, // 在Range右邊外面
    NotIn_LeftSide = -1, // 在Range左邊外面
    LocationOfRangeNull = 0, // 空值 (非法結果)
    Between = 1, // 在Range中央(非左右端點)
    LeftSide = 2,  // 在Range左端點
    RightSide = 3  // 在Range右端點
}
IndexLocationOfRange;

Range createRange(int start, int end , long result)
{
    Range range;
    range.start = start;
    range.end = end;
    range.result = result;

    return range;
}

IndexLocationOfRange findIndexLocationInRange(int index, Range range)
{
    if(index == range.start)
    {
        return LeftSide;
    }

    if (index == range.end)
    {
        return RightSide;
    }

    if (index > range.start && index < range.end)
    {
        return Between;
    }

    if (index < range.start)
    {
        return NotIn_LeftSide;
    }

    if (index > range.end)
    {
        return NotIn_RightSide;
    }

    return LocationOfRangeNull;
}


int findRangeIndexInTableFromArrayIndex(Range rangeTable[], int rangeTableCount, int index)
{
    IndexLocationOfRange location = LocationOfRangeNull;
    int left = 0;
    int right = rangeTableCount - 1;
    int result = -1;
    while (left <= right)
    {
        
        int middle = (left + right) / 2;
        Range middleRange = rangeTable[middle];
        IndexLocationOfRange location = findIndexLocationInRange(index, middleRange);

        if (location == NotIn_LeftSide)
        {
            right = middle - 1;
        }
        else if (location == NotIn_RightSide)
        {
            left = middle + 1;
        }
        else
        {
            result = middle;
            break;
        }

    }

    // printf("findRange:Start:%d, End:%d, Result:%d\n", findRange.start, findRange.end, findRange.result);
    return result;    
    
}


int isRangeEqual(Range a, Range b)
{
    if (a.start == b.start)
    {
        return 1;
    }

    return 0;
}


// Complete the arrayManipulation function below.
// 曠世名題！
long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {

    long *resultArray = (long *)malloc(sizeof(long) * n);
  
    memset(resultArray, 0, sizeof(long) * n);


    for (int i = 0; i < queries_rows; i++)
    {
        int a = queries[i][0];  //先取出a b k
        int b = queries[i][1];
        long k = (long)queries[i][2];

        // 不要直接記加總值，記「起伏幅度」就好。
        // 想成一條數線，放值進去把中間一段拉高，這時會形成一段往上爬跟一段往下走的差距
        //            ___________
        //           |           |
        //      +100 |           | -100
        // _________ |           |_________
        // a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 11   
        //
        // 如圖所示。不要在迴圈中計算「絕對值」，而是記所有欄位和周圍欄位的「相對落差」
        // 因為題目只需要求最大(山最高的地方)！
        // 所以只要記「山的走勢」，最後再從頭一路加到尾就可以得出所有欄位的最終結果！
        // 曠世名題！
        // 反過來說就算輸入的k會是負的這個解法也可以成立。

        int left = a - 1;
        int right = b - 1;
        resultArray[left] += k;
        if (right < n - 1)
        {
            resultArray[right + 1] -= k;
        }
    }
    
    long maximum = 0;
    
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += resultArray[i];
        if (sum > maximum)
        {
            maximum = sum;
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
