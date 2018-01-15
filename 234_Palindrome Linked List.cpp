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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode* mid = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the mid point
        while(fast && fast->next){
            fast = (fast->next)->next;
            slow = slow->next;
        }
        mid = slow;
        
        // Reverse the second part of the linked list
        ListNode* cur = mid;
        ListNode* pre = NULL;
        ListNode* temp = NULL;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        // Compare with head & pre
        while(head != mid){
            if(head->val == pre->val){
                head = head->next;
                pre = pre->next;
            }else
                return false;
        }
        return true;   
    }
};