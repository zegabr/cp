#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;



ll p,q,qc,r,n;
vector<ll> c;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(cin>>p>>q>>n){
		c.clear();
		vector<ll> a(n);
		for(ll i=0;i<n;i++)cin>>a[i];
		r=10;
		if(a[n-1]==1 and n!=1){
			a[n-2]++;
			a.resize(n-1);
			n--;
		}
		while(r!=0){
			r=p%q;
			qc=p/q;
			//cout<<p<<"="<<q<<"*"<<qc<<"+"<<r<<pl;
			c.push_back(qc);
			p=q;
			q=r;
		}
		/*
		for(ll k:a)cout<<k<<sp;
		cout<<pl;
		for(ll k:c)cout<<k<<sp;
		cout<<pl;
		*/
		bool ok= n==c.size();
		for(ll i=0;i<n and ok;i++){
			ok &= a[i]==c[i];
		}
		if(ok)cout<<"YES"<<pl;
		else cout<<"NO"<<pl;

	}
}
