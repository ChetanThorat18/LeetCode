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
    // Helper function to collect leaf values from the tree
    void solve(TreeNode* root, vector<int>& Seq) {
        if (!root) {
            return;
        }

        // If the current node is a leaf node, add its value to the sequence
        if (root->left == NULL && root->right == NULL) {
            Seq.push_back(root->val);
        }

        // Recursively collect leaf values from left and right subtrees
        solve(root->left, Seq);
        solve(root->right, Seq);
    }

    // Function to check if two trees are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSeq1; // To store leaf sequence of tree1
        vector<int> leafSeq2; // To store leaf sequence of tree2

        // Collect leaf values from both trees
        solve(root1, leafSeq1);
        solve(root2, leafSeq2);

        // Compare the sizes of the leaf sequences
        if (leafSeq1.size() != leafSeq2.size()) {
            return false;
        }

        // Compare the leaf sequences element by element
        int i = 0;
        while (i < leafSeq1.size()) {
            if (leafSeq1[i] != leafSeq2[i]) {
                return false;
            }
            i++;
        }

        // If all checks pass, the trees are leaf-similar
        return true;
    }
};
