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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Approach: BFS (Breadth-First Search)

        // If both trees are empty, they are considered the same
        if (p == NULL && q == NULL)
            return true;

        // If one tree is empty and the other is not, they are not the same
        if (p == NULL || q == NULL)
            return false;

        // Use two queues to perform BFS on both trees simultaneously
        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;

        // Initialize the queues with the root nodes of both trees
        Q1.push(p);
        Q2.push(q);

        // Perform BFS until either queue is empty
        while (!Q1.empty() && !Q2.empty()) {
            // Get the front nodes from both queues
            TreeNode* node1 = Q1.front();
            Q1.pop();

            TreeNode* node2 = Q2.front();
            Q2.pop();

            // If the values of the nodes are not equal, the trees are not the same
            if (node1->val != node2->val)
                return false;

            // Check the left children of both nodes
            if (node1->left != NULL && node2->left != NULL) {
                Q1.push(node1->left);
                Q2.push(node2->left);
            }
            // If only one of the left children is NULL, the trees are not the same
            else if (node1->left != NULL || node2->left != NULL) {
                return false;
            }

            // Check the right children of both nodes
            if (node1->right != NULL && node2->right != NULL) {
                Q1.push(node1->right);
                Q2.push(node2->right);
            }
            // If only one of the right children is NULL, the trees are not the same
            else if (node1->right != NULL || node2->right != NULL) {
                return false;
            }
        }

        // If both queues are empty, the trees are structurally identical
        return true;
    }
};
