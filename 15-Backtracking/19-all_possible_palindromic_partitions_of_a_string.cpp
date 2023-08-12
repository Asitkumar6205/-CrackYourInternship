class Solution{
public:     
    bool palin(string &temp) {
        int i =0, j=temp.length()-1;
        while (i<j) {
            if (temp[i++] != temp[j--]) return false;
        }
        return true;
    }
    void solve (int idx, string &s, vector<string> &v, vector<vector<string>> &ans) {
        if (idx == s.length()) {
            ans.push_back(v);
            return;
        }      
        
        string temp = "";
        for (int i = idx; i<s.length(); i++) {
            temp += s[i];
            if (palin(temp)) {
                v.push_back(temp);
                solve(i+1,s,v,ans);
                v.pop_back();
            }
        }
        
    }
      
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        vector<string> v;
        solve (0,S,v,ans);
        return ans;
    }
};