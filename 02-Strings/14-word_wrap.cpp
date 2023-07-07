class Solution {
public:
    int solveWordWrap(vector<int> nums, int k){
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        int i, j, curr, cost;
        dp[n-1] = 0;
        for(i=n-2; i>=0; i--){
            curr = -1;
            for(j=i; j<n; j++){
                curr += nums[j]+1;
                if(curr>k)
                    break;
                if(j==n-1)
                    cost = 0;
                else
                    cost = (k-curr)*(k-curr)+dp[j+1];
                dp[i] = min(dp[i],cost);
            }
        }
        return dp[0];
    } 
};