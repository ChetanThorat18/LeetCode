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
    vector<int> nextLargerNodes(ListNode* head) {
/*
  - 
  - While the stack is not empty and the current node has a larger value than the top of    the stack, update the result for the node at the top of the      stack and pop from  the stack.

*/
    

    vector<int>result;
    stack<pair<int, int>> stk;  // Pair: (node value, node index)
   
    ListNode* tmp = head;
    int index = 0;
    while(tmp){
        result.push_back(0);  // Initialize the result for the current node.
        while( !stk.empty() && tmp->val > stk.top().first){
            result[stk.top().second] = tmp->val;
            stk.pop();
        } 

        // Push the current node onto the stack to find its next greater node.
            stk.push({tmp->val, index++});
            tmp = tmp->next;
    }

    return result;
    }
};