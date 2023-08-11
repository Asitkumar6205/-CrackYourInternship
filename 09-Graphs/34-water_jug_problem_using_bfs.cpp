int solve(int m,int n,int &d){
    int ans = 1,j1 = m,j2 = 0; // ans = 1 for filling jug1 with m
    while(j1 != d && j2 != d){
        int temp = min(j1,n-j2); // pour from jug1 to jug2
        j2 += temp;
        j1 -= temp;
        ans++;
        if(j1 == d || j2 == d) break;
        if(j1 == 0){ // fill jug1
            j1 = m;
            ans++;
        }
        if(j2 == n){ // empty jug2
            j2 = 0;
            ans++;
        }
    }
    return ans;
}
int minSteps(int m, int n, int d){
    if(d%__gcd(m,n) != 0 || d > max(m,n)) return -1;
    return min(solve(m,n,d),solve(n,m,d));
}