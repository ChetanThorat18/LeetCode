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
    ListNode*  reverseHalfLL(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        } 
        return prev;  // new Head
    }

    bool isPalindrome(ListNode* head) {
        // Base case
        if(head == NULL || head->next == NULL){
            return true;
        }
        // Approach : reversing the 2nd half and compare the two halves

        // Find middle using slow-fast pointers
        ListNode* slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        // if LL is of Odd length , skip middle node
        if(fast != NULL){
            slow = slow->next;
        }

        slow = reverseHalfLL(slow);  // slow points to reversed half LL
        fast = head;  // fast points to Original head

        while(slow){
            if(slow->val != fast->val )
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;

    }
};