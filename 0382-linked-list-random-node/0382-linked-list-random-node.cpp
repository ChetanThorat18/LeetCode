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
    vector<int>arr;
    Solution(ListNode* head) {

        ListNode* curr = head;
        while(curr){
            arr.push_back(curr->val);
            curr = curr -> next;
        }
    }
    
    int getRandom() {
        int n = arr.size();

        int random_index = rand() % n ;   // Return a number from 0 to n-1 with equal probability

        return arr[random_index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */