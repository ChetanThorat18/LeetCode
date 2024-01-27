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
    int pairSum(ListNode* head) {
       // Approach : Without using extra space

       // Step 1 : Find Middle node

       ListNode* slow = head;
       ListNode* fast = head;

       while(fast && fast->next){
           slow = slow->next;
           fast = fast->next->next;
       } 

       ListNode* mid = slow;

       // Step 2 : Reverse second half

       ListNode* prev = NULL;
       ListNode* nextNode = NULL;
       while(mid){
           nextNode = mid->next;
           mid->next = prev;
           prev = mid;
           mid = nextNode; 
       } 

        // Step 3 : Calculate maxTwinSum 
       ListNode* second = prev;  // New head of reversed second half
       ListNode* first = head;
       int result = INT_MIN;
       while(second){
           result = max(result , first->val + second->val);
           first = first->next;
           second = second->next;
       }

       return result;
    }
};