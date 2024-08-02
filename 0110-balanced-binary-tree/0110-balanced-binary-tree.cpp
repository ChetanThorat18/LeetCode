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
    int solve(TreeNode* root){
        if (!root)
            return 0;  // Base case: The height of an empty tree is 0

        // Recursively get the height of the left subtree
        int leftHeight = solve(root->left);
        if (leftHeight == -1)
            return -1;  // If the left subtree is not balanced, propagate the unbalanced state

        // Recursively get the height of the right subtree
        int rightHeight = solve(root->right);
        if (rightHeight == -1)
            return -1;  // If the right subtree is not balanced, propagate the unbalanced state

        // Check if the current node is balanced by comparing the heights of its left and right subtrees
        if (abs(leftHeight - rightHeight) > 1)
            return -1;  // If the current node is not balanced, propagate the unbalanced state

        // Return the height of the current tree, which is 1 plus the maximum height of its subtrees
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;  
    }
};