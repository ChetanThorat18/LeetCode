class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Approach : Slight Optimisation to previous Approach
        // Instead of traversing complete linked list first to find middle node and then traverse second half
        // Directly reverse first half while finding middle node

        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Reverse the first half of the linked list
        while (fast && fast->next) {
            fast = fast->next->next;

            // Reverse the slow pointer's next pointer
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        //  if the length of the linked list is odd(Skip middle node)
        if (fast != NULL) {
            slow = slow->next;
        }

        // Prev => new head of reversed first half
        // Slow => head of second half

        // Compare the reversed first half with the second half of the linked list
        while (prev && slow) {
            // If values mismatch, the linked list is not a palindrome
            if (prev->val != slow->val)
                return false;

            slow = slow->next;
            prev = prev->next;
        }

        return true;
    }
};
