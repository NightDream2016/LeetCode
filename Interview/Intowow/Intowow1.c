#include <stdlib.h>
#include <stdio.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

typedef struct point
{
    int x;
    int y;
}
Point;

Point createPoint(int x, int y)
{
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

int pointDistanceSquare(Point A, Point B)
{
    int xDiff = B.x - A.x;
    int yDiff = B.y - A.y;
    
    return xDiff*xDiff + yDiff*yDiff;
}

int solution(int A, int B, int C, int D) 
{
    // write your code in C99 (gcc 6.2.0)

    int result[12] = {0};

    result[0]  = pointDistanceSquare(createPoint(A, B), createPoint(C, D));
    result[1]  = pointDistanceSquare(createPoint(A, B), createPoint(D, C));
    result[2]  = pointDistanceSquare(createPoint(A, C), createPoint(B, D));
    result[3]  = pointDistanceSquare(createPoint(A, C), createPoint(D, B));
    result[4]  = pointDistanceSquare(createPoint(A, D), createPoint(B, C));
    result[5]  = pointDistanceSquare(createPoint(A, D), createPoint(C, B));
    result[6]  = pointDistanceSquare(createPoint(B, A), createPoint(C, D));
    result[7]  = pointDistanceSquare(createPoint(B, A), createPoint(D, C));
    result[8]  = pointDistanceSquare(createPoint(C, A), createPoint(B, D));
    result[9]  = pointDistanceSquare(createPoint(C, A), createPoint(D, B));
    result[10] = pointDistanceSquare(createPoint(D, A), createPoint(B, C));
    result[11] = pointDistanceSquare(createPoint(D, A), createPoint(C, B));

    int maximumResult = 0;
    for (int i = 0; i < 12; i++)
    {
        if (maximumResult < result[i])
        {
            maximumResult = result[i];
        }
    }
    
    return maximumResult;
}


int main()
{
    int result1 = solution(1,1,2,3);
    int result2 = solution(2,4,2,4);
    int result3 = solution(-5000,5000,1,1);

    return 0;

}