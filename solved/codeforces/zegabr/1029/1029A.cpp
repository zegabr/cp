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

/////////////Z-ALGORITHM////
//z[i] is the length of the biggest prefix of s, beggining from position i
//z[0] is by definition s.size(), however never used, so leaving zero there is the best option
//to search for a pattern p in a text t, run zfunc(p+'¨'+t), so p will be prefix
vector<int> zfunc(const string &s){
	int n = s.size();
	vector<int> z(n);
	for(int i=1, l=0, r=0; i<n; i++){
		if(i<=r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;//z-array
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int> z = zfunc(s);
	int i;
	for( i=1;i<n and z[i]+i!=n;i++);
	
	if(z[i]+i!=n){
		while(k--) cout<<s;
		cout<<pl;
	}else{
		cout<<s;
		k--;
		while(k--)cout<<s.substr(z[i]);
		cout<<pl;
	
	}
		
}
