#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace Output
{
    void outputVector(vector<int>& vector)
    {
        cout << "[";
        for (auto &integer : vector)
        {
            cout << " " << integer << " ";
        }
        cout << "]," << endl;
    }

    void outputVector(vector<string>& vector)
    {
        cout << "[";
        for (auto &element : vector)
        {
            cout << " " << element << " ";
        }
        cout << "]," << endl;
    }

    void outputVectorWithLength(vector<int>& vector, int length)
    {
        cout << "[";
        for (int i = 0; i < length; i++)
        {
            cout << " " << vector[i] << " ";
        }
        cout << "]," << endl;
    }

    void outputPairVector(vector<pair<int, int>> pairs)
    {
        cout << "[" << endl;
        for (pair<int, int>& element : pairs)
        {
            cout << "{" << element.first << "," << element.second << "}, ";
        }
        cout << "]" << endl;
    }

    void output2DVector(vector<vector<int>> vectors)
    {
        cout << "[" << endl;
        for (auto &vector : vectors)
        {
            outputVector(vector);
        }
        cout << "]" << endl;
    }

    void output2DArray(int **array, int n)
    {
        cout << "[" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << array[i][j] << ", ";
            }
            cout << endl;
        }
        cout << "]" << endl;
    }

    void outputTab(int tabCount)
    {
        for (int i = 0; i < tabCount; i++)
        {
            cout << "   ";
        }
    }
};




