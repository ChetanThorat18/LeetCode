/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Optimal Approach :-> Space Complexity O(1) && Time Complexity O(3n) ~ O(n)
        if(head == NULL)
            return head;

        // Step 1 => Insert New nodes as copy of old node in between two nodes in original List
        // eg- Original List -->    1->2->3->4->NULL
        // Modified List -->     1->1'->2->2'->3->3'->4->4'->NULL

        Node* tmp = head;
        while(tmp){
            Node* front = tmp->next;
            Node* copyNode = new Node(tmp->val);
            copyNode->next = front;
            tmp->next = copyNode;
            tmp = front;
        }

        // Step 2 => Set random pointers link in CopyNodes
        tmp = head;
        while(tmp){
            if(tmp->random != NULL){  // because if random is NULL then it is already set 
                tmp->next->random = tmp->random->next;  // copyNode->random = oldNode->random->next (corresponding copyNode)
            }
            tmp = tmp->next->next;
        }

        // Step 3 => Now set next pointer link in copyNodes to corresponding copyNode and separate original and new List
        // i.e  1->2->3->4   and  1'->2'->3'->4'

        tmp = head;
        Node* newHead = new Node(0);
        newHead->next = tmp->next;
        while (tmp) {
            Node* front = tmp->next->next; // Save the next original node

            // checks whether there is a next original node (front) 
            // if so, sets the next pointer of the current copy node (tmp->next) to the next copy node in the modified list (front->next).
            //If there is no next original node (i.e., front is nullptr), it sets the next pointer of the current copy node to nullptr.
            tmp->next->next = front ? front->next : nullptr; // Connect copyNode->next to its corresponding copyNode

            tmp->next = front; // Connect originalNode->next to the next original node
            tmp = front; // Move to the next original node
        } 
         

        return newHead->next;
    }
};