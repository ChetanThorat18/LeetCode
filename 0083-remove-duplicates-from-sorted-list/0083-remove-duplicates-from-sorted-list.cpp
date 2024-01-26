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
        // if LinkedList is empty or has only one node , return head
        if(head == NULL || head->next == NULL ){
            return head;
        }

        ListNode* temp = head;
        
        while(temp != NULL){
            // if last node , break
            if(temp->next == NULL){
                break;
            }
            // if current node has same value as that of its successor 
           if(temp->val == temp->next->val){
               temp->next = temp->next->next;
           }
           else{
               temp = temp = temp->next;
           }
        }

        return head;
    }
};