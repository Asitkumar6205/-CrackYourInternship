class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n=v.size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(v[i][j],v[j][i]);
        }
        //reverse
        for(int i=0;i<n;i++)
            reverse(v[i].begin(),v[i].end());
    }
};