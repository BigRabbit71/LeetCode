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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* p = head;
        ListNode* q = head->next;
        
        while(q){
            if(q->val == p->val){
                q = q->next;
                p->next = q;
            }
            else{
                p = q;
                q = q->next;
            }    
        }
        
        return head;
    }
};