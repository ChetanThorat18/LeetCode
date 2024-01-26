/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;

        // Slow-Fast pointer approach
        // if there is cycle in Linked List , slow and fast pointers are definitely gonna meet at some point

        ListNode* slow = head;
        ListNode* fast = head->next;

        while( slow != fast){
            if(fast == NULL || fast->next == NULL)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};