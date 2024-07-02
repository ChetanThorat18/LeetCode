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
    TreeNode* pruneTree(TreeNode* root) {
        // If the current node is NULL, return NULL as there is nothing to prune
        if(root == NULL)
            return NULL;

        // Recursively prune the left subtree
        root->left = pruneTree(root->left);
        // Recursively prune the right subtree
        root->right = pruneTree(root->right);

        // After pruning, if the current node is a 0 and both its left and right children are NULL,
        // it means this subtree does not contain a 1, so return NULL to remove this node
        if(root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;

        // If the current node or its subtrees contain a 1, keep the node
        return root;
    }
};