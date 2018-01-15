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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(0);
        ListNode* cur = new_head;
        
        while(head){
            if((head->val) == val){
                head = head->next;
            }else{
                cur->next = head;
                head = head->next;
                cur = cur->next;
            }
        }
        
        //记得截断！
        cur->next = NULL; 
        
        return new_head->next;
    }
};