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
    ListNode* swapPairs(ListNode* head) {
       // Iterative Approach 

       // Base case: Empty list or a single node
        if (!head || !head->next) {
            return head;
        } 

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;
        while(current && current->next){
            // Nodes to be swapped
            ListNode* first = current ;
            ListNode* second = current->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            prev = first;
            current = first->next;

        }

        return dummy->next;
    }
};