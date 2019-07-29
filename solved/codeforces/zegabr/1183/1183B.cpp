#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
#define int ll



main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k,t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int a[n];
		for(int &v : a){
			cin>>v;
		}
		sort(a,a+n);
		int ans = k+a[0];
		if((int)abs(ans-a[n-1])>k)cout<<-1<<pl;
		else cout<< ans<< pl;

	}
}
