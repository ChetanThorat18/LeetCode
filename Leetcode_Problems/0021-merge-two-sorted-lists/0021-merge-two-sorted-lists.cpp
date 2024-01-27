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
   
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify the merging process
        ListNode* dummy = new ListNode();
        // Tail pointer to track the end of the merged list
        ListNode* tail = dummy;

        // Continue merging until either l1 or l2 becomes null
        while (l1 && l2) {
            if (l1->val < l2->val) {
                // If the value in l1 is smaller, add it to the merged list
                tail->next = l1;
                l1 = l1->next;
            } else {
                // If the value in l2 is smaller or equal, add it to the merged list
                tail->next = l2;
                l2 = l2->next;
            }
            // Move the tail pointer to the last node in the merged list
            tail = tail->next;
        }

        // If there are remaining nodes in l1, append them to the merged list
        if (l1) {
            tail->next = l1;
        }

        // If there are remaining nodes in l2, append them to the merged list
        if (l2) {
            tail->next = l2;
        }

        // Return the merged list starting from the next of the dummy node
        return dummy->next;
    }
};
