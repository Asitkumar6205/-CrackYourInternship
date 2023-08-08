class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board){
        queue<int> q ; q.push(1);
        int n = board.size(), goal = n*n;
        vector<int> dist(goal + 1, 1e9); dist[1] = 0;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            if(curr == goal ) break;
            for(int i=1; i<=6; i++){
                int next = i + curr;
                if(next > goal) continue;
                int r = (next-1)/n, c = (next-1)%n;
                int & vertex = board[n-1-r][r%2 == 0 ? c : n-1-c];
                if( vertex != 0){
                    next = vertex > 0 ? vertex : next;
                    dist[next] = dist[next] > dist[curr] + 1 ? dist[curr] + 1 : dist[next];
                    q.push(next);
                    vertex = 0;
                } 
            }
        }
        return dist[goal] == 1e9 ? -1 : dist[goal];
    }
}; 