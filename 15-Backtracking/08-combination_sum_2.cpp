class Solution {
public:
    void helper(vector<int>& v, int target, vector<vector<int> >& ans, vector<int>& temp, int i, int sum){ 
        if(target == sum){
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;
        if(i==v.size()) return;
        temp.push_back(v[i]);
        sum += v[i];
        helper(v,target,ans,temp,i+1,sum);
        temp.pop_back();
        sum -= v[i];
        while(i+1<v.size() && v[i]==v[i+1]) i++;
        helper(v,target,ans,temp,i+1,sum);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(v,target,ans,temp,0,0);
        return ans;
    }
};