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
       // Base Case : If Empty list or a single node then cannot swap in pair 
       if(head == NULL || head->next == NULL)
        return head; 

        // Temporary pointer to store the second node in the pair
        ListNode* tmp = head->next;
        // Recursive call to swapPairs for the remaining list after the pair
        head->next = swapPairs(head->next->next);
        // Swapping the pair of nodes
        tmp->next = head;

        // Return the new head of the modified list
        return tmp;
    }
};
