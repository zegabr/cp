
const int inf = 0x3f3f3f3f, ms = 11;
int v, g[ms][ms], dp[ms][1<<ms], n;

int tsp(int pos, int vis) {
  if (vis+1 == (1<<n)){
    return g[pos][0];
  }
  if (dp[pos][vis] != -1) return dp[pos][vis];

  dp[pos][vis] = inf;

  for(int i=0;i<n;i++) {
    if (!(vis & (1<<i))) {
      dp[pos][vis] = min(dp[pos][vis], g[pos][i] + tsp(i, vis|(1<<i)));
    }
  }
  return dp[pos][vis];
}

int solve(){
  memset(dp,-1,sizeof dp);
  return tsp(0,0);
}


