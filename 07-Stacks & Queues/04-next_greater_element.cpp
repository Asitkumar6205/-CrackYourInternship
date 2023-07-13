class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(auto it:nums2){
            while(st.size() && st.top() < it){
                mp[st.top()] = it;
                st.pop();
            }
            
            st.push(it);
        }
        vector<int> ans;
        for(auto it:nums1){
            ans.push_back((mp.count(it) ? mp[it] : -1));
        }
        return ans;
    }
};