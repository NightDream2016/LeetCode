#include "GlobalInclude.cpp"

class Solution {
public:

    int absMaxOfTwoIndicesVector(vector<int> A, vector<int> B)
    {
        if (A.size() == 1 && B.size() == 1)
        {
            return abs(A[0] - B[0]);
        }

        int aMax = A[A.size() - 1];
        int aMin = A[0];
        int bMax = B[B.size() - 1];
        int bMin = B[0];

        int absMax = INT_MIN;
        absMax = max(absMax, abs(aMax - bMax));
        absMax = max(absMax, abs(aMax - bMin));
        absMax = max(absMax, abs(aMin - bMin));
        absMax = max(absMax, abs(aMin - bMax));

        return absMax;
    }

    int solution(vector<int> &A) 
    {
        // write your code in C++14 (g++ 6.2.0)
        int numSize = A.size();
        
        unordered_map<int ,vector<int>> numsMap;
        for (int i = 0; i < numSize; i++)
        {
            vector<int> indexList = numsMap[A[i]];
            indexList.push_back(i);
            numsMap[A[i]] = indexList;
        }
        
        sort(A.begin(), A.end());
        
        int absMax = INT_MIN;
        for (int i = 1; i < numSize; i++)
        {
            int firstNum = A[i - 1];
            int secondNum = A[i];
            if (firstNum != secondNum)
            {
                vector<int> firstIndexList = numsMap[firstNum];
                vector<int> secondIndexList = numsMap[secondNum];
                absMax = max(absMax, absMaxOfTwoIndicesVector(firstIndexList, secondIndexList));
            }
        }
        
        return absMax;
        
    }
};


int main(int argc, char *argv[])
{
    vector<int> vectorInput = {1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 5, 1, 4, 7, 3, 3, 3, 3, 3, 5};

    Solution result;
    int results = result.solution(vectorInput);
    return 0;
}