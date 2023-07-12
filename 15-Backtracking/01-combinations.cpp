class Solution {
public:
    void backtracking(vector<int> v, int k, vector<vector<int>>& ans, vector<int>& temp, int i){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<v.size(); j++){
            temp.push_back(v[j]);
            backtracking(v, k, ans, temp, j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(vector<int> v, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtracking(v, k, ans, temp, 0);
        return ans;
    }
};