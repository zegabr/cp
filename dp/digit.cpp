
vector<int> num;
const int digits = 101;
ll dp[digits][digits*9+1][2];//qtd digitos, soma maxima dos digitos, limitado ou nao

void init(){
  memset(dp,-1,sizeof dp);
}

//return sum of digits for all number from 0 to num
ll solve(int pos, int sum, int e){
  if(pos == num.size()){//check property here
    return sum;
  }

  ll &res = dp[pos][sum][e];
  if(res != -1)	return res;

  res = 0;
  int lim = (e == 0) ? num[pos] : 9;

  for(int d = 0; d <= lim; d++){
    res += solve(pos+1, sum+d, (!e and d<lim)?1:e);
  }

  return res;
}

ll solve(){
  return solve(0,0,0);
}
