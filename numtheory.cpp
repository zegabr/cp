//=============DIVISORES================
ll countdiv(ll n){//O(sqrt(n))
	ll c=0;
	for(ll i=1; i*i<=n; i++){
		if(n%i==0){
			if(n/i==i)c++; //conta um divisor
			else c+=2; // conta 2 divisores: i  e n/i
		}
	}
	return c;
}

//=========EUCLIDES ESTENDIDO==============
//typedef<pair<ll,ll>> pll;
// acha u e v da equacao:
// u * x + v * y = gcd(x, y);
// u eh inverso modular de x no modulo y
// v eh inverso modular de y no modulo x
pll euclides(ll a, ll b) {//O()
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

//==============MDC===================
ll mdc(ll a, ll b) {
	while(b) a %= b, swap(a, b);
	return a;
}

//================MMC==================
inline ll mmc(const ll &a, const ll &b) {
	return (a / mdc(a, b)) * b; 
}

//===============FAST EXPONENTIATION=================
ll fexp(ll a, ll b) {//O(logb)
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

//===================SIEVE==================
vector<bool> prime(N, 1);
void sieve (ll n){//O(nloglogn)
	for (ll p=2; p<=n;p++){
		if(prime[p]){
			for(ll i=p*p; i<=n; i+=p)
				prime[i]=0; 
		}
	}    
}

//================EULER FUNCTION ===============
vector<ll> phi(N);
void PHI(){//get prime factors and calculate phi
	for(ll i=1;i<N;i++)phi[i]=i;
	for(ll i=2;i<N;i++){//O(N)
		if(phi[i]==i){//n is prime
			for(ll j=i;j<N;j+=i){//O(logi)
				//i is a prime factor of j
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
ll PHI(ll n){//OTHER EULER FUNCTION///////
	ll ans = n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans*=i-1;
			ans/=i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1){//n is prime
		ans*=n-1;
		ans/=n;
	}	
	return ans;
}
