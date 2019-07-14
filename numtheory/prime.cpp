//====================================================
//===================SIEVE==================
#include<bitset>
const int P = 2e7+5;
bitset<P+1> prime;
vector<ll> primes;

void sieve (ll n){
	prime.set();
	prime[0]=prime[1]=0;
	for (ll p=2; p<=n;p++) if(prime[p]){
		primes.push_back(p);
		for(ll i=p*p; i<=n; i+=p)
			prime[i]=0; 
	}

}

//==============IS PRIME===============
bool isPrime(ll n){
	if(n<prime.size()) return prime[n];
	for(int i=0;i<primes.size();i++) if(n%primes[i]==0) return 0;
	return 1;
}
//====================================================