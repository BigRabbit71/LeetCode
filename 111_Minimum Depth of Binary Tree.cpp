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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        else{
            int m = minDepth(root->left);
            int n = minDepth(root->right);
            
            if(m && n)
                return min(m, n)+1;
            else
                //有一个孩子是空的，不能取那一边
                return max(m, n)+1;
        }
    }
};