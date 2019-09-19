int maxsubarraysum(vector<int> %a){
	int ans = -inf;
	vector<int> dp(inf,0);
	for(int i=1;i<a.size();i++){
		cin>>a[i];
		dp[i]=max(a[i],dp[i-1]+a[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}
