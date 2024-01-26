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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;

        // Find middle of LL using slow , fast pointers
        ListNode* slow = head , *fast = head->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }


        // reverse the second half of list i.e. from slow->next
        // 1->2->3->4->5->6    to     1->2->3->   6->5->4->
        ListNode* second = reverseLL(slow->next);
        slow->next = NULL;

        // Link one,one node from both both halfs 
        // eg-  1->6->2->5->3->4

         ListNode* first = head;

         while(first && second){
             ListNode* tmp1 = first->next;
             ListNode* tmp2 = second->next;

             first->next = second;
             second->next = tmp1;

             first = tmp1;
             second = tmp2;
         }
        
    }
};