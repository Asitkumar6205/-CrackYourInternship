class Solution {
public:
    bool ans=false;
    bool map(TreeNode* root, TreeNode* soot){
        if(root!=NULL && soot!=NULL){
            bool r=map(root->left,soot->left);                         
            bool s=map(root->right,soot->right);
            if(root->val==soot->val && r && s)
                return true;
            else return false;
        }
        else if(root==NULL && soot==NULL)
            return true;
        else return false;
    }
    void inorder(TreeNode* root, TreeNode* soot) {
        if(root!=NULL){
            inorder(root->left,soot);
            bool m=map(root,soot);
            if(m) ans=m;
            inorder(root->right,soot);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* soot) {
        inorder(root,soot);
        return ans;
    }
};