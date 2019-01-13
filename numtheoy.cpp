typedef long long ll;
typedef pair <ll,ll> pll;

//////////////CONTA DIVISORES////////
int countdiv(int n){
	int c=0, k=sqrt(n);
	for(int i=1; i<=k; i++){
		if(n%i==0){
			if(n/i==i)c++; //conta um divisor
			else c+=2; // conta 2 divisores: i  e n/i
		}
	}
	return c;
}

/////EUCLIDES ESTENDIDO//////////
pll euclides(ll a, ll b) {
	// acha u e v da equacao:
	// u * x + v * y = gcd(x, y);
	// u eh inverso modular de x no modulo y
	// v eh inverso modular de y no modulo x
	ll u = 0, oldu = 1, v = 1, oldv = 0;
	while(b) {
		ll q = a / b;
		oldv = oldv - v * q;
		oldu = oldu - u * q;
		a = a - b * q;
		swap(a, b);
		swap(u, oldu);
		swap(v, oldv);
	}
	return pll(oldu, oldv);
}

/////////////MDC//////////////
ll mdc(ll a, ll b) {
	while(b) a %= b, swap(a, b);
	return a;
}

//////////MMC//////////////////////
inline ll mmc(const ll &a, const ll &b) {
	return (a / mdc(a, b)) * b; 
}

//////////SIEVE////////
vector<bool> prime(maxn, 1);

void sieve (int n){
	for (int p=2; p*p<=n;p++){
		if(prime[p]){
			for(int i=p*2; i<=n; i+=p)
				prime[i]=0; 
		}
	}    
}

////////////FAST EXPONENTIATION//////
const ll mod = 1e9+7;

ll fexp(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
