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
    long totalSum; // Variable to store the total sum of all nodes in the tree
    long result;   // Variable to store the maximum product found
    const int MOD = 1e9 + 7; 

    // Helper function to calculate the total sum of the tree
    int calculateTotalSum(TreeNode* root) {
        if (!root) // Base case: if the node is null, return 0
            return 0;

        // Recursively calculate the sum of the left and right subtrees
        int leftSubtreeSum = calculateTotalSum(root->left);
        int rightSubtreeSum = calculateTotalSum(root->right);

        // Return the sum of the current subtree
        return root->val + leftSubtreeSum + rightSubtreeSum;
    }

    // Helper function to compute subtree sums and potential products
    // This function performs a post-order traversal to calculate the sum of each subtree, and at each node,
    // it calculates the potential product of splitting the tree at that node and updates the result with the maximum product found
    int solve(TreeNode* root) {

        if (!root) // Base case: if the node is null, return 0
            return 0;


        // Recursively calculate the sum of the left and right subtrees
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);


        // Calculate the sum of the current subtree
        long subTreeSum = root->val + leftSum + rightSum;

        // Calculate the remaining tree sum by subtracting the current subtree sum from the total sum
        long remainingTreeSum = totalSum - subTreeSum;

        // Update the result with the maximum product found so far
        result = max(result, subTreeSum * remainingTreeSum);

        
        // Return the sum of the current subtree
        return subTreeSum;
    }

    // Main function to find the maximum product of sums of two subtrees
    int maxProduct(TreeNode* root) {
        if (!root) // Base case: if the tree is empty, return 0
            return 0;

        // Calculate the total sum of the tree
        totalSum = calculateTotalSum(root);

        result = 0; // Initialize the result variable

        // Compute the maximum product by splitting the tree at each edge
        solve(root);

        // Return the result modulo 10^9 + 7
        return result % MOD;
    }
};