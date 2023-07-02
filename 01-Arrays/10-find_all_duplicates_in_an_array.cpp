class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto it : nums){
            m[it]++;
            if(m[it]==2)
                ans.push_back(it); 
        }
        return ans;
    }
};