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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        unordered_map<ListNode* , bool>visited;

        ListNode* tmp = head;

        while(tmp){
            if(visited[tmp]){
                return tmp;
            }
            visited[tmp] = true;
            tmp = tmp->next;
        }
        return NULL;
    }
};
