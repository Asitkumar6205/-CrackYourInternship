class Solution{
    array<int,4>solve(Node*root,int &maxi){
        if(!root) return {(int)-1e9,(int)1e9,0,1};//{max_val,min_val,sz,res}
        auto Left=solve(root->left);
        auto Right=solve(root->right);
        array<int,4>ans={
            max({Left[0],Right[0],root->data}),
            min({Left[1],Right[1],root->data}),
            Left[2]+Right[2]+1,
            Left[3]&Right[3]&(root->data>Left[0]&&root->data<Right[1])
        };
        maxi=max(maxi,ans[3]?ans[2]:0);
        return ans;
    }
    public:
    int largestBst(Node *root)
    {
        int maxi=-1e9;
        solve(root,maxi);
        return maxi;
    }
};