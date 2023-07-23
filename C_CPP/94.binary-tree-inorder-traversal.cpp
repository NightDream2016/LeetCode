/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (60.92%)
 * Likes:    2530
 * Dislikes: 106
 * Total Accepted:    638.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> solution;
        
        if (root == NULL)
        {
            return solution ;
        }
    
        vector<int> leftSolution = inorderTraversal(root -> left);
        
        for (int element : leftSolution)
        {
            solution.push_back(element);
        }
        
        solution.push_back(root -> val);
        
        vector<int> rightSolution = inorderTraversal(root -> right);
        
        for (int element : rightSolution)
        {
            solution.push_back(element);
        }
        
        return solution;
        
    }
};
// @lc code=end

