
const int P = 2e7+5;
vector<bool> prime(P+1,1);
vector<ll> primes;

void sieve (){
	prime[0]=prime[1]=0;
	for (ll p=2; p*p<=P;p++) if(prime[p]){
		for(ll i=p*p; i<=P; i+=p)
			prime[i]=0; 
	}
	primes.pb(2);
	for(int i=3;i<=P;i+=2)
		if(prime[i])
			primes.push_back(i);
}

bool isprime(ll n){
	if(n<prime.size()) return prime[n];
	for(ll &p:primes){
		if(p*p>n) break;
		if(n%p==0) return 0;
	}
	return 1;
}

