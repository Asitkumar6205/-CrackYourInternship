class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> left(n);
        vector<int> ryt(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                            st.pop();
            if(st.empty())
                left[i]=0;
            else
                left[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(st.empty())
                ryt[i]=n-1;
            else
                ryt[i]=st.top()-1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int area=heights[i]*(ryt[i]-left[i]+1);
            ans=max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=matrix[i][j]-'0';
        
        for(int i=1;i<m;i++)
            for(int j=0;j<n;j++)
                if(dp[i][j]!=0)
                    dp[i][j]+=dp[i-1][j];
        int ans=0;
        for(int i=0;i<m;i++)
            ans=max(ans, largestRectangleArea(dp[i]));
        return ans;
    }
};