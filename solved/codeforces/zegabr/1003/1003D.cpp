#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
#define fi first
#define se second
#define mod(X) (X)%MOD
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
using namespace std; typedef long long ll;
const int N = 5 + 1e5 * 3;
const int MOD = 1e9+7;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q;
	cin>>n>>q;
	unordered_map<int,int>m;
	vector<int> v;
	while(n--){
		int a; cin>>a;
		if(!m[a])v.push_back(a);
		m[a]++;
	}
	sort(v.rbegin(),v.rend());
		
	while(q--){
		cin>>n;
		int ans=0;
		for(int i=0;n and i<v.size();i++){
			int a=v[i];
			int c=min(n/a, m[a]);
			n-=c*a;
			ans+=c;
		}
		if(n) cout<<-1<<pl;
		else cout<<ans<<pl;
	
	}		
		
}
