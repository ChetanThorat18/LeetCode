/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Initialize two separate linked lists for nodes before and after x
        ListNode* beforeHead = NULL;
        ListNode* afterHead = NULL;

       
        ListNode* temp = head;
        ListNode* node1 = new ListNode();  // Pointer for nodes less than x
        ListNode* node2 = new ListNode();  // Pointer for nodes greater than or equal to x

        // Iterate through the original linked list
        while (temp != NULL) {
            if (temp->val < x) {
                // Add nodes less than x to the 'before' partition
                if (beforeHead == NULL) {
                    node1 = new ListNode(temp->val);
                    beforeHead = node1;
                } else {
                    node1->next = new ListNode(temp->val);
                    node1 = node1->next;
                }
            } else {
                // Add nodes greater than or equal to x to the 'after' partition
                if (afterHead == NULL) {
                    node2 = new ListNode(temp->val);
                    afterHead = node2;
                } else {
                    node2->next = new ListNode(temp->val);
                    node2 = node2->next;
                }
            }
            temp = temp->next;  // Move to the next node in the original list
        }

        // Connect the 'before' and 'after' partitions
        if (beforeHead == NULL) {
            // If 'before' is empty, return 'after' as the result
            beforeHead = afterHead;
        } else {
            // Otherwise, connect 'before' and 'after'
            node1->next = afterHead;
        }

        return beforeHead;
    }
};
