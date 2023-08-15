class Solution {
public:
    int f(int i, string& c, vector<int>& t, vector<int>& dp, char prevc, int prevt) {
        if(i < 0) 
            return 0;
        if(dp[i] != -1)
            return dp[i];
        if(c[i] == prevc)
            return dp[i] = f(i - 1, c, t, dp, c[i], max(t[i], prevt)) + min(t[i], prevt);
        else 
            return dp[i] = f(i - 1, c, t, dp, c[i], t[i]);
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return f(n - 1, colors, neededTime, dp, 'A', neededTime[n - 1]);
    }
};