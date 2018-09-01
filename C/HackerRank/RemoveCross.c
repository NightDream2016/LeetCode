#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;

    scanf("%d\n", &n);

    int **board = (int **)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        int *row = (int **)malloc(sizeof(int) * n);
        board[i] = row;
        
        for (int j = 0; j < n; j++)
        {
            char currentChar;
            scanf("%c", &currentChar);

            if(currentChar == 'O')
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = 1;
            }

            // 在輸入的時候就檢查有沒有十字型
            if (i >= 2 && i < n && j >= 1 && j < n)
            {
                if (board[i][j] && board[i - 1][j] && board[i - 1][j + 1] && board[i - 1][j - 1] && board[i - 2][j])
                {
                    board[i][j] = 0;
                    board[i - 1][j] = 0;
                    board[i - 1][j + 1] = 0;
                    board[i - 1][j - 1] = 0;
                    board[i - 2][j] = 0;
                }
            }
        }

        // 吃掉\n
        int newline;
        scanf("%c", &newline);
    }

    // 只要輸入完成以後最後的board有一個XX就是impossible
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] >= 1)
            {
                result = 1;
                break;
            }
        }
    }

    if (result)
    {
        printf("Impossible");
    }
    else
    {
        printf("Possible");
    }
    
    return 0;
}