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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
      return NULL;
    } 

    ListNode* partitionAndMerge(int start, int end,vector<ListNode*>&lists){

        if(start == end) // if only one list , then return it
            return lists[start];

        int mid = (start+end) / 2;

        ListNode* L1 = partitionAndMerge(start,mid,lists);
        ListNode* L2 = partitionAndMerge(mid+1,end,lists);

        return mergeTwoLists(L1,L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k==0)
            return NULL;

        return partitionAndMerge(0,k-1,lists);
    }
};