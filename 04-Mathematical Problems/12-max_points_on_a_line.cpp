class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans=1;
        for(int i=0;i<p.size();i++){
            unordered_map<double,int>m;
            for(int j=0;j<p.size();j++){
                if(i==j)
                    continue;
                double num=(double)(p[i][0]-p[j][0])/(p[i][1]-p[j][1]);
                double val=atan(num);
                m[val]++;
                ans=max(ans,m[val]+1);
            }
        }
        return ans;
    }
};