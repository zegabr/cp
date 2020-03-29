
#define Hash pair<ll,ull>
const ll base = 137;//cover all ascii values
const ll mod = (1ll<<31)-1ll;
//mod2 = 1<<64

vector<ll> pot1;
vector<ull> pot2;

void buildpot(int maxsize=2000000){//call at beginning of main
  pot1.resize(maxsize);
  pot2.resize(maxsize);
  pot1[0] = pot2[0] = 1;
  for(int i = 1;i < maxsize;i++){
    pot1[i] = (pot1[i-1] * base) % mod;
    pot2[i] = pot2[i-1]*base;
  }   
}

void build(string &s, vector<ll> &h, vector<ull> &h2){
  int n = len(s);
  h.resize(n);
  h2.resize(n);
  h[0] = h2[0] = s[0];
  for(int i = 1;i < n;i++){
    h[i] = ((h[i-1] * base) + s[i]) % mod;
    h2[i] = h2[i-1] * base + s[i];
  }
}

//hash function is a double hash
Hash get(int l, int r, vector<ll> &h, vector<ull> &h2, bool isreversed=0){
  if(isreversed){
    int R=r,L=l;
    r = len(h)-L-1;
    l = len(h)-R-1;
  }
  ll res1 = h[r];
  ull res2 = h2[r];
  if(l>0){
    res1 = ((res1 - pot1[r-l+1]*h[l-1]%mod)+mod)%mod;
    res2 = res2 - pot2[r-l+1] * h2[l-1];
  } 
  return Hash(res1,res2);
}

Hash getpref(int m,vector<ll> &h, vector<ull> &h2){
  return get(0,m-1,h,h2);
}

Hash getsuff(int m, vector<ll> &h, vector<ull> &h2){
  return get(len(h)-m,len(h)-1,h,h2);
}

