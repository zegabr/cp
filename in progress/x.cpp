#include<bits/stdc++.h>
using namespace std;
#define sp ' '
#define pl '\n'
typedef unsigned long long ll;

const ll inf = 1e18+10;
const ll N =2e7 ;


bool isprime(const ll &n){//O(sqrt(n))
	ll c=0;
	if(n==2) return 1;//2 é nao otimo nesta questao
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
	ll k,upp,d1,d2;
	cin>>k;
	if(k==1 or k==2){
		cout<<1<<pl;
		return 0;
	}
	if(k&1){
		cout<<0<<pl;
		return 0;
	}
	if(isprime(k+1)){
		cout<<k+1<<pl;
		return 0;
	}

	vector<ll> divs;// divs of k = phi(n)
	for(int i=1;i*i<=k;i++){
		if(k%i==0){
			d1=i, d2=k/i;
			if(isprime(d1+1)) divs.push_back(d1);
			if(d1!=d2 and isprime(d2+1)) divs.push_back(d2);
		}
	}
	sort(divs.begin(),divs.end());

	cout<<"divisors of k are ";
	for(ll v : divs) cout<<v<<sp;
	cout<<pl;


	ll n=1,ans=inf,p,k2=k;
	for(int i=0;i<divs.size();i++){
		n=1,k2=k;
		for(int j=i;j<divs.size();j++){		
			p=divs[j]+1;
			n*=p;
			
			while(k2%(p)==0){
				k2/=p;
				n*=p;
			}
		}
		if(n>k) ans = min(n,ans);
	}
	if(ans!=inf)cout<<ans<<pl;
	else cout<<0<<pl;
	
	




}
