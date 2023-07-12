class Solution {
public:
    void helper(vector<int>& v, int target, vector<vector<int> >& ans, vector<int>& temp, int i){ 
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        while(i<v.size() && target-v[i]>=0){
            temp.push_back(v[i]);
            helper(v,target-v[i],ans,temp,i);
            i++;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(v,target,ans,temp,0);
        return ans;
    }
};