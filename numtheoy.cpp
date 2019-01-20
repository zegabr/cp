typedef long long ll;
typedef pair <ll,ll> pll;

//////////////CONTA DIVISORES////////
template <class T>
T countdiv(T n){
	T c=0, k=sqrt(n);
	for(T i=1; i<=k; i++){
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
template <class T>
T mdc(T a, T b) {
	while(b) a %= b, swap(a, b);
	return a;
}

//////////MMC//////////////////////
template<class T>
inline T mmc(const T &a, const T &b) {
	return (a / mdc(a, b)) * b; 
}

//////////SIEVE////////
vector<bool> prime(N, 1);
template<class T>
void sieve (T n){
	for (T p=2; p*p<=n;p++){
		if(prime[p]){
			for(T i=p*2; i<=n; i+=p)
				prime[i]=0; 
		}
	}    
}

////////////FAST EXPONENTIATION//////
template<class T>
T fexp(T a, T b) {
	T ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
