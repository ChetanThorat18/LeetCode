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
       // Brute Force
       vector<int>ans;

       if(head == NULL )
            return ans;
        if(head->next == NULL){
            ans.push_back(0);
            return ans;
        }
             

       ListNode* curr = head;
      
      // for each node , find next greater element using nested Loop
       while(curr->next){
           ListNode* tmp = curr->next;
            bool found = false;
           while(tmp){
               if(tmp->val > curr->val){
                    found = true;
                   ans.push_back(tmp->val);
                   break;
               }
               tmp = tmp->next;
           }

            if(! found){
                ans.push_back(0);
            }

           curr = curr->next;
       } 
       // Last element will not have next greater element
       ans.push_back(0);
       return ans;
    }
};
