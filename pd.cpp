///////EGGDROP ITERATIVO//////////////
dp[N][N];
eggdrop(int n, int k){
	int res, i, j, k;
	for(i=1;i<=n;i++){
		dp[i][1]=1;
		dp[i][0]=0;
	}
	for(j=1;j<=k;j++)dp[i][j]=j;
	for(i=2;i<=n;i++){
		for(j=2;j<=k;j++){
			dp[i][j]=inf;
			for(x=1;x<=j;x++){
				res=1+max(dp[i-1][x-1],dp[i][j-x]);
				dp[i][j]=min(dp[i][j],res);
			}
		}
	}
}

//////MAX SUBARRAY SUM
int dp[maxn],a[maxn], ans = -maxn;
int maxsubarraysum(int n){
	dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=max(a[i],dp[i-1]+a[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

//////TSP///////////////
int dp[1<<maxn][maxn];
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
