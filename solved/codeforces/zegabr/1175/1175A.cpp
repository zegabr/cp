#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
#define int ll



main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k>n or k==1){
			cout<<n<<pl;
			continue;
		}
		int ans=0;
		while(n){
			if(n%k==0){
				n/=k;
			ans++;
			}else{
				int r = n%k;
				n-=r;
				ans+=r;
			}
		}
	cout<<ans<<pl;
	}
}
