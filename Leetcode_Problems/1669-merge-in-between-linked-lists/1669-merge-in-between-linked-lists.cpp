/*
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
     ListNode* left = NULL; // Pointer to the node before a
        ListNode* right = list1; // Pointer to the node after b

        // Traverse the list to find the nodes at positions a-1 and b
        for (int i = 0; i <= b; i++) {
            if (i == a - 1) {
                left = right; // Update left pointer to the node before the range to be removed (a-1)
            }
            right = right->next; 
        }

        // At this point , left => a-1 , right => b+1

        left->next = list2; // Connect the last node before the removed range to the head of list2

        // Traverse list2 to find its last node
        ListNode* tmp = list2;
        while (tmp->next) {
            tmp = tmp->next;
        }

        tmp->next = right; // Connect the last node of list2 to the node after the removed range (b+1)

        return list1;
    }
};