class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size(),M=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]= 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]%M + dp[i-1][j]%M;
                else dp[i][j] = dp[i-1][j]%M;
            }
        }
        return dp[n][m]%M;
    }
};