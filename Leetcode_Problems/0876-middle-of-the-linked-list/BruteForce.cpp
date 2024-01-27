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
    ListNode* middleNode(ListNode* head) {
        // Brute Force

        // Calculate the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

       int middleIndex = length / 2;
        current = head;

        // Traverse the linked list to find the middle node
        for (int i = 0; i < middleIndex; i++) {
            current = current->next;
        }

        return current;

        
    }
};
