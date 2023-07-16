class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {\
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto it: v)
            m[it]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        return ans;
    }
};