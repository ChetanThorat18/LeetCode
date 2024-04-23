/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Pointers to traverse both lists
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Loop until both pointers meet (i.e., reach the intersection point)
        while(ptrA != ptrB ){

            // Move ptrA to the head of the other list if it reaches the end of list A
            if(ptrA == NULL){
               
                ptrA = headB;
            }else{
                ptrA = ptrA->next;
            }

            // Move ptrB to the head of the other list if it reaches the end of list B
            if(ptrB == NULL){
                ptrB = headA;
            }else{
                ptrB = ptrB->next;
            }
        }

        // Return the intersection point (or NULL if there's no intersection)
        return ptrA;
    }
};

/*
    The reason behind resting pointer to head of other list when it reaches
    end of current list is ==> 

    Firstly , pointer which is associated with smaller list will reach end.
    By reseting it to head of longer list , allows it traverse extra nodes in 
    longer list until longer list pointer reaches end of list. 
    Once ptr associated with longer list also reaches end of list , reset it to head of smaller list.

    Now , Move both pointers at same speed to find intersection node.

    This is beacuse , From here onwards , both pointers will need to traverse the same number of nodes .

*/
