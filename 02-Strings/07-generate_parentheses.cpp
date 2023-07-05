class Solution {
public:
    void backtrack(int n, vector<string> &ans, string temp, int open, int close){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n)
            backtrack(n, ans, temp+"(", open+1, close);
        if(close<open)
            backtrack(n, ans, temp+")", open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        backtrack(n, ans, temp, 0, 0);
        return ans;
    }
};