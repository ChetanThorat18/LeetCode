class Solution {
public:
    void reorderList(ListNode* head) {
        // stack to store the nodes of the linked list
        stack<ListNode*> stk;

        // Traverse the linked list and push each node onto the stack
        ListNode* tmp = head;
        while (tmp) {
            stk.push(tmp);
            tmp = tmp->next;
        }

        // We need only last n/2 nodes of the linked list
        int k = stk.size() / 2;

        // Initialize a pointer to traverse the linked list
        ListNode* curr = head;

        // Reorder the linked list by popping nodes from the stack and inserting them after each current node
        while (k--) {
            // Pop the top node from the stack
            ListNode* stkTop = stk.top();
            stk.pop();

            // Insert the popped node after the current node
            tmp = curr->next;
            curr->next = stkTop;
            stkTop->next = tmp;

            // Move the current pointer to the next node
            curr = tmp;
        }

        // Set the next pointer of the last node to NULL to terminate the reordered list
        curr->next = NULL;
    }
};
