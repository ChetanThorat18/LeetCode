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
    // This variable will hold the maximum difference found
    int result;

    // Helper function to compute the difference between an ancestor node and its descendant nodes
    void maxDiffUtil(TreeNode* root, TreeNode* child) {
        // Base case: if either node is null, return
        if (!root || !child)
            return;

        // Update the result with the maximum difference found so far
        result = max(result, abs(root->val - child->val));

        // Recur for the left and right child nodes
        maxDiffUtil(root, child->left);
        maxDiffUtil(root, child->right);
    }

    // Function to traverse the tree and find maximum differences for each node's descendants
    void findMaxDiff(TreeNode* root) {
        // Base case: if the root is null, return
        if (!root)
            return;

        // Calculate the difference for the left and right child nodes
        maxDiffUtil(root, root->left);
        maxDiffUtil(root, root->right);
        
        // Recur for the left and right subtrees
        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }

    // Main function to find the maximum ancestor-descendant difference in the tree
    int maxAncestorDiff(TreeNode* root) {
        result = -1;

        // Start the recursive traversal to find the maximum difference
        findMaxDiff(root);

        // Return the final result
        return result;
    }
};
