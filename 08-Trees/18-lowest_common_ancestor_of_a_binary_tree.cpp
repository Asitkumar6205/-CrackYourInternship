class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val==root->val or q->val==root->val)
            return root;
        if(!root->right and !root->left)
            return NULL;
        TreeNode *left = NULL, *right = NULL;
        if(root->left)
            left = lowestCommonAncestor(root->left, p, q);
        if(root->right)
            right = lowestCommonAncestor(root->right, p, q);
        if(left and right)
            return root;    
        return left==NULL?right:left;
    }
};