class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();
        if(h<n) return -1;
        if(haystack == needle) return 0;
        for(int i=0; i<h-n+1; i++){
            if(haystack.substr(i,n) == needle)
                return i;
        }
        return -1;
    }
};