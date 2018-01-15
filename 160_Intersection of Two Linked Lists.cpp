/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<algorithm>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        int m = 0, n = 0;
        
        // Get the lengths of two linked list
        while(cur1){
            m++;
            cur1 = cur1->next;
        } 
        while(cur2){
            n++;
            cur2 = cur2->next;
        }
        
        ListNode* curA = new ListNode(0);
        ListNode* curB = new ListNode(0);
        curA->next = headA;
        curB->next = headB;
        int delta = 0;
        if(m<n){
            ListNode* temp = curA;
            curA = curB;
            curB = temp;
            delta = n-m;
        }else{
            delta = m-n;
        }
        
        for(int i=delta; i>0; i--){
                curA = curA->next;
        }
        for(int i=min(m, n); i>0; i--){
            if(curA->next == curB->next)
                return curA->next;
            else{
                curA = curA->next;
                curB = curB->next;
            }
        }
        return NULL;
    }
};