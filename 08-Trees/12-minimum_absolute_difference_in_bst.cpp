class Solution {
public:
    void helper(TreeNode *node, TreeNode *&prev, int &ans) {
        if (!node)
            return;
        helper(node->left, prev, ans);
        if (prev)
            ans = min(ans, node->val - prev->val);
        prev = node;
        helper(node->right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode *prev = NULL;
        helper(root, prev, ans);
        return ans;
    }
};