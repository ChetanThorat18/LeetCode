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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0)
            return head;

        // Count length
        ListNode* tmp = head;
        int length = 1;
        while(tmp->next){
            length++;
            tmp = tmp->next;
        }

        // last node->next = head
        tmp->next = head;

        k = k % length; // handles case of k > length

        // now traverse till (n-k)th node from last
        tmp = head;
        for(int i=1 ; i < length-k; i++){
            tmp = tmp->next;
        }
        // break list here and update head
        head = tmp->next; 
        tmp->next = NULL;

        return head;

        /*
            eg -  1->2->3->4->5  and k=2 
            STEP 1 :-   length = 5 , 1->2->3->4->5->1(head)

            STEP 2:-     1->2->3-> NULL      4->5->1
        */
    }
};