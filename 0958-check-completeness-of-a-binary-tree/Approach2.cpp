/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to count the total number of nodes in the tree
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        // Recursively count nodes in left and right subtrees and add 1 for the root node
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // DFS function to check if the tree is complete
    bool dfs(TreeNode* root, int idx, int totalNodes) {
        if (root == NULL)
            return true;
        
        // If the current node's index is greater than the total number of nodes, the tree is not complete
        if (idx > totalNodes)
            return false;
        
        // Recursively check the left and right subtrees
        return dfs(root->left, 2 * idx, totalNodes) && dfs(root->right, 2 * idx + 1, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        // Approach: DFS (Depth-First Search)
        
        // Calculate the total number of nodes in the tree
        int totalNodes = countNodes(root);

        // Start DFS from the root with index 1
        int idx = 1;
        return dfs(root, idx, totalNodes);
    }
};
