
const ll base = 31;
const ll mod = 1e9+9;

vector<ll> pot;
string s, rev, t;

void buildpot(int strsize){//chamar antes de build
  pot.resize(strsize);
  pot[0] = 1;
  for(int i = 1;i < strsize;i++){
    pot[i] = (pot[i-1] * base) % mod;
  }   
}

vector<ll> build(string &s){
  int n = len(s);
  vector<ll> h(n);
  h[0] = s[0];
  for(int i = 1;i < n;i++){
    h[i] = ((h[i-1] * base) + s[i]) % mod;
  }
  return h;
}

ll get(int l, int r, vector<ll> &h, bool isreversed=0){
  ll res = h[r];

  if(isreversed){
    r = len(h)-r-1;
    l = len(h)-l-1;
  }

  if(l>0) res = ((res - pot[r-l+1]*h[l-1])%mod+mod)%mod;
  return res;
}


