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
// acha x e y da equacao:
// a * x + b * y = gcd(a, b);
// x eh inverso modular de a no modulo y
// y eh inverso modular de b no modulo x
ll x,y,d;
void euclides(ll a, ll b) {
	if(b==0){x=1; y=0; d=a; return;}
	euclides(b,a%b);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1; y=y1;

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
ll fexp(ll a, ll b, ll mod) {//O(logb)
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

//===================SIEVE==================
bitset<10000010> prime;
vector<ll> primes;
void sieve (ll n){
	prime.set();
	prime[0]=prime[1]=0;
	for (ll p=2; p<=n;p++) if(prime[p]){
		primes.push_back(i);
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
ll PHI(ll n){//OTHER EULER FUNCTION///////
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


//==========CRT=================
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
inline ll LCM(ll a, ll b) { return a / __gcd(a, b) * b; }
inline ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { ll x, y, d; };
GCD_type ex_GCD(ll a, ll b){
	if (b == 0) return {1, 0, a};
	GCD_type pom = ex_GCD(b, a % b);
	return {pom.y, pom.x - a / b * pom.y, pom.d};
}
int t;
ll a[N], n[N], ans, lcm;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i <= t; i++) cin >> a[i] >> n[i], normalize(a[i], n[i]);
	ans = a[1];
	lcm = n[1];
	for(int i = 2; i <= t; i++)
	{
		auto pom = ex_GCD(lcm, n[i]);
		int x1 = pom.x;
		int d = pom.d;
		if((a[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
		ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
		lcm = LCM(lcm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
	}
	cout << ans << " " << lcm << endl;

	return 0;
}
//////===========================================


//===========PRIMITIVE ROOT=================//requires fexp e PHI()
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
