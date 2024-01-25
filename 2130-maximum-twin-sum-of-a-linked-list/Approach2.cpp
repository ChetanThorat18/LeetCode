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
    int pairSum(ListNode* head) {
        // Approach : Using Stack

        stack<int>stk;
        ListNode* curr = head;
        while(curr){
            stk.push(curr->val);
            curr = curr->next;
        }

        int n = stk.size();
        int count = 1;
        curr = head;
        int result = INT_MIN;

        while(count <= n/2){
            result = max(result , curr->val + stk.top());
            curr = curr->next;
            stk.pop();
            count++;
        }

        return result;

    }
};
