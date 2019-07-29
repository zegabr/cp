#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
#define int ll

bool serve(ll n){
	int ans = 0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	return ans%4==0;
}

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	while(!serve(n)){
		n++;
	//	cout<<n<<sp<<(n%9)<<pl;
	}

	cout<<n;
}
