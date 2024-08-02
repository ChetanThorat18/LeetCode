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
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0; // Base case: if the node is NULL, return 0 (no depth)

        // If one child is NULL, we should not consider it for the minimum depth
        if (root->left == NULL) {
            return 1 + solve(root->right);
        }
        if (root->right == NULL) {
            return 1 + solve(root->left);
        }

        // If both children are present, find the minimum depth between the two
        return 1 + min(solve(root->left), solve(root->right));
    }

    int minDepth(TreeNode* root) {
        // DFS Approach
        return solve(root); // Start the recursion from the root
    }
};