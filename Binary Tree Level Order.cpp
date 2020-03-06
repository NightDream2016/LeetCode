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