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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // Get the length of the linked list
        int length = 0;
        ListNode* cur = root;
        while(cur){
            length++;
            cur = cur->next;
        }
        
        // Get the size of every part 
        vector<int> size_vec(k, (length/k));
        for(int i=0; i<(length%k); i++) size_vec[i]++;       
        
        // Get the parts
        vector<ListNode*> parts(k, NULL);
       
        for(int i=0; i<k; i++){ //k parts
            ListNode* part_head = new ListNode(0);
            ListNode* part_cur = part_head;
            if(size_vec[i] > 0){
                for(int j=0; j<size_vec[i]; j++){
                    part_cur->next = root;
                    root = root->next;
                    part_cur = part_cur->next;
                }
                part_cur->next = NULL;    
            }
            parts[i] = part_head->next;
        }
        
        return parts;    
    }
};