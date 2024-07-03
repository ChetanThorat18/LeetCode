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
    vector<vector<int>> result;  

    void solve(TreeNode* root, int targetSum, int sum, vector<int>tmp) {
        // Base case: If the current node is NULL, return
        if (root == NULL)
            return;

        // Add the current node's value to the sum
        sum += root->val;
        // Add the current node's value to the current path
        tmp.push_back(root->val);

        // If the current node is a leaf (no children)
        if (root->left == NULL && root->right == NULL) {
            // Check if the current path's sum equals the targetSum
            if (sum == targetSum) {
                // If so, add the current path to the result
                result.push_back(tmp);
            }
            return;
        }

        // Recursively call the helper function for the left and right children
        solve(root->left, targetSum, sum, tmp);
        solve(root->right, targetSum, sum, tmp);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;  // Temporary vector to store the current path
        int sum = 0;  // Variable to keep track of the current path's sum

        // Call the helper function with the root node
        solve(root, targetSum, sum, tmp);

        // Return the result containing all valid paths
        return result;
    }
};
