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
        // Itrative approach (O(n))
        ListNode* current = head;
        ListNode* prev = NULL;

        while(current != NULL){
            ListNode* Next = current->next;
            current->next = prev;
            prev = current;
            current = Next; 
        }

        return prev;
    }
};