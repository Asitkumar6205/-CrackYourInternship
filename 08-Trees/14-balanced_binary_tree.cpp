class Solution {
public:
    int f=true;
    int solve(TreeNode* root){
        if(!root) return true;
        int lh=solve(root->left);        
        int rh=solve(root->right);
        if(abs(lh-rh)>1) f=false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        f=true;
        solve(root);
        return f;
    }
};