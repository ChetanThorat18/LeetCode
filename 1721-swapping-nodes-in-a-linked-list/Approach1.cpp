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
    int findLength(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* swapNodes(ListNode* head, int k) {
      // Approach 1 

      // Step 1: Find the length of the linked list
      int length = findLength(head);  

      // Step 2: Find the kth node from the beginning
      int k1 = k;
      ListNode* Node1 = head;  
      while(k1 > 1){
          Node1 = Node1->next;
          k1--;
      }

      // Step 3: Find the kth node from the end (length - k + 1)th node from beginning
      int k2 = length - k + 1 ; 
      ListNode* Node2 = head;
      while(k2 > 1){
          Node2 = Node2->next;
          k2--;
      }

      //Swap the values of the two nodes
      swap(Node1->val , Node2->val);

      return head;
    }
};
