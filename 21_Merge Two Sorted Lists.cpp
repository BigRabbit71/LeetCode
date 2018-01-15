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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        if(l1==NULL && l2==NULL) return NULL;
        else if(l1!=NULL && l2==NULL) return l1;
        else if(l1==NULL && l2!=NULL) return l2;
        else{
            while(l1 && l2){
                if(l1->val <= l2->val){
                    cur->next = l1;
                    cur = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l2;
                    cur = l2;
                    l2 = l2->next;
                }
            }
            if(l1==NULL)
                cur->next = l2;
            else
                cur->next = l1;  
        }
        return head->next;
    }
};