class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int sum) {
        // If the current node is NULL, return false as there's no path
        if (root == NULL)
            return false;

        // Add the current node's value to the sum
        sum += root->val;

        // If the current node is a leaf (no children)
        if (root->left == NULL && root->right == NULL) {
            // Check if the current path's sum equals targetSum
            if (sum == targetSum) {
                return true;
            }
            // If not, return false
            return false;
        }

        // Recursively check the left and right subtrees
        // Return true if any subtree has a valid path
        return solve(root->left, targetSum, sum) || solve(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;  // Variable to keep track of the current path's sum
        return solve(root, targetSum, sum);
    }
};