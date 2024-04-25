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
    // Function to calculate the length of the linked list
    int getLengthOfList(ListNode* tmp){
        int cnt = 0;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Approach : Two pass solution

        // Calculate the length of the linked list
        int Len = getLengthOfList(head);

        // If n is equal to the length of the list, remove the head node
        if( n == Len){
            ListNode* tmp = head->next;
            delete(head);
            return tmp;
        }

        // Traverse to the node just before the one to remove
        ListNode* tmp = head;
        for(int i=1; i< Len - n; i++){
            tmp = tmp->next;
        }

        // Remove the nth node from the end by adjusting pointers
        ListNode* delNode = tmp->next;
        tmp->next = tmp->next->next;
        delete(delNode);

         return head;
    }
};
