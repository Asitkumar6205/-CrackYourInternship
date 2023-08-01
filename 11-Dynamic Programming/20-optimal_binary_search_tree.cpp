int optCost_memoized(int freq[], int i, int j) {
    if (cost[i][j])
        return cost[i][j];
    int fsum = Sum(freq, i, j);
    int Min = INT_MAX;
    for (int r = i; r <= j; r++) {
        int c = optCost_memoized(freq, i, r - 1) + optCost_memoized(freq, r + 1, j) + fsum;
        if (c < Min) {
            Min = c;
            cost[i][j] = c;
        }
    }
    return cost[i][j];
}