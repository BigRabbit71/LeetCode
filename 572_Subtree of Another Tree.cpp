/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr && t!=nullptr)
            return false;
        else if(isSame(s, t))
            return true;
        else{
            return isSubtree(s->left, t) || isSubtree(s->right, t); // point!
        }
    }
    
    bool isSame(TreeNode* s, TreeNode* t){
        if(!s && !t)
            return true;
        else if(!s || !t)
            return false;
        else{
            if(s->val != t->val)
                return false;
            else
                return isSame(s->left, t->left) && isSame(s->right, t->right); // point!
        }
    }
};