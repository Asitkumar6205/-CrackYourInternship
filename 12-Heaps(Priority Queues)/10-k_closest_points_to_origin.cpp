class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& c, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        vector<vector<int>> ans;
        for(int i=0; i<c.size(); i++){
            double x = c[i][0]*c[i][0];
            double y = c[i][1]*c[i][1];
            double z = sqrt(x+y);

            pq.push({z,c[i]});

            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};