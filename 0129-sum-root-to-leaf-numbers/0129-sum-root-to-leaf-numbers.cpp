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
    int solve(TreeNode* root, int curr) {
        // Base case: if the node is null, return 0
        if (!root)
            return 0;

        // Update the current number by appending the current node's value
        curr = curr * 10 + root->val;

        // If the current node is a leaf node, return the current number
        if (root->left == NULL && root->right == NULL)
            return curr;

        // Recursively calculate the sum for the left and right subtrees
        int left = solve(root->left, curr);
        int right = solve(root->right, curr);

        // Return the sum of the left and right subtree sums
        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        // Start the recursive calculation with the initial current number as 0
        return solve(root, 0);
    }
};