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

    string solve(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& result) {
        // Base case: if the node is null, return "N" to represent null nodes
        if (root == NULL)
            return "N";

        // Serialize the current subtree into a string
        string s = to_string(root->val) + "," + solve(root->left, mp, result) + "," + solve(root->right, mp, result);

        // If the serialized subtree is found exactly once before, add the root to the result
        if (mp[s] == 1)
            result.push_back(root);

        // Increment the count of the serialized subtree in the map
        mp[s]++;

        // Return the serialized string of the subtree
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // Map to store the serialized subtree and its frequency
        unordered_map<string, int> mp;

        // Vector to store the roots of duplicate subtrees
        vector<TreeNode*> result;

        // Call the helper function to populate the result vector
        solve(root, mp, result);

        return result;
    }
};
