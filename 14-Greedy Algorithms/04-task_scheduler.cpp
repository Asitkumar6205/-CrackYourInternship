class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto it : tasks)
            mp[it]++;
        int maxCount=0;
        for(auto it : mp)
            maxCount=max(maxCount,it.second);
        int res=(maxCount-1)*(n+1);
        for(auto it : mp)
            if(it.second==maxCount) res++;
        res=max(res,(int)tasks.size());
        return res;
    }
};