//////MAX SUBARRAY SUM//////
//int dp[maxn],a[maxn],ans=-maxn;
int maxsubarraysum(int n){
	dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=max(a[i],dp[i-1]+a[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

///////EGGDROP ITERATIVO//////////////


//////TSP///////////////
