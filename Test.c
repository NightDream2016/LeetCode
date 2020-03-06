#include "stdlib.h"
#include "math.h"
#include "stdio.h"

int isInputInteger(char input[])
{
  int result = 1;
  int dashCount = 0;
  for (int i = 0; i < 20; i++)
  {
    printf("%d", input[i]);

    if (input[i] == '\0')
    {
        break;
    }
    if (!(input[i] >= 48 && input[i] <= 57))
    {
       if (input[i] == '-' && dashCount == 0)
       {
         dashCount++;
         continue;
       }
       else
       {
         result = 0;
         break;
       }
    }
  }
  
  return result;
}

int main() {
  
  char input[20];
  unsigned long result = 0;
  while(scanf("%s\n", input)!= EOF)
  {
    printf("%s\n", input);
    if (isInputInteger(input))
    {
      unsigned long currentAbs = abs(atoi(input));
      result += currentAbs;
    }
  }
  
  printf("%ld", result);
  
  return 0;
}