/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> solutions;

        if (root == NULL)
        {
            return solutions;
        }
        
        queue <Node *>nodeQueue;    
        int previousLevelNodeCount = 1;
        
        nodeQueue.push(root);
        while (nodeQueue.empty() == false)
        {
            vector<int> result;
            int currentLevelNodeCount = 0;
            while (previousLevelNodeCount > 0)
            {
                Node *root = nodeQueue.front();

                for (Node *child : root->children)
                {
                    if (child != NULL)
                    {
                        nodeQueue.push(child);
                        currentLevelNodeCount++;
                    }   
                }
                
                result.push_back(root -> val);
                previousLevelNodeCount--;
                nodeQueue.pop();
            }
            
            solutions.push(result);
            previousLevelNodeCount = currentLevelNodeCount;
        }

        return solutions;
    }
};