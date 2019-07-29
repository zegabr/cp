#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> tp;
char pl='\n';
ll maxn=1e6+3;
vector<bool> prime(maxn,1);
set<ll> tprimes;
void sieve(){
	prime[0]=prime[1]=0;
	ll i,p;
	for(p=2;p*p<maxn;p++){
		if(prime[p]){
			for(i=p<<1;i<maxn;i+=p) 
				prime[i]=0;
		}
	}
	for(ll p=2;p<maxn;p++)if(prime[p])tp.insert(p*p);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	sieve();
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(tp.count(n)) cout<<"YES\n";
		else cout<< "NO\n";
	
	}
	
}

