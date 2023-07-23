#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (34.42%)
 * Total Accepted:    106.2K
 * Total Submissions: 308.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct chessLocation
{
    int x;
    int y;
}
ChessLocation;

typedef struct solutionListNode
{
    ChessLocation *locations;
    struct solutionListNode *next;
}
SolutionListNode;

int rowLocation;
int columnLocation;
int slashLocationSum;
int slashLocationDiffRowMinusColumn;
int slashLocationDiffColumnMinusRow;

SolutionListNode *pushSolution(SolutionListNode *list, ChessLocation locations[], int locationLength)
{
    SolutionListNode *newNode = (SolutionListNode *)malloc(sizeof(SolutionListNode));
    ChessLocation *pushLocations = (ChessLocation *)malloc(sizeof(ChessLocation) * locationLength);

    memcpy(pushLocations, locations, sizeof(ChessLocation) * locationLength);
    newNode->locations = pushLocations;
    newNode->next = list;
    list = newNode;

    // printf("Push Solution:\n");
    // outputLocations(pushLocations, locationLength);
    // printf("\n");
    return list;
}


void outputLocations(ChessLocation locations[], int length)
{
    for (int i = 0; i < length; i++)
    {
        ChessLocation location = locations[i];
        printf("(%d, %d) ,", location.x, location.y);
    }
}


void outputSolutionCorrdinate(SolutionListNode *listNode, int locationLength)
{
    int currentSolutionIndex = 1;
    while (listNode != NULL)
    {
        printf("Solution %d:\n", currentSolutionIndex);
        outputLocations(listNode->locations, locationLength);
        printf("\n");
        currentSolutionIndex++;
        listNode = listNode->next;
    }
}


void solutionListToResult(char ***result, SolutionListNode *listNode, int length)
{
    int currentSoutionIndex = 0;
    while (listNode != NULL)
    {
        ChessLocation *locations = listNode->locations;
        char **currentSolutionStringArray = (char **)malloc(sizeof(char *) * length);
        for (int i = 0; i< length; i++)
        {
            char *rowString = (char *)malloc(sizeof(char) * (length + 1));
            memset(rowString, '.', sizeof(char) * length);
            rowString[length] = '\0';
            ChessLocation location = locations[i];
            rowString[location.y] = 'Q';
            currentSolutionStringArray[i] = rowString;
        }
        result[currentSoutionIndex] = currentSolutionStringArray;
        currentSoutionIndex++;
        listNode = listNode->next;
    }
}


void outputSolutionStringArray(char ***result, int n, int solutionCount)
{
    int i = 0;
    while (i < solutionCount)
    {
        printf("Solution %d:\n", i + 1);
        printf("[\n");
        char **solution = result[i];
        for (int j = 0; j < n; j++)
        {   
            char *outputResult = (char *)malloc(sizeof(char) * (n + 1));
            memcpy (outputResult, solution[j], sizeof(char) * (n + 1));
            outputResult[n] = '\0';
            printf("%s ,\n", outputResult);
        }
        printf("]\n");
        i++;
    }
}


int isLocationValid(ChessLocation locations)
{
    int row = locations.y;
    int column = locations.x;

    if (columnLocation & 1 << column)
    {
        return 0;
    }

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
                            int currentChessIndex,
                            ChessLocation locations[],
                            SolutionListNode **listHead
                            )                        
{
    if (currentChessIndex >= n)
    {
        *listHead = pushSolution((*listHead), locations, n);
        return 1; // 已經走到底，確定是解，直接回傳
    }

    int column = currentChessIndex;

    int solutionCount = 0;
    for (int row = 0; row < n; row++ )
    {
        ChessLocation location;
        location.x = column;
        location.y = row;
        if (isLocationValid(location))
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
            
            locations[currentChessIndex] = location;
            // printf("Chess Index:%d\n", currentChessIndex);
            // printf("Row:%d Column:%d\n", row, column);
            // printf("Set Location:[%d, %d]\n", locations.x, locations.y);
            
            solutionCount += getSolutionOfNQueens(n, currentChessIndex + 1, locations, listHead);

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

            location.x = -1;
            location.y = -1;
            locations[currentChessIndex] = location;
        }
    }
    
    return solutionCount;

}


char*** solveNQueens(int n, int* returnSize) 
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

    SolutionListNode *listHead = NULL;
    ChessLocation *locations = (ChessLocation *)malloc(sizeof(ChessLocation) * n);

    int solutionCount = getSolutionOfNQueens(n, 0, locations, &listHead);
    char ***solutionArray = (char ***)malloc(sizeof(char**) * solutionCount);
    solutionListToResult(solutionArray, listHead, n);
    *returnSize = solutionCount;

    // outputSolutionStringArray(solutionArray, n, solutionCount);
    outputSolutionCorrdinate(listHead, n);


    return solutionArray;

}   


int main(int argc, char **argv)
{
    int returnSize = 0;
    int n = 12;
    solveNQueens(n, &returnSize);

    return 0;
}

