int solution(int A, int B) 
{
    // write your code in C99 (gcc 6.2.0)
    if (A % B == 0)
    {
        return 1;
    }
    
    int maximumValue = -1;
    
    int previousValue = 1;

    for (int i = 0; i < B; i++)
    {
        int currentValue = (int)(((unsigned long)A * (unsigned long)previousValue) % (unsigned long)B);
        // printf("i:%d currentValue:%d maximumValue:%d previousValue:%d\n", i ,currentValue, maximumValue, previousValue);
        if (currentValue > maximumValue)
        {
            maximumValue = currentValue;
        }
        else
        {
            if (currentValue == maximumValue)
            {
                break;
            }
        }
        
        if (currentValue == previousValue)
        {
            break;
        }
        
        previousValue = currentValue;
        
    }

    
    return maximumValue;
}



int main()
{


    int result = solution(199999999, 199999994);


    return 0;

    
}