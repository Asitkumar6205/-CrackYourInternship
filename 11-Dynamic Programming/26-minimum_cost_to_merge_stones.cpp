class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>&p,int k){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int h=i;h<j;h+=k-1){
            ans=min(ans,solve(i,h,dp,p,k)+solve(h+1,j,dp,p,k));
        }
        if((j-i)%(k-1)==0){
            if(i==0) ans+=p[j];
            else ans+=p[j]-p[i-1];
        }
        return dp[i][j]=ans;
    }
    int mergeStones(vector<int>& v, int k) {
        int n=v.size();
        if((n-1)%(k-1)!=0) return -1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>p=v;
        for(int i=1;i<n;i++) p[i]+=p[i-1];
        return solve(0,n-1,dp,p,k);
    }
};