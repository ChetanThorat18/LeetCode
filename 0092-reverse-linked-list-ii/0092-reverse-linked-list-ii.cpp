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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0,head);

        ListNode* leftPrev = dummy;
        ListNode* curr = head;
        // Move to the starting position (left)
        // leftPrev => previous node of left position
        for(int count = 1 ; count < left; count++){
            leftPrev = curr ;
            curr = curr->next;
        }

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        // Reverse the sublist from left to right
        for(int count = 1 ; count <= right-left+1 ; count++){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        } 

        // prev => new Head of reversed sublist
        // Connect the reversed sublist back to the original list
        leftPrev->next->next = curr;
        leftPrev->next = prev;

        return dummy->next;
    }
};