//=============MDC(GCD)===================
#define gcd(a,b) __gcd(a,b)

//==========MMC(LCM)================
inline ll lcm(const ll &a, const ll &b) {
	return (a / gcd(a, b)) * b; 
}

//=============DIVISORS================
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

//=========EUCLIDES ESTENDIDmO==============
// acha x e y da equacao:
// a * x + b * y = gcd(a, b);
// x eh inverso modular de a no modulo y
// y eh inverso modular de b no modulo x
//ll xe,ye,de;
void euclides(ll a, ll b, ll &x, ll &y, ll &d) {
	if(b==0){x=1; y=0; d=a; return;}
	euclides(b,a%b,x,y,d);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1; y=y1;

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

//===================SIEVE==================
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