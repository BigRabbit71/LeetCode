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
    bool compare(TreeNode *left, TreeNode *right){
        if(left==nullptr && right==nullptr)
            return true;
        else if(left==nullptr && right!=nullptr)
            return false;
        else if(left!=nullptr && right==nullptr)
            return false;
        else{
            if(left->val != right->val)
                return false;
            else
                return compare(left->left, right->right)&&compare(left->right, right->left); // point!
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        else{
            return compare(root->left, root->right);
        }
    }
};
