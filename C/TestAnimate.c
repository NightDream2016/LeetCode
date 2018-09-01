#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>


typedef struct point
{
    int x;
    int y;
}
Point;

void printLocation(Point p, int width , int height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j <height; j++)
        {
            if (i == p.x && j == p.y)
            {
                printf("O");
            }
            else
            {
                if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
                {
                    printf("X");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
    Point p;
    p.x = 0;
    p.y = 0;

    int width = 30;
    int height = 30;
    hidecursor();
    while (1)
    {
        printLocation(p, width ,height);
        p.x = (p.x + 1) % width;
        p.y = (p.y + 1) % height;
        system("cls");
    }
}