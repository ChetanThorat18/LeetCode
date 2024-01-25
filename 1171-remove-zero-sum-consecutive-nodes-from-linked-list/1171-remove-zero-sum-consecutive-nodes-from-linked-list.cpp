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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        //  hash map to store the cumulative sum and corresponding node
        unordered_map<int, ListNode*> mp;
        mp[0] = dummyNode;

        ListNode* curr = head;
        int prefixSum = 0;
        while (curr) {
            prefixSum += curr->val;

            // Check if the current cumulative sum is encountered before
            // If present , it indicates the presence of a subsequence with a sum of zero from that node to current node.
            if (mp.find(prefixSum) != mp.end()) {
                // If encountered, find the starting node of the sequence with the same sum
                ListNode* start = mp[prefixSum];
                ListNode* tmp = start->next;

                // Iterate from this starting node to the current node, removing nodes and their corresponding entries in map
                 int pSum = prefixSum;
                while (tmp != curr) {
                    pSum += tmp->val;
                    mp.erase(pSum);
                    tmp = tmp->next;
                }

                // Adjust the next pointer of the starting node to skip the removed sequence (nodes to be deleted)
                start->next = curr->next;
            }

            // If the current cumulative sum is encountered for the first time, store it in the hash map
            else {
                mp[prefixSum] = curr;
            }

            curr = curr->next;
        }

        return dummyNode->next;
    }
};