//=============MDC(GCD)===================
#define gcd __gcd

//==========MMC(LCM)================
inline ll lcm(const ll &a, const ll &b) {
	return (a / gcd(a, b)) * b; 
}

//===================SIEVE==================
const int P = 2e7+5;
vector<bool> prime;
vector<ll> primes;

void sieve (){
	prime.assign(P+1,1);
	prime[0]=prime[1]=0;
	for (ll p=2; p<=P;p++) if(prime[p]){
		primes.push_back(p);
		for(ll i=p*p; i<=P; i+=p)
			prime[i]=0; 
	}
}

//==============IS PRIME===============
bool isPrime(ll n){
	if(n<prime.size()) return prime[n];
	for(int i=0;i<primes.size();i++) if(n%primes[i]==0) return 0;
	return 1;
}

//===============FAST EXPONENTIATION=================
ll fexp(ll a, ll b, ll mod) {//O(logb)
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

//===========MULTIPLICATIVE INVERSE=================
ll invmod(ll a, ll mod){//mod has to be prime
	return fexp(a,mod-2,mod);
}

//================EULER FUNCTION ===============
vector<ll> phi(P+1);
void PHI(){//get prime factors and calculate phi
	for(ll i=1;i<P;i++)phi[i]=i;
	for(ll i=2;i<P;i++){//O(N)
		if(phi[i]==i){//n is prime
			for(ll j=i;j<P;j+=i){//O(logi)
				//i is a prime factor of j
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}

ll PHI(ll n){//OTHER EULER FUNCTION///////calculates one phi
	ll ans = n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans-=ans/i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1){//n is prime
		ans-=ans/n;
	}	
	return ans;
}

//===========PRIMITIVE ROOT=================
int generator (int p) {//find a primitive root modulo p
	//talvez seja interessante fazer uma condicional aqui pra saber se o p tem raíz primitiva
	vector<int> fact;
	int tot = PHI(p),  n = tot;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);//fatores de phi
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);


	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (int i=0; i<fact.size() && ok; ++i)
			ok &= fexp (res, tot / fact[i], p) != 1;
		if (ok)  return res;//primitive root
	}
	return -1;//there is none
}
//=================raízes primitivas=======================
// 	ord(a,m) = menor inteiro positivo tal que a^k==1modm
//  ord(a,m)|phi(m) //ordem de a mod m divide phi(m)
// 	se ord(a,m)==phi(m) , a é raíz primitiva
// 	gcd(a,m) tem q ser 1 para a possuir ordem modulo m
// 	se k=ord(a,m), ord(a^t,m)=k/gcd(k,t);//logo se a for raíz primitiva, vc consegue ordem de qualquer potencia dele, logo de qualquer nmero q possui ordem
// 	um número tem raíz primitiva se for da forma 2,4,p^k ou 2p^k com k inteiro positivo e p PRIMO ÍMPAR
//====================================================

//===============DISCRETE ROOT========================
#define mp make_pair
vector<int> droot(int k,int a,int n){//find x where x^k==a mod n
	if(a==0){
		//0 is the only solution
		vector<int> ans={0};
		return ans;
	}

	int g = generator(n);

	//baby-step giant-step discrete log algorithm
	int sq = (int)sqrt(n+.0)+1;
	vector<pair<int,int>> dec(sq);
	for(int i=1;i<=sq;i++)
		dec[i-1] = {fexp(g, i*sq*k%(n-1), n), i};
	sort(dec.begin(), dec.end());
	int any_ans=-1;
	for(int i=0;i<sq;i++){
		int my = fexp(g,i*k%(n-1),n)*a%n;
		auto it = lower_bound(dec.begin(),dec.end(), mp(my, 0));
		if(it != dec.end() and it->first == my){
			any_ans = it->second*sq -i;
			break;
		}
	}	
	if(any_ans == -1){
		vector<int> ans;//no solutions
		return ans;
	}

	int delta = (n-1)/gcd(k,n-1);
	vector<int>ans;
	for(int cur=any_ans%delta; cur< n-1;cur+=delta)
		ans.push_back(fexp(g,cur,n));
	sort(ans.begin(),ans.end());
	return ans;
}
//===================================================
//===========DISCRETE LOG==========================
int dlog(int a, int b, int m){//find x where a^x = b mod m, with a and m co-prime
	int n = (int)sqrt(m+ .0) + 1;
	int an = 1;
	for(int i = 0; i < n; i++)
		an = an * a % m;

	map<int,int> vals;
	for(int p = 1, cur = an; p <= n; p++){
		if(!vals.count(cur)) vals[cur] = p;
		cur = cur * an % m;
	}

	for(int q = 0, cur = b; q <= n; q++){
		if(vals.count(cur)){
			int ans = vals[cur] * n - q;
			return ans;
		}
		cur = cur * a % m;
	}
	return -1;

}
//================================================
