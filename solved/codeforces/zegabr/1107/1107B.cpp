#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	ll n, i, x;
	cin>>n;
	while(n--){
		cin>>i>>x;
		ll ans = x + (i-1)*9;
		cout<<ans<<pl;
	}

}
