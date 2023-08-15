class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    } 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++)
            v[i] = {intervals[i][0], intervals[i][1]};
        sort(v.begin(), v.end(), cmp);
        int count = 1;
        int endTime = v[0].second;
        for(int i=1; i<n; i++){
            if(v[i].first >= endTime){
                count++;
                endTime = v[i].second;
            }
        }
        return n-count;
    }
};