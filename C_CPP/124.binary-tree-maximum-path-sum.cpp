#include "GlobalInclude.cpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

    vector<TreeNode *> vectorOfTree(TreeNode *root)
    {
        vector<TreeNode *> result;
        if (root == NULL)
        {
            result.push_back(root);
            return result;
        }

        queue <TreeNode*> nodeQueue;
        int currentDepthNodeCount = 1;
        int nextDepthNodeCount = 1;
        int currentDepth = 0;
        nodeQueue.push(root);
        while (nodeQueue.empty() == false)
        {
            while (currentDepthNodeCount != 0)
            {
                TreeNode *rootNode = nodeQueue.front();
                nodeQueue.pop();
                if (rootNode -> left != NULL)
                {
                    nodeQueue.push(rootNode -> left);
                    nextDepthNodeCount += 1;
                }

                if (rootNode -> right != NULL)
                {
                    nodeQueue.push(rootNode -> right);
                    nextDepthNodeCount += 1;
                }
                currentDepthNodeCount--;
            }
            currentDepthNodeCount = nextDepthNodeCount;
            currentDepth += 1;
        }

        return currentDepth;
    }

    int maxPathSum(TreeNode* root) 
    {
        int treeDepth = depthOfTree(root);

        int dpTable[nodeCount][nodeCount];    

        

    }
};
// @lc code=end

