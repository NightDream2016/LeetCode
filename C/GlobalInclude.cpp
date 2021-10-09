#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include "math.h"
#include "memory.h"
#include "Output.cpp"

using namespace std;
using namespace Output;

#pragma region List

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *listFromVector(vector<int> listVal)
{
    ListNode *root = new ListNode(-1);
    ListNode *currentRoot = root;
    for (int val : listVal)
    {
        currentRoot -> next = new ListNode(val);
        currentRoot = currentRoot -> next;
    }

    return root -> next;
}

#pragma endregion

#pragma region Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *treeFromVector(vector<int> listVal)
{
    TreeNode *root = new TreeNode(listVal[0]);
    TreeNode *currentRoot = root;
    queue<TreeNode *> treeQueue;

    for (int i = 1; i < listVal.size(); i++)
    {
        TreeNode *currentNode = new TreeNode(listVal[i]);
        
        if (i % 2)
        {
            currentRoot -> left = currentNode;
        }         
        else
        {
            currentRoot -> right = currentNode;
            currentRoot = treeQueue.front();
            treeQueue.pop();
        }

        treeQueue.push(currentNode);
    }

    return root;
}

#pragma endregion
