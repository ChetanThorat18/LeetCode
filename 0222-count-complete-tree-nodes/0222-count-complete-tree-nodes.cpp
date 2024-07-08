class Solution {
public:
    int getLeftHeight(TreeNode* root) {
        TreeNode* tmp = root; // Start from the root node
        int lh = 0; // Initialize the left height counter
        while (tmp) { // Traverse down the leftmost path
            lh++; // Increment the height counter for each level
            tmp = tmp->left; // Move to the left child
        }
        return lh; // Return the height of the leftmost path
    }

    int getRightHeight(TreeNode* root) {
        TreeNode* tmp = root; // Start from the root node
        int rh = 0; // Initialize the right height counter
        while (tmp) { // Traverse down the rightmost path
            rh++; // Increment the height counter for each level
            tmp = tmp->right; // Move to the right child
        }
        return rh; // Return the height of the rightmost path
    }
    
    int countNodes(TreeNode* root) {
        if (root == NULL) // Base case: if the root is NULL, the tree is empty
            return 0;

        int leftHeight = getLeftHeight(root); // Get the height of the leftmost path
        int rightHeight = getRightHeight(root); // Get the height of the rightmost path

        // If the heights are equal, the tree is a perfect binary tree
        if (leftHeight == rightHeight)
            return pow(2, leftHeight) - 1; // Number of nodes in a perfect binary tree

        // If the heights are not equal, recursively count nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
        // Add 1 for the current root node and the nodes in the left and right subtrees
    }
};

/*
    The no.  nodes in perfect binary tree of height h are ==> 2^h - 1

    eg-         1
               / \
              2   3
             /\   /\
            4  5  6 7

        Here height = 3 , no of nodes ==> 2^3 - 1 => 8-1 ==> 7

*/