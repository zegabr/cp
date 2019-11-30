int tsp(int pos, int vis) {
    if (vis+1 == (1<<n)){
			return g[pos][n-1];
    }
		int &ans = dp[pos][vis];
    if (ans != -1) return ans;
    
    int ans = 0x3f3f3f3f;
    
    for(int i=0;i<n;i++) {
        if (!(vis & (1<<i))) {
						ans = min(ans, g[pos][i] + tsp(i, vis|(1<<i)));
        }
    }
    return ans;
}
