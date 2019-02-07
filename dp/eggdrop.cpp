///////EGGDROP ITERATIVO//////////////

//int dp[N][N];
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