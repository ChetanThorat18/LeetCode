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
        // Brute Force

        vector<int>LL;
        ListNode* curr = head;

        while(curr){
            LL.push_back(curr->val);
            curr = curr->next;
        }

        int maxTwinSum = INT_MIN;

        int i=0 , j = LL.size()-1;
        while(i < j){
            maxTwinSum = max(maxTwinSum , LL[i++] + LL[j--]);
        }

        return maxTwinSum;

    }
};
