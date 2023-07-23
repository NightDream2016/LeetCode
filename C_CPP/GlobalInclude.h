#include "Output.cpp"
#include "memory.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace Output;

namespace Global
{
    class Tree
    {
    public:
        struct TreeNode
        {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };
        TreeNode *treeFromVector(vector<int> listVal);
    };

    class List
    {
    public:
        struct ListNode
        {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };
        ListNode *listFromVector(vector<int> listVal);
    };

} // namespace Global
