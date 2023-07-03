class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string &word, int i, int j, int start) {
        int m = board.size(), n = board[0].size();
        if(start == word.size()) return true;
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || board[i][j] != word[start]) return false;
        
        vis[i][j] = true;
        bool a = dfs(board, vis, word, i+1, j, start+1) ||
                 dfs(board, vis, word, i-1, j, start+1) ||
                 dfs(board, vis, word, i, j+1, start+1) ||
                 dfs(board, vis, word, i, j-1, start+1);
        
        vis[i][j] = false; // Reset the visited state for backtracking
        return a;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board, vis, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};