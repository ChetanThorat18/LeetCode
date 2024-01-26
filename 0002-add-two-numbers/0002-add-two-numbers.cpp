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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize a new ListNode to store the result
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3; // Pointer to the head of the result
        int carry = 0; // Variable to store the carry value

        // Iterate through both linked lists
        while (l1 && l2) {
            // Calculate the sum of current digits and carry
            int sum = l1->val + l2->val + carry;

            // Update the result ListNode with the current digit of the sum
            l3->next = new ListNode(sum % 10);

            // Update the carry for the next iteration
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }

        // Process the remaining nodes in l1, if any
        while (l1) {
            int sum = l1->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l3 = l3->next;
        }

        // Process the remaining nodes in l2, if any
        while (l2) {
            int sum = l2->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;
            l3 = l3->next;
        }

        // If there's a carry left, create a new node for it
        if (carry) {
            l3->next = new ListNode(carry);
        }

        // Return the result starting from the second node (head->next)
        return head->next;
    }
};
