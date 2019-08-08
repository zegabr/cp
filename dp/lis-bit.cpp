const int ms = 20;
int v[] =  {2, ,3,45 ,65,4 ,76, 2};
int bit[ms];
int dp[ms];

void update(int x, int v){
	for(;x<ms;x+=x&-x)
		bit[x] = max(bit[x],v);
}

int get(int x){
	int ans = 0;
	for(;x;x-=x&-x)
		ans = max(bit[x], ans);
}

int lis(int n){
	int ans =0;
	for(int i=0;i<n;i++){
		dp[i] = 1 + get(v[i]);
		update(v[i], dp[i]);
		ans  = max(ans, dp[i]);
	}
	return ans;

}
