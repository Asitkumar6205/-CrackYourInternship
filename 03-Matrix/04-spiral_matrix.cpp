class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v){
        int m=v.size()-1;
        int n=v[0].size()-1;
        int t=0, b=m, l=0, r=n, d=0;
        vector<int>ans;
        
        while(t<=b && l<=r){
            if(d==0){
                for(int i=l;i<=r;i++)
                    ans.push_back(v[t][i]);
                t++;
            }
            if(d==1){
                for(int i=t;i<=b;i++)
                    ans.push_back(v[i][r]);
                r--;
            }
            if(d==2){
                for(int i=r;i>=l;i--)
                    ans.push_back(v[b][i]);
                b--;
            }
            if(d==3){
                for(int i=b;i>=t;i--)
                    ans.push_back(v[i][l]);
                l++;
            }
            d=(d+1)%4;
        }
        return ans;
    }
};