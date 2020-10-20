
//requires fexp.cpp
bool overflow(long long a, long long b) {
  return b && (a >= (1long long << 62) / b);
}

long long add(long long a, long long b, long long mod) {
  return (a + b) % mod;
}

long long mul(long long a, long long b, long long mod) {
  if (!overflow(a, b)) return (a * b) % mod;
  long long ans = 0;
  while(b) {
    if (b & 1) ans = add(ans, a, mod);
    a = add(a, a, mod);
    b >>= 1;
  }
  return ans;
}

long long my_rand() {
  long long ans = rand();
  ans = (ans << 31) | rand();
  return ans;
}

bool miller(long long p, int precision) {//check primality
  if(p < 2) return 0;
  if(p % 2 == 0) return (p == 2);
  long long s = p - 1;
  while(s % 2 == 0) s >>= 1;
  for(int i = 0; i < precision; i++) {
    long long a = rand() % (p - 1) + 1, temp = s;
    long long mod = fexp(a, temp, p);
    while(temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mul(mod, mod, p);
      temp <<= 1;
    }
    if(mod != p - 1 && temp % 2 == 0) return 0;
  }
  return 1;
}

long long rho(long long n) {//find a prime factor
  if (n == 1 || miller(n, 10)) return n;
  if (n % 2 == 0) return 2;
  while(1) {
    long long x = my_rand() % (n - 2) + 2, y = x;
    long long c = 0, cur = 1;
    while(c == 0) {
      c = my_rand() % (n - 2) + 1;
    }
    while(cur == 1) {
      x = add(mul(x, x, n), c, n);
      y = add(mul(y, y, n), c, n);
      y = add(mul(y, y, n), c, n);
      cur = __gcd((x >= y ? x - y : y - x), n);
    }
    if (cur != n) return cur;
  }
}
