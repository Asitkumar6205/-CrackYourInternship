class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto it :  strs){
            string s= it;
            sort(s.begin(),s.end());
            mp[s].push_back(it);
        }
        for( auto x :mp)
            ans.push_back(x.second);
        return ans;
    }
};