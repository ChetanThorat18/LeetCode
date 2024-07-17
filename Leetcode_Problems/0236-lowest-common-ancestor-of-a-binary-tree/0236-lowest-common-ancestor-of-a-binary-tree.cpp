/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is NULL, return NULL.
        if (root == NULL)
            return NULL;

        // If either p or q is the root, then root is the LCA.
        if (root == p || root == q)
            return root;

        // Recursively find the LCA in the left subtree.
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        // Recursively find the LCA in the right subtree.
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        // If both leftNode and rightNode are not NULL, then p and q are found in different subtrees.
        // Hence, the current root is their LCA.
        if (leftNode != NULL && rightNode != NULL)
            return root;

        // If one of the nodes is NULL, return the non-NULL node.
        // This means either the LCA was found in one of the subtrees, or both p and q are in one subtree.
        return leftNode == NULL ? rightNode : leftNode;
    }
};