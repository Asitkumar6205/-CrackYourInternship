class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it : nums)
            m[it]++;
        int mx = INT_MIN;
        for(auto it : m)
            mx = max(it.second, mx);
        for(auto it : m){
            if(it.second == mx){
                mx = it.first;
                break;
            }
        }
        return mx;
    }
};