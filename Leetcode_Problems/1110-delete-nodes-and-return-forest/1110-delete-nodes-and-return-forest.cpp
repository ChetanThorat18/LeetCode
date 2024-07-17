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
    // Vector to store the roots of the trees in the remaining forest
    vector<TreeNode*> result;

    // Helper function to delete nodes and form the forest
    TreeNode* solve(TreeNode* root, unordered_set<int>& toDeleteSet) {
        if (root == NULL)
            return NULL;

        // Recursively solve for left and right subtrees
        root->left = solve(root->left, toDeleteSet);
        root->right = solve(root->right, toDeleteSet);

        // If the current node is in the toDeleteSet
        if (toDeleteSet.find(root->val) != toDeleteSet.end()) {
            // If the left child exists, push it to result as it will become a new root
            if (root->left != NULL) {
                result.push_back(root->left);
            }
            // If the right child exists, push it to result as it will become a new root
            if (root->right != NULL) {
                result.push_back(root->right);
            }
            // Return NULL to remove the current node
            return NULL;
        } else {
            // If the current node is not in the toDeleteSet, return the node itself
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Create a set from the to_delete vector for quick lookup
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());

        // Solve the tree starting from the root
        solve(root, toDeleteSet);

        // If the root is not to be deleted, add it to the result
        if (toDeleteSet.find(root->val) == toDeleteSet.end()) {
            result.push_back(root);
        }

        // Return the result vector containing the roots of the remaining forest
        return result;
    }
};