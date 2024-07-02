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
    // Helper function to check if a subtree contains at least one node with the value 1
    bool isOnePresent(TreeNode* node) {
        // If the node is null, return false as it does not contain a 1
        if (node == NULL)
            return false;

        // If the node's value is 1, return true
        if (node->val == 1)
            return true;

        // Recursively check if 1 is present in the left or right subtree
        return isOnePresent(node->left) || isOnePresent(node->right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        // If the root is null, return null as there is nothing to prune
        if (root == NULL)
            return NULL;

        // If the left subtree does not contain a 1, set the left child to null
        if (!isOnePresent(root->left))
            root->left = NULL;

        // If the right subtree does not contain a 1, set the right child to null
        if (!isOnePresent(root->right))
            root->right = NULL;

        // Recursively prune the left and right subtrees
        pruneTree(root->left);
        pruneTree(root->right);

        // After pruning, if the current node is a 0 and both its left and right children are null,
        // it means this subtree does not contain a 1, so return null to remove this node
        if (root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;

        // If the current node or its subtrees contain a 1, keep the node
        return root;
    }
};
