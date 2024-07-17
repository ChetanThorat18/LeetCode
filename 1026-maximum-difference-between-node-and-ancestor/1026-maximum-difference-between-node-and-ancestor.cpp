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
    // Helper function to calculate the maximum ancestor difference
    int solve(TreeNode* root, int minVal, int maxVal) {
        // Base case: if the current node is NULL, return the difference between max and min values
        if (root == NULL)
            return abs(minVal - maxVal);

        // Update the min and max values
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        // Recursive call for left and right children
        int left = solve(root->left, minVal, maxVal);
        int right = solve(root->right, minVal, maxVal);

        // Return the maximum of the values obtained from left and right subtrees
        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        // Initialize the recursion with the root's value as both min and max values
        return solve(root, root->val, root->val);
    }
};