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
    // Helper function to check if two trees are mirror images of each other
    bool solve(TreeNode* left, TreeNode* right) {
        // If both nodes are null, they are symmetric (base case)
        if (left == NULL && right == NULL)
            return true;

        // If only one of the nodes is null, they are not symmetric
        if (left == NULL || right == NULL)
            return false;

        // Check if the current nodes' values are equal and recursively check the subtrees
        // The left subtree of the left node should be a mirror of the right subtree of the right node
        // The right subtree of the left node should be a mirror of the left subtree of the right node
        return (left->val == right->val) &&
               solve(left->left, right->right) &&
               solve(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (root == NULL)
            return true;

        // Use the helper function to check if the left and right subtrees are mirrors of each other
        return solve(root->left, root->right);
    }
};