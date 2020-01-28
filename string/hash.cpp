
const ll base = 31;
const ll mod = 1e9+9;

vector<ll> pot;

void buildpot(int maxsize=2000000){//chamar no inicio do main
  pot.resize(maxsize);
  pot[0] = 1;
  for(int i = 1;i < maxsize;i++){
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
  if(isreversed){
    int R=r,L=l;
    r = len(h)-L-1;
    l = len(h)-R-1;
  }
  ll res = h[r];
  if(l>0) res = ((res - pot[r-l+1]*h[l-1])%mod+mod)%mod;
  return res;
}

ll getpref(int m,vector<ll> &h){
  return get(0, m-1, h);
}

ll getsuff(int m, vector<ll> &h){
  return get(len(h)-m, len(h)-1, h);
}

