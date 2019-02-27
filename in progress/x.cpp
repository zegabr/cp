#include<bits/stdc++.h>
using namespace std;
#define sp ' '
#define pl '\n'
typedef long long ll;

const ll inf = 1e18+10;
const int N =2e7 ;


bool isprime(ll n){//O(sqrt(n))
	ll c=0;
	for(ll i=1; i*i<=n; i++){
		if(n%i==0){
			if(n/i==i)c++; //conta um divisor
			else c+=2; // conta 2 divisores: i  e n/i
		}
	}
	return c==2;
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
	set<ll> divs;//divs of k
	ll d;
	for(ll i=1 ;i*i<=k; i++){
		if(k%i==0LL){
			if(isprime(i+1))divs.insert(i+1);
			d=k/i;
			if(d!= i and isprime(d+1) )divs.insert(d+1);
		}
	}
	int tam=divs.size();
		cout<<tam<<pl;
		return 0;
	vector<ll>primes;
	for(ll p:divs){
		primes.push_back(p);
		//	cout<<p<<sp;
	}
	//cout<<pl;

	ll pnum,pden;
	ll ans = inf;
	int mask;
	for(mask = 1; mask<(1<<tam); mask++){
		pnum=1LL; pden=1LL;
		set<ll> used;
		for(int i=0;i<tam;i++){
			if(mask&(1<<i)){
				//				cout<<primes[i]<<sp;
				used.insert(primes[i]);
				pnum*=primes[i];
				pden*=primes[i]-1;
								if(pden==0LL){//degub
									cout<<pden<<pl;
									cout<<primes[i]<<pl;
									cout<<primes[i]-1<<pl;
									for(ll f : used)cout<<f<<sp;
									cout<<pl;
									return 0;
								}
			}
		}
		//cout<<" ==> ";
		pnum*=k;	
		if(pnum%pden==0LL){
			ll n = pnum/pden;
			ll aux =n;
			for(ll p:used){
				while(aux%p==0LL) aux/=p;
			}
			if(aux==1){

				//cout<<n<<" is a solution"<<pl;
				ans=min(ans,n);
			}
		}
	}
	//testar para todos os subsets de primes se (k*prodP%prodPminus)==0 
	cout<<(ans==inf ? 0 : ans)<<pl;	

}

