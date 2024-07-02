/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& result, int currLevel) {
        // Base case: if the node is null, simply return.
        if (root == NULL)
            return;

        // If this is the first node we're visiting at this level,
        // it means it's the rightmost node of this level from the perspective of the current recursion state.
        if (currLevel == result.size())
            result.push_back(root->val);


        // Recursively visit the right subtree first, ensuring we capture the rightmost nodes first
        solve(root->right, result, currLevel + 1);

        // Recursively visit the left subtree.
        solve(root->left, result, currLevel + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<int> result;

        // Start the recursive traversal from the root at level 0.
        solve(root, result, 0);

        return result;
    }
};