/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // Approach: BFS (Breadth-First Search)
        // We use a queue to traverse the tree level by level

        if (root == NULL)
            return 0; // If the tree is empty, the minimum depth is 0

        queue<TreeNode*> Q;
        Q.push(root); // Start with the root node

        int depth = 1; // Initial depth is 1 (root level)

        while (!Q.empty()) {
            int n = Q.size(); // Number of nodes at the current level

            while (n--) {
                TreeNode* tmp = Q.front(); // Get the front node from the queue
                Q.pop();

                // Check if the current node is a leaf node (no children)
                if (tmp->left == NULL && tmp->right == NULL)
                    return depth; // Return the current depth if a leaf node is found

                // Add the left child to the queue if it exists
                if (tmp->left != NULL)
                    Q.push(tmp->left);

                // Add the right child to the queue if it exists
                if (tmp->right != NULL)
                    Q.push(tmp->right);
            }

            depth++; // Increment the depth after processing all nodes at the current level
        }

        return -1; 
    }
};
