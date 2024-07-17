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
    // Helper function to find the path from the root to a given target node.
    bool solve(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        // Base case: if the root is NULL, return false.
        if (root == NULL)
            return false;

        // Add the current node to the path.
        path.push_back(root);

        // If the current node is the target node, return true.
        if (root == target)
            return true;

        // Recursively check if the target node is in the left or right subtree.
        if ((root->left && solve(root->left, target, path)) || 
            (root->right && solve(root->right, target, path))) {
            return true;
        }

        // If the target node is not found in either subtree, remove the current node from the path and return false.
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Brute-Force

        // Vectors to store the paths from the root to nodes p and q.
        vector<TreeNode*> path_to_P;
        vector<TreeNode*> path_to_Q;

        // Find paths from the root to nodes p and q.
        if (!solve(root, p, path_to_P) || !solve(root, q, path_to_Q))
            return NULL; // If either p or q is not found in the tree, return NULL.

        // Initialize the LCA to NULL.
        TreeNode* LCA = NULL;

        // Compare the paths to find the lowest common ancestor.
        for (int i = 0; i < path_to_P.size() && i < path_to_Q.size(); ++i) {
            // The last common node in the paths is the LCA.
            if (path_to_P[i] == path_to_Q[i]) {
                LCA = path_to_P[i];
            } else {
                break; // Stop as soon as the paths diverge.
            }
        }

        return LCA; // Return the lowest common ancestor.
    }
};
