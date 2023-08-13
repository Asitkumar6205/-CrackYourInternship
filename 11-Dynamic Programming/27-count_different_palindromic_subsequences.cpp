#define MOD 1000000007
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n , 0)) ;
        vector<int> next(n , -1) , prev(n, -1) ;
        unordered_map<char , int> idx ;
        for (int i=0 ; i<n ; i++) {
            char c = s[i] ;
            if (idx.find(c) == idx.end()) 
                idx.insert({c,i});
            else {
                prev[i] = idx[c] ;
                next[idx[c]] = i ;
                idx[c] = i ;
            }
        }
        for (int i=n-1 ; i>=0 ; i--) {
            for (int j=i ; j<n ; j++) {
                if (i==j)
                    dp[i][j] = 1 ;
                else if (s[i] != s[j]) 
                    dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1])%MOD ;
                else {
                    int nextIdx = next[i] , prevIdx = prev[j] ;
                    if (nextIdx > prevIdx || nextIdx == -1) 
                        dp[i][j] = ((2*dp[i+1][j-1])%MOD + 2)%MOD ;
                    
                    else if (nextIdx == prevIdx ) 
                        dp[i][j] = ((2*dp[i+1][j-1])%MOD + 1)%MOD ;
                    else 
                        dp[i][j] = ( (2*dp[i+1][j-1])%MOD - dp[nextIdx+1][prevIdx-1])%MOD ;
                }
                if (dp[i][j] < 0) dp[i][j] = (dp[i][j] + MOD )%MOD ;
            }
        }
        return (int)(dp[0][n-1])%MOD ;
    }
};