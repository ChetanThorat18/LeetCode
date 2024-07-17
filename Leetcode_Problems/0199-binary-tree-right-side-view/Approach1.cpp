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
    vector<int> rightSideView(TreeNode* root) {
        
        // If the root is null, return an empty list since there's no tree to view.
        if(root == NULL)
            return {};

        vector<int> result;

        // We use a queue to perform a level-order traversal (BFS).
        queue<TreeNode*> Q;

        // Start by pushing the root into the queue.
        Q.push(root);

        // Perform BFS until the queue is empty.
        while(!Q.empty()) {
            // Get the number of nodes at the current level.
            int n = Q.size();

            // Initialize a node to keep track of the last node(rightmost) in the current level.
            TreeNode* node = NULL;
            // Process all nodes at the current level.
            while(n--) {
                // Extract the front node from the queue.
                node = Q.front();
                Q.pop();

                // Push the left child of the current node to the queue, if it exists.
                if(node->left)
                    Q.push(node->left);

                // Push the right child of the current node to the queue, if it exists.
                if(node->right)
                    Q.push(node->right);
            }

            // The last processed node in the current level is the rightmost node.
            // Add its value to the result list.
            result.push_back(node->val);
        }

        // Return the list containing the right side view of the tree.
        return result;
    }
};
