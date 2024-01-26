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
        // Optimal Approach
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;

        if(tmp1 == NULL || tmp2 == NULL)
            return NULL;

        // Count length of both the linked lists
        // move longer list head ahead equal to abs(count1-count2)
        // then traverse both linked lists simultaneously until it finds the intersection point

        int count1=0,count2=0;
        while(tmp1){
            count1++;
            tmp1 = tmp1->next;
        }
        while(tmp2){
            count2++;
            tmp2 = tmp2->next;
        }

        int diff = abs(count1 - count2);

        if(count1 > count2){
            tmp1 = headA;
            while(diff > 0){
                tmp1 = tmp1->next;
                diff--;
            }
            tmp2 = headB;
            while(tmp1 && tmp2){
                if(tmp1 == tmp2){
                    return tmp1;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }
        else{
           
            tmp2 = headB;
            while(diff > 0){
                tmp2 = tmp2->next;
                diff--;
            }
            tmp1 = headA;
            while(tmp1 && tmp2){
                if(tmp1 == tmp2){
                    return tmp1;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }

        return NULL; 
    }
};