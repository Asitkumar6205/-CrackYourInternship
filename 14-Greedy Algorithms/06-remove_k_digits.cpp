class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(auto x : num){
        while(ans.length() && ans.back() > x && k){
            ans.pop_back();
            k--;
        }
        if(ans.length() || x != '0')
            ans.push_back(x);
        }
        while(ans.length() && k--)
            ans.pop_back();
        if(ans == "") ans = "0";
        return ans;
    }
};