class Solution {
public:
    void helper(vector<int>& v, vector<vector<int>>& ans, vector<int> temp, int i){
        if(i==v.size())
            ans.push_back(temp);
        else{                
            //PICK
            temp.push_back(v[i]);
            helper(v,ans,temp,i+1);
            temp.pop_back();

            //NOT PICK
            while(i+1<v.size() && v[i]==v[i+1]) i++;
            helper(v,ans,temp,i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(v,ans,temp,0);
        return ans;
    }
};