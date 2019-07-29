#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;

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



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		ll v[n];
		for(ll &k : v)cin>>k;
		sort(v,v+n);
		ll ans = v[0]*v[n-1];
		bool vai = 1;
		for(int i=0,j=n-1; i<=j and vai; i++,j--){
				vai &= v[i]*v[j]==ans;
		}
	if(vai and countdiv(ans)-2==n)
		cout<<ans<<pl;
	else cout<<-1<<pl;

	}
}
