class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> t(n+1);
        t[n] = 1;
        for(int i = n-1; i >= 0; --i) {
            if(s[i] == '0')
                t[i] = 0; 
            else {
                t[i] = t[i+1];
                if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) 
                    t[i] += t[i+2];
            }
        }
        return t[n];
    }
};