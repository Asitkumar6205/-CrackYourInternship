class Solution {
public:
    void helper(vector<int>& v, vector<int>& temp, vector<vector<int>>& ans, int i) {
        if(i==v.size())
            ans.push_back(temp);
        else{
            temp.push_back(v[i]);
            helper(v,temp,ans,i+1);
            temp.pop_back();
            helper(v,temp,ans,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(v,temp,ans,0);
        return ans;
    }
};