#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	ll n, a,b,ans,minans;
	cin>>q;
	while(q--){
		cin>>n>>a>>b;
		if(2*a<=b){
			ans = n*a;
		}else{
			ans = n/2*b + n%2*a;
		}
		cout<<ans<<pl;
	}
}
