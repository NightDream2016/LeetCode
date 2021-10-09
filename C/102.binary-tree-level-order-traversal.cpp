/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.29%)
 * Likes:    2356
 * Dislikes: 62
 * Total Accepted:    526.8K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> solutions;

        if (root == NULL)
        {
            return solutions;
        }
        
        queue <TreeNode *>nodeQueue;    
        int previousLevelNodeCount = 1;
        
        nodeQueue.push(root);
        while (nodeQueue.empty() == false)
        {
            vector<int> result;
            int currentLevelNodeCount = 0;
            while (previousLevelNodeCount > 0)
            {
                TreeNode *root = nodeQueue.front();
                if (root -> left != NULL)
                {
                    nodeQueue.push(root -> left);
                    currentLevelNodeCount++;
                }
                
                if (root -> right != NULL)
                {
                    nodeQueue.push(root -> right);
                    currentLevelNodeCount++;    
                }

                result.push_back(root -> val);
                previousLevelNodeCount--;
                nodeQueue.pop();
            }
            
            solutions.push_back(result);
            previousLevelNodeCount = currentLevelNodeCount;
        }
        
        return solutions;
    }
};
// @lc code=end

