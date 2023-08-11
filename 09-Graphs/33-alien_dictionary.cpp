class Solution{
    public:
        string findOrder(string dict[], int N, int K) {
        map<char, int> mp;
        char ch = 'a';
        for(int i=0; i<26; i++) {
            mp[ch] = i;
            ch++;
        }
    
        vector<vector<int>> dag(K);
    
        for(int i=0; i<N-1; i++) {
            int j=0, k=0;
            int flag = 0;
            while(j<dict[i].size() && k<dict[i+1].size()) {
                if(dict[i][j] != dict[i+1][k] && flag == 0) {
                    dag[mp[dict[i][j]]].push_back(mp[dict[i+1][k]]);
    
                    flag = 1;
                }
    
                j++;
                k++;
            }
        }
    
        vector<int> indegree(K, 0);
    
        for(int i=0; i<dag.size(); i++) {
            for(auto it: dag[i]) {
                indegree[it]++;
            }
        }
    
        queue<int> q;
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        string topo;
    
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            topo.push_back(n + 'a');
            for(auto it: dag[n]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
    
        return topo;
    }
};