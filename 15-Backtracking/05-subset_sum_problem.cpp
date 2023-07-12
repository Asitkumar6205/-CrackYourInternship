class Solution {
public:
    int helper(int n, vector<int> &v, int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int j=1; j<=sum; j++)
            dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if(dp[i][j] != true){
                    if(j >= v[i-1])
                        dp[i][j] = dp[i-1][j-v[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int> &v) {
        int sum = 0;
        int n = v.size();
        for(int i=0; i<n; i++)
            sum += v[i];
        if(sum%2 != 0)
            return 0;
        else
            return helper(n-1, v, sum/2);
    }
};