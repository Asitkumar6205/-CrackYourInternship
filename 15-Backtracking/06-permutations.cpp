class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>& v, int i){
        if(i==v.size()){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<v.size();j++){
            swap(v[i],v[j]);
            helper(ans,v,i+1);
            swap(v[i],v[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        helper(ans,v,0);
        return ans;
    }
};