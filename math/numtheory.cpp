//////////////DIVISORES////////
ll countdiv(ll n){
	ll c=0, k=sqrt(n);
	for(ll i=1; i<=k; i++){
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

////////////FAST EXPONENTIATION//////
ll fexp(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

//////////SIEVE////////
vector<bool> prime(N, 1);
void sieve (ll n){
	for (ll p=2; p*p<=n;p++){
		if(prime[p]){
			for(ll i=p*2; i<=n; i+=p)
				prime[i]=0; 
		}
	}    
}

////////////EULER FUNCTION WITH PRIME FACTORS////////////////
vector<int> fators[N], phi(N);
void PHI(){//get prime factors and calculate phi
	for(int i=2;i<N;i++){//O(N)
		phi[i]=i;
		if(fators[i].size()) continue;

		//i is prime
		for(int j = i+i; j<N;j+=i){//O(logN)
			fators[j].push_back(i);
		}
	}

	for(int i=2;i<N;i++){//O(N)
		if(fators[i].empty()){//i is prime
			fators[i].push_back(i);		
			phi[i]=i-1;
			continue;
		}
		for(int pi : fators[i]){//O(logN)
			phi[i]=(phi[i]/pi)*(pi-1);
		}
	}

}

////////////OTHER EULER FUNCTION/////////
vector<ll> phi(N);
void PHI(){//get prime factors and calculate phi
	for(ll i=1;i<N;i++)phi[i]=i;
	for(ll i=2;i<N;i++){//O(N)
		if(phi[i]==i){//n is prime
			for(ll j=i;j<N;j+=i){//O(logN)
				//i is a prime factor of j
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
