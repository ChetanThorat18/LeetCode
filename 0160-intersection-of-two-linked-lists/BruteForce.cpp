/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute Force
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;

        if(tmp1 == NULL || tmp2 == NULL)
            return NULL;
        
        unordered_set<ListNode*>NodeSet;
        // Traverse the first linked list and store nodes in the set
        while(tmp1){
            NodeSet.insert(tmp1);
            tmp1 = tmp1->next;
        }
        while(tmp2){
            // if it already exist in set then return it
           if( NodeSet.count(tmp2) > 0 )
                return tmp2;
            
            tmp2 = tmp2->next;
        }
        return NULL;
        
    }
};
