
int c[ms], j[ms];
int dp[ms][ms];

int mm(int i, int j){
	if(i==j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	int resp = 0x3f3f3f3f;
	
	for(int k=i;k<j;j++)
		resp = min(resp, mm(i,k)+mm(k+1,j) + l[i]*c[k]*c[j]);
	
	return dp[i][j] = resp;
}
