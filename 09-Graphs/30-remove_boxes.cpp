class Solution {
public:
    int dp[100][100][100];
    int solve(vector<int>& boxes, int b, int e, int k){
        if(b>e) return 0;
        if(dp[b][e][k]!=-1) return dp[b][e][k];
        int res = (k+1)*(k+1)+solve(boxes,b+1,e,0);
        for(int i=b+1; i<=e; i++)
            if(boxes[i]==boxes[b]) res = max(res,solve(boxes,b+1,i-1,0)+solve(boxes,i,e,k+1));
        return dp[b][e][k]=res;
    }
    int removeBoxes(vector<int>& boxes)
    {    
        memset(dp,-1,sizeof dp);
        return solve(boxes, 0, boxes.size()-1, 0);   
    }
};