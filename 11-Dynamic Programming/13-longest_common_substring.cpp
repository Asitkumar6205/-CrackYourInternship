int solve(int i, int j, int n, int m, string &s1, string &s2,vector<vector<int>>&dp){
    if(i == n || j == m)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] =  1 + solve(i+1,j+1,n,m,s1,s2,dp);
    return 0;
}

int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
    int res = 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            res = max(res,solve(i,j,n,m,str1,str2,dp));
    }
    return res;
}