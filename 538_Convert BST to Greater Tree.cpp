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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        /* 二叉查找树，则中序遍历的逆序则为一个降序的遍历
        *  遍历过后，则累加到sum，每次遍历一个节点，则将之前的sum累加上去
        */
        if(root == nullptr)
            return root;
        else{
            root->right = convertBST(root->right);
            
            // 先保存下来
            int temp = root->val;
            root->val += sum;
            sum += temp;
            
            root->left = convertBST(root->left); 
            
            return root;
        }
    }
};