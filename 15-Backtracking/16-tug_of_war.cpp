class Solution {
public:
    int dp[3001][31];
    int solve(int idx,int w,vector<int>& stones)
    {
        if(idx<0 || w==0)
        return 0;
        if(dp[w][idx]!=-1)
        return dp[w][idx];
        int take = 0,notTake = 0;
        if(w-stones[idx]>=0)
        take = stones[idx]+solve(idx-1,w-stones[idx],stones);
        notTake = solve(idx-1,w,stones);
        return dp[w][idx] = max(take,notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto &i:stones)
        sum+=i;
        int n = stones.size();
        memset(dp,-1,sizeof(dp));
        int sum1 = solve(n-1,sum/2,stones);
        return (sum-2*sum1);
    }
};