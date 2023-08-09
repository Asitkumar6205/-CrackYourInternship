class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        left = left>0 ? left:0;
        right = right>0 ? right:0;
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};