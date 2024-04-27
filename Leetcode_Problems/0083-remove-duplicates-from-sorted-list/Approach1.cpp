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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        // Initialize a pointer to traverse the list
        ListNode* tmp1 = head;
        
        // Iterate through the list
        while(tmp1){
            // Check if the current node has a next node and if it's a duplicate
            if(tmp1->next && tmp1->val == tmp1->next->val){
                // Initialize a pointer to skip all duplicate nodes
                ListNode* tmp2 = tmp1->next;
                int currVal = tmp1->val;
                
                // Traverse through the list to skip all duplicate nodes
                while(tmp2 && tmp2->val == currVal){
                    tmp2 = tmp2->next;
                }

                // Update the next pointer of the current node to skip duplicates
                tmp1->next = tmp2;
            }

            // Move to the next node
            tmp1 = tmp1->next;
        }

        // Return the head of the updated list
        return head;
    }
};
