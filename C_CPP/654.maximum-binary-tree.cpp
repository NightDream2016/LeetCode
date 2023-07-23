#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        stack <TreeNode*> minStack;
        TreeNode *root = NULL;
        for (int num : nums)
        {
            while (minStack.empty() == false)
            {
                TreeNode *previousRoot = minStack.top();
                if (num < previousRoot -> val)
                {
                    break;
                }
                minStack.pop();
            }
            
            TreeNode *newNode = new TreeNode(num);

            if (minStack.empty())
            {
                newNode -> left = root;
                root = newNode;
            }    
            else
            {
                TreeNode *previousRoot = minStack.top();
                newNode -> left = previousRoot -> right;
                previousRoot -> right = newNode;
                
            }

            minStack.push(newNode);
        }

        return root;
    }
};
// @lc code=end

int main(int argc, char *argv[])
{
    vector<int> vectorInput = {3,2,1,6,0,5};
    Solution solution;
    TreeNode *result = solution.constructMaximumBinaryTree(vectorInput);
    return 0;
}