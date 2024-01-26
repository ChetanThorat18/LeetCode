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
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        // Step 2: Compare the values to check for a palindrome
        int start = 0;
        int end = values.size() - 1;
        while (start < end) {
            if (values[start] != values[end]) {
                return false; // Not a palindrome
            }
            start++;
            end--;
        }

        return true; // Palindrome
    }
};
