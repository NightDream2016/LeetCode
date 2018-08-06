#include <time.h>
/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (47.90%)
 * Total Accepted:    79.7K
 * Total Submissions: 166.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
int rowLocation;
int slashLocationSum;
int slashLocationDiffRowMinusColumn;
int slashLocationDiffColumnMinusRow;

int isLocationValid(int row, int column)
{
    if (rowLocation & 1 << row)
    {
        return 0;
    }

    if (slashLocationSum & 1 << (row+column))
    {
        return 0;
    }

    if (row >= column)
    {
        if (slashLocationDiffRowMinusColumn & 1 << (row-column))
        {
            return 0;
        }
    }
    else
    {
        if (slashLocationDiffColumnMinusRow & 1 << (column-row))
        {
            return 0;
        }
    }
    
    return 1;
}

int getSolutionOfNQueens(   int n, 
                            int currentChessIndex
                            )                        
{
    if (currentChessIndex == n - 1)
    {
        // *listHead = pushSolution((*listHead), locations, n);
        return 1; // 已經走到底，確定是解，直接回傳
    }

    int column = currentChessIndex;
    int solutionCount = 0;
    for (int row = 0; row < n; row++ )
    {
        if (isLocationValid(row , column))
        {
            // 擺棋子
            rowLocation |= 1 << row;
            columnLocation |= 1 << column;
            slashLocationSum |= 1 << (row+column);

            if (row >= column)
            {
                slashLocationDiffRowMinusColumn |= 1 << (row-column);
            }
            else
            {
                slashLocationDiffColumnMinusRow |= 1 << (column-row);
            }

            // printf("Chess Index:%d\n", currentChessIndex);
            // printf("Row:%d Column:%d\n", row, column);
            // printf("Set Location:[%d, %d]\n", locations.x, locations.y);
            
            solutionCount += getSolutionOfNQueens(n, currentChessIndex + 1);

            // 走完所有子樹後要清空目前的變更 (棋子換下一個點擺)
            rowLocation &= ~(1 << row);
            columnLocation &=  ~(1 << column);
            slashLocationSum &= ~(1 << (row+column));

            if (row >= column)
            {
                slashLocationDiffRowMinusColumn &= ~(1 << (row - column));
            }
            else
            {
                slashLocationDiffColumnMinusRow &= ~(1 << (column - row));
            }
            
        }
    }
    
    return solutionCount;

}


int totalNQueens(int n) 
{
    // rowLocation = (int *)malloc(sizeof(int) * n);
    // columnLocation = (int *)malloc(sizeof(int) * n);
    // slashLocationSum = (int *)malloc(sizeof(int) * n * 2);
    // // Row-Column的方向寫成兩個Array，程式比較好寫:P (雖然開2n用位移的應該也可以啦)
    // slashLocationDiffRowMinusColumn = (int *)malloc(sizeof(int) * n);
    // slashLocationDiffColumnMinusRow = (int *)malloc(sizeof(int) * n);

    rowLocation = 0;
    columnLocation = 0;
    slashLocationSum = 0;
    slashLocationDiffColumnMinusRow = 0;
    slashLocationDiffRowMinusColumn = 0;

    int solutionCount = getSolutionOfNQueens(n, 0);
    // outputSolutionStringArray(solutionArray, n, solutionCount);
    // outputSolutionCorrdinate(listHead, n);


    return solutionCount;
}

int main(int argc, char **argv)
{
    int n = 13;
    int solutionCount = totalNQueens(n);

    printf("Solution Count Of %d Queen: %d", n , solutionCount);

    return 0;
}


