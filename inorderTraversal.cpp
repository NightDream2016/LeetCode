#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main(int argc, char *argv[])
{
    Solution solution;
    return 0;
}