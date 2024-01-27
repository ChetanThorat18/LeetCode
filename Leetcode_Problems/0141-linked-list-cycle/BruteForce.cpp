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
    bool hasCycle(ListNode *head) {
        ListNode* tmp = head;

        //Create hashmap to check whether current node is visited or not
        //(use key as node itself and not a value) since values can be duplicate but address(node) cannot
        unordered_map<ListNode*, bool> visited;

        while( tmp != NULL){
            if(visited[tmp])
                return true;

            visited[tmp] = true;

            tmp = tmp->next;
        }
        return false;
    }
};
