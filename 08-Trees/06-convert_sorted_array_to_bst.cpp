class Solution {
public:
    TreeNode* create(int l,int h,vector<int>&v){
        if(l==h) return new TreeNode(v[l]);
        if(l>h) return NULL;
        int mid=l+(h-l)/2;
        TreeNode* tree = new TreeNode(v[mid]);
        tree->left = create(l,mid-1,v);
        tree->right = create(mid+1,h,v);
        return tree;
    }
    TreeNode* sortedArrayToBST(vector<int>&v){
        int l=0;
        int h=v.size()-1;
        return create(l,h,v);
    }
};