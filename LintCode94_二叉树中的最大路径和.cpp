/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        // write your code here
        // case err:
        if(root == nullptr){
            return 0;
        }
        
        // case normal:
        int res = INT_MIN;
        int oneSideSum = helper(root, res);
        return res;
    }
    
    int helper(TreeNode *root, int &maxSum){
        if(root == nullptr){
            return 0;
        }
        
        int leftSum = helper(root->left, maxSum);
        int rightSum = helper(root->right, maxSum);
        
        // maxSum是一个全局最大值，通过引用来达到全局的目的
        maxSum = max(maxSum, max(0, leftSum)+max(0, rightSum)+root->val);
        
        // 返回给上层的sum只能选择和更大的那边的oneSideSum，或者左右孩子都是负值sum，就返回自己
        int oneSideSum = max(max(0, leftSum), max(0, rightSum)) + root->val;
        return oneSideSum;
    }
};