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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head; 
        ListNode* slow = head;

        // move fast forward n times so that gap between slow and fast is of n nodes
        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        // if fast is already null, it means we have to delete head itself. So, just return next of head
        // eg.  1->2->3->4->5  n=5 means we have to delete head
        if(fast == NULL)
            return head->next;

        // when fast reaches last node , slow will be at previous of node to be deleted 
        while( fast->next != NULL ){
            slow = slow->next;
            fast = fast->next;
        }

        //skip the node to be deleted
        slow->next = slow->next->next;
        return head;
    }
};