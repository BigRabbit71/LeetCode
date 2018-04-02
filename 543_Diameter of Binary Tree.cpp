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
    int maxDiameter = 0;
    int maxDepth(TreeNode *root){
        if(root == nullptr)
            return 0;
        else{
            int m = maxDepth(root->left);
            int n = maxDepth(root->right);
            
            // 对每个节点都求一下两边最长长度之和，如果大于当前最大值，则更新
            if(m+n > maxDiameter)
                maxDiameter = m+n;
            
            return max(m, n)+1;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        
        return maxDiameter;
    }
};