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
    bool isCompleteTree(TreeNode* root) {
        // Approach: BFS (Breadth-First Search)

        // Initialize a queue for level-order traversal
        queue<TreeNode*> Q;

        // Start by pushing the root node into the queue
        Q.push(root);

        // Flag to indicate if we have encountered any missing children
        bool missingChild = false;

        // Perform level-order traversal
        while (!Q.empty()) {
            // Get the front node from the queue
            TreeNode* currNode = Q.front();
            Q.pop();

            // If the current node is NULL, it means there is a missing child
            if (currNode == NULL) {
                missingChild = true;
            } else {
                // If we have encountered a missing child before and the current node is not NULL,
                // it means the tree is not complete
                if (missingChild == true) {
                    return false;
                }

                // Push the left and right children of the current node into the queue
                Q.push(currNode->left);
                Q.push(currNode->right);
            }
        }

        // If we successfully traverse the tree without issues, it is complete
        return true;
    }
};
