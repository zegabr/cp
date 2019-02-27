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

//debug
/*
	ll arr[]={2, 4 ,10 ,16 ,40, 100, 250 ,256 ,400 ,640 ,1600, 16000, 25600};
	ll to=1;
	for(int v : arr) to*=v;
	cout<<to<<pl;
*/
	ll teste = 14195346025471803392;
	ll opa = 160000;
	ll bug = teste*opa;
	cout<<bug<<pl;
	return 0;

//debug



	ll k;
	cin>>k;//phi(n)
	if(k==1){
		cout<<1<<pl;
		return 0;
	}else if(k&1){
		cout<<0<<pl;
		return 0;
	}
	vector<ll> primes;//primes of k
	ll d;
	for(ll i=1 ;i*i<=k; i++){
		if(k%i==0LL){
			if(isprime(i+1))primes.push_back(i+1);
			d=k/i;
			if(d!=i and isprime(d+1) )primes.push_back(d+1);
		}
	}
	ll tam=primes.size();
	//cout<<tam<<pl;
	sort(primes.begin(),primes.end());
	ll pnum,pden;
	ll ans = inf;
	ll mask;
	for(mask = 1; mask<(1<<tam); mask++){
		pnum=1ull; pden=1ull;
		set<ll> used;
		for(ll i=0;i<tam;i++){
			if(mask&(1<<i)){
				//				cout<<primes[i]<<sp;
				used.insert(primes[i]);
				pnum*=primes[i];
				pden*=primes[i]-1;
				//cout<<pden<<pl;
								if(pden==0ULL){//degub
									cout<<i<<pl;
									cout<<pden<<pl;
									cout<<primes[i]<<pl;
									cout<<primes[i]-1<<pl;
									for(ll f : used)cout<<f-1<<sp;
									cout<<pl;
									return 0;
								}
			}
		}
		//cout<<" ==> ";
		pnum*=k;	
		if(pnum%pden==0ULL){
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

