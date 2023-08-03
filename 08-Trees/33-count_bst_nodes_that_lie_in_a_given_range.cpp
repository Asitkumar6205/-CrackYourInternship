class Solution{
public:
    int ans = 0;
    int getCount(Node *root, int l, int h){
        if(!root)
            return 0;
        if(root->data >= l && h >= root->data) 
            ans++;
        getCount(root->left, l, h);
        getCount(root->right, l, h);
        return ans;
    }
};