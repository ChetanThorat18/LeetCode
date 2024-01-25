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
    ListNode* swapNodes(ListNode* head, int k) {
        // Approach 2 : Single Pass

        ListNode* Node1 = head;
        ListNode* Node2 = head;

        // Find k^th Node from beginning
        ListNode* tmp = head;
        for(int i=1; i<k; i++){
            tmp = tmp->next;
        }
        Node1 = tmp;

        // tmp has already traversed k nodes from beginning
        // So , when tmp reaches last node , Node2 will be K^th node from end
        while(tmp->next){
            tmp = tmp->next;
            Node2 = Node2 ->next;
        }

        swap(Node1->val , Node2->val);

        return head;
    }
};