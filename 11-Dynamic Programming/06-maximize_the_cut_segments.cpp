class Solution{
    public:
    int maximizeTheCuts(int n, int x, int y, int z){
        vector <int> v = {x,y,z},dp(n+1,INT_MIN);
        dp[0] = 0;
        for(int i = 0;i < 3;i++)
            for(int j = 1;j <= n;j++)
                if(v[i] <= j) dp[j] = max(1+dp[j-v[i]],dp[j]);
        return dp[n] < 0 ? 0 : dp[n];
    }
};