string a,b;
int dp[1010][1010];

void init(){
  memset(dp, -1, sizeof dp);
}

int lcs(int i, int j){
  if(i==-1 or j==-1) return 0;

  int &res = dp[i][j];
  if(res!=-1) return res;

  if(a[i]==b[j]){
    res = max({res, 1+lcs(i-1,j-1)});
  }else{
    res = max({res, lcs(i,j-1), lcs(i-1,j)});
  }

  return res;
}
