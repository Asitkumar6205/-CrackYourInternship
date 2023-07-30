    int helper(int indx,string s,set<string> &st,string &str){
        if(indx == str.size())
            return (s=="") or (st.find(s) != st.end());
        s += str[indx];
        if(st.find(s) != st.end())
            if(helper(indx+1,"",st,str)) return true;
        return helper(indx+1,s,st,str);
    }
    int wordBreak(string A, vector<string> &B) {
        set<string> st(B.begin(),B.end());
        return helper(0,"",st,A);
    }