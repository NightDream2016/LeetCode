#include "GlobalInclude.cpp"

class Solution {
public:
    int solution(vector<int> &A) 
    {
        // write your code in C++14 (g++ 6.2.0)
        
        if (A.size() <= 2)
        {
            return A.size();
        }
        
        int currentSliceStart = 0;
        
        int currentValueOne = A[0];
        int currentValueOneLastIndex = 0;
        
        int currentValueTwo = INT_MIN;
        int currentValueTwoLastIndex = -1;
        
        int maxLength = 1;
        int localLength = 1;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] == currentValueOne)
            {
                currentValueOneLastIndex = i;
            }
            else
            {
                if (currentValueTwo == INT_MIN)
                {
                    currentValueTwo = A[i];
                    currentValueTwoLastIndex = i;
                }
                else
                {
                    if (A[i] == currentValueTwo)
                    {
                        currentValueTwoLastIndex = i;
                    }
                    else
                    {
                        maxLength = max(localLength, maxLength);

                        if (currentValueOneLastIndex < currentValueTwoLastIndex)
                        {
                            currentSliceStart = currentValueOneLastIndex + 1;
                            currentValueOne = A[i];
                            currentValueOneLastIndex = i;
                        }
                        else
                        {
                            currentSliceStart = currentValueTwoLastIndex + 1;
                            currentValueTwo = A[i];
                            currentValueTwoLastIndex = i;
                        }

                        localLength = i - currentSliceStart;
                    }
                }
            }

            localLength++;
        }

        maxLength = max(localLength, maxLength);
        
        return maxLength;
    }
};


int main(int argc, char *argv[])
{
    vector<int> vectorInput = {0, 5, 4, 4, 5, 12};

    Solution result;
    int results = result.solution(vectorInput);

    return 0;
}