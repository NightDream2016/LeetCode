#include "GlobalInclude.h"

using namespace std;
using namespace Output;

namespace Global
{
    class List
    {
        struct ListNode
        {
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
                currentRoot->next = new ListNode(val);
                currentRoot = currentRoot->next;
            }

            return root->next;
        };
    };

    class Tree
    {
        struct TreeNode
        {
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
                    currentRoot->left = currentNode;
                }
                else
                {
                    currentRoot->right = currentNode;
                    currentRoot = treeQueue.front();
                    treeQueue.pop();
                }

                treeQueue.push(currentNode);
            }

            return root;
        }
    }
}; // namespace Global