
#define gdc __gcd

bool overflow(ll a, ll b) {
  return b && (a >= (1ll << 62) / b);
}

ll add(ll a, ll b, ll mod) {
  return (a + b) % mod;
}

ll mul(ll a, ll b, ll mod) {
  if (!overflow(a, b)) return (a * b) % mod;
  ll ans = 0;
  while(b) {
    if (b & 1) ans = add(ans, a, mod);
    a = add(a, a, mod);
    b >>= 1;
  }
  return ans;
}

ll my_rand() {
  ll ans = rand();
  ans = (ans << 31) | rand();
  return ans;
}

bool miller(ll p, int precision) {
  if(p < 2) return 0;
  if(p % 2 == 0) return (p == 2);
  ll s = p - 1;
  while(s % 2 == 0) s >>= 1;
  for(int i = 0; i < precision; i++) {
    ll a = rand() % (p - 1) + 1, temp = s;
    ll mod = fexp(a, temp, p);
    while(temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mul(mod, mod, p);
      temp <<= 1;
    }
    if(mod != p - 1 && temp % 2 == 0) return 0;
  }
  return 1;
}

ll rho(ll n) {
  if (n == 1 || miller(n, 10)) return n;
  if (n % 2 == 0) return 2;
  while(1) {
    ll x = my_rand() % (n - 2) + 2, y = x;
    ll c = 0, cur = 1;
    while(c == 0) {
      c = my_rand() % (n - 2) + 1;
    }
    while(cur == 1) {
      x = add(mul(x, x, n), c, n);
      y = add(mul(y, y, n), c, n);
      y = add(mul(y, y, n), c, n);
      cur = gcd((x >= y ? x - y : y - x), n);
    }
    if (cur != n) return cur;
  }
}
