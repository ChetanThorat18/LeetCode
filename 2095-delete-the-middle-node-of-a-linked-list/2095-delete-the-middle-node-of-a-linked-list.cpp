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
    ListNode* deleteMiddle(ListNode* head) {
        // If there is only one node , it is the middle node
        if(head->next == NULL)
            return NULL;

        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while( fast && fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prevSlow->next = slow->next;
        delete(slow);

        return head;
    }
};