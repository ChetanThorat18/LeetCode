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
        // Brute Force

        map<Node* , Node*>mp;  //OldNode , corresponding NewNode

        // first traversal => create new nodes with only values and store in map as Old,New
        Node* tmp = head;
        while(tmp){
            mp[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }

        // second traversal => establish next,random links in NewNodes by referring to corresponding oldNode 
        tmp = head;
        while(tmp){
            // New Nodes next => Corresponding NewNode from OldNode-> next 
            mp[tmp] -> next = mp[tmp->next];
            // New Node random => Corresponding random from olNode->random
            mp[tmp]->random = mp[tmp->random];

            tmp = tmp->next;
        }

        // return head of New list i.e  NewNode corresponding to old head
        return mp[head];
    }
};
