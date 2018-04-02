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
    int pathSum(TreeNode* root, int sum) {
        // 遍历所有的节点
        if(root==nullptr)
            return 0;
        else
            return dfs(root, sum)+pathSum(root->left, sum)+pathSum(root->right, sum);
    }
    
    // 以某个节点为根节点，它的所有子路径之和是sum值的个数
    int dfs(TreeNode *root, int sum){
        int count = 0;
        
        if(root==nullptr)
            return 0;
        else if(root->val == sum)
            ++count;
        
        // point：不断递归减小sum
        count += dfs(root->left, sum-root->val);
        count += dfs(root->right, sum-root->val);
        
        return count;
    }
};