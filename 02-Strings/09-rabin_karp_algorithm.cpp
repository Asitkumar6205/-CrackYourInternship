class Solution{
public:
   vector<int> search(string pat, string txt){
       int m = txt.length();
       int n = pat.length();
       vector<int> ans;
       int j;
       for(int i = 0; i<=m-n; i++){
           for(j = 0; j<n; j++){
               if(pat[j] != txt[i+j])
                   break;
           }
           if(j==n)
               ans.push_back(i+1);
       }
       if (ans.empty())
           return {-1};
       return ans;
   }
};