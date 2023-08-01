class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int m, int n, int &maxlen, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int len = 0;
        if(nums1[m-1] == nums2[n-1])
            len = 1 + solve(nums1, nums2, m-1, n-1, maxlen, dp);
        maxlen = max(len, maxlen);
        solve(nums1, nums2, m-1, n, maxlen, dp); 
        solve(nums1, nums2, m, n-1, maxlen, dp);
        return dp[m][n] = len;

    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int maxlen = 0;
        solve(nums1, nums2, m, n, maxlen, dp);
        return maxlen;
    }
};
