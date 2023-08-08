class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            adj[from].push_back({to, cost});
        }
        vector<long long> dist(n, LONG_MAX);
        priority_queue<pair<int, pair<long long, int>>, vector<pair<int, pair<long long, int>>>, greater<pair<int, pair<long long, int>>>> q;
        q.push({0, {0, src}});
        dist[src] = 0;
        long long int ans = LONG_MAX;
        while(q.size()){
            int stop = q.top().first;
            long long total  = q.top().second.first;
            int from = q.top().second.second;
            q.pop();
            if(stop <= k + 1 && from == dst)
                ans = min(ans, total);
            if(stop <= k){
                for(auto it : adj[from]){
                    int to = it.first;
                    int cost = it.second;
                    if(dist[to] > total + cost){
                        dist[to] = total + cost;
                        q.push({stop + 1, {dist[to], to}});
                    }
                }
            }
        }
        return ans == LONG_MAX ? -1 : ans;
    }
};