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
    ListNode* reverseList(ListNode* head) {
        // Brute Force
        // Traverse whole linked list and put values in stack( O(n))
        //Again traverse from head and pop from stack and put in linked list (O(n))
        // Time Complexity (O(2n))
        // Space Complexity (O(n))

        ListNode* tmp = head;
        stack<int>stk;

        while(tmp!= NULL){
            stk.push(tmp->val);
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp != NULL){
            tmp->val = stk.top();
            stk.pop();
            tmp = tmp->next;
        }
        return head;
        
    }
};
