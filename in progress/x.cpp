#include<bits/stdc++.h>
using namespace std;
#define sp ' '
#define pl '\n'
typedef unsigned long long ll;

const ll inf = 1e18+10;
const ll N =2e7 ;


bool isprime(ll n){//O(sqrt(n))
	ll c=0;
	if(n==2) return 1; 
	if(~n&1 or n==1) return 0;
	for(ll i=3; i*i<=n; i+=2){
		if(n%i==0){
			return 0;
		}

	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	ll k;
	cin>>k;//phi(n)
	if(k==1){
		cout<<1<<pl;
		return 0;
	}else if(k&1){
		cout<<0<<pl;
		return 0;
	}
	set<ll> primesaux;//primes p such p-1 | k
	ll d;
	for(ll i=1 ;i*i<=k; i++){
		if(k%i==0LL){
			if(isprime(i+1))primesaux.insert(i+1);
			d=k/i;
			if(d!=i and isprime(d+1) )primesaux.insert(d+1);
		}
	}
	vector<ll>primes;
	for(ll a : primesaux)primes.push_back(a);
	ll tam=primes.size();
	cout<<tam<<pl;
	ll pnum,pden;
	ll ans = inf;
	ll mask;
	ll aux;
	bool ok;
	for(mask = 1; mask<(1<<tam); mask++){
		pnum=1ll;
		ok=1;
		aux=k;
		set<ll> used;
		for(ll i=0;i<tam and ok;i++){
			if(mask&(1<<i)){
				used.insert(primes[i]);//fatores de n
				pnum*=primes[i];
				if(aux%(primes[i]-1)==0)aux/=(primes[i]-1);
				else ok=0;

			}
		}
		ll aux2=aux;
		for(ll i=2 ;i*i<=aux2 and ok; i++){
			if(k%i==0LL){
				if(used.count(i)==0)ok=0;
				while(aux2%i==0LL and ok)aux2/=i;
			}
		}
		if(aux2>1 and used.count(aux2)==0)ok=0;//aux2 é primo

		if(ok){
			ll n = aux*pnum;

			//cout<<n<<" is a solution"<<pl;
			ans=min(ans,n);
		}


	}
	//testar para todos os subsets de primes se (k*prodP%prodPminus)==0 
	cout<<(ans==inf ? 0 : ans)<<pl;	

}

