class Solution {
public:
    vector<vector<string>> result;
    set<int> colSet, posDigSet, negDigSet;
    void backtrack(int row, int n, vector<string> curr){
        if(row == n){
            result.push_back(curr);
            return;
        }
        for(int col = 0; col < n; col++){
            if(colSet.find(col) == colSet.end() && posDigSet.find(row+col) == posDigSet.end() && negDigSet.find(row-col) == negDigSet.end()){
                colSet.insert(col);
                posDigSet.insert(row+col);
                negDigSet.insert(row-col);
                curr[row][col] = 'Q';
                backtrack(row+1, n, curr);
                colSet.erase(col);
                posDigSet.erase(row+col);
                negDigSet.erase(row-col);
                curr[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row = "";
        for(int i = 0; i < n; i++) row += '.';
        backtrack(0, n, vector<string>(n, row));
        return result;
    }
};