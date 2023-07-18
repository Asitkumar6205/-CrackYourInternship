class Solution {
public:
    int countuniquePaths(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i==m || j==n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = countuniquePaths(m,n,i+1,j,dp);
        int down = countuniquePaths(m,n,i,j+1,dp);
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countuniquePaths(m,n,0,0,dp);
    }
};