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

    // Helper function to check if two trees are identical
    bool solve(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, they are considered identical
        if (root1 == NULL && root2 == NULL)
            return true;

        // If one of the nodes is null while the other is not, they are not identical
        if (root1 == NULL || root2 == NULL)
            return false;

        // Check if the current nodes' values are equal and recursively check the left and right subtrees
        return (root1->val == root2->val) && 
               solve(root1->left, root2->left) && 
               solve(root1->right, root2->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};
