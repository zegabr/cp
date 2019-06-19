//==========MAX SUBARRAY SUM============
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


//==================LIS (nlogn)==========
int ceilindex(vector<int> &v,vector<int> &T, int l, int r, int key){
	while(r-l > 1){
		int m = l + (r-l)/2;
		if(v[T[m]]>=key) r=m;
		else l=m;
	}
	return r;
}
vector<int> LIS(vector<int> &v){
	vector<int> ans;
	if(v.size()==0) return ans;
	vector<int> tail(v.size(),0);
	vector<int> prev(v.size(),-1);
	int len = 1;
	for(int i=1;i<v.size();i++){
		if(v[i] < v[tail[0]]) tail[0]=i;
		else if(v[i] > v[tail[len-1]]){
			prev[i] = tail[len-1];
			tail[len++] = i;
		}else{
			int pos = ceilindex(v,tail, -1, len-1 , v[i]);
			prev[i] = tail[pos-1];
			tail[pos]=i;
		}
	}
	for(int i=tail[len-1]; i>=0; i=prev[i])ans.push_back(v[i]);
	reverse(ans.begin(),ans.end());
	return ans;
}
///////EGGDROP ITERATIVO//////////////


//////TSP///////////////
