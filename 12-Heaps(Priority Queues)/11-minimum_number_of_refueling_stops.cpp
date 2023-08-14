class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<int>> t(n+1, vector<int>(n+1, 0));
        
        for(int i = 0; i<n+1; i++) 
            t[i][0] = startFuel;

        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j <= i; j++) { 
                t[i][j] = t[i-1][j];
                if(t[i-1][j-1] >= stations[i-1][0]) 
                    t[i][j] = max(t[i][j], t[i-1][j-1] + stations[i-1][1]);
            }
        }
        
        for(int j = 0; j<n+1; j++) {
            if(t[n][j] >= target)
                return j;
        }

        return -1;
    }
}; 