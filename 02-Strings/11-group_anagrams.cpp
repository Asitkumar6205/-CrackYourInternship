class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string, vector<string>> m;

        for(int i=0; i<s.size(); i++){
            string key(26, '0');
            for(auto it : s[i]) 
                key[it-'a']++;
            m[key].push_back(s[i]);
        }

        vector<vector<string>> ans;
        for(auto it : m) 
            ans.push_back(it.second);
        return ans;
    }
};