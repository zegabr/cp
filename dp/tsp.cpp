//////TSP///////////////

//int dp[1<<maxn][maxn];
int solve_top_down(int A, int u){
	if(__builtin_popcount(A)==1) return 0;
	int &ans = dp[A][u];
	if(ans!= inf) return ans;
	for(int v = 0; v < n; v++){
		if(u != v and ((A>>v)&1))
			ans = min(ans, solve_top_down(A^(1<<u),v)+ w[v][u]);
	}
	return ans;
}
for(int i=0; i<n;i++) ans = min(ans, solve_top_down((1<<n)-1, i));


//bottom-up
for(int A=0; A<(1<<n); A++){
	for(int v=0; v<n; v++){
		if(((A>>v)&1)==0) continue;
		for(int u=0; u<n; u++){
			if(u==v or !((A>>u)&1)) continue;
			dp[A][u]=min(dp[A][u], dp[A^(1<<u)][v] + w[u][v]);
		}
	}
}
for(int i=0;i<n;i++) ans = min(ans, dp[(1<<n)-1][i]);
