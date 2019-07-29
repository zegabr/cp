#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;

const int N = 2e5+10;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll ans=0LL,m,n,k;
	cin>>n>>m>>k;
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.rbegin(),v.rend());
	ll max1=v[0],max2=v[1];
	//cout<<max1<<sp<<max2<<pl;
	ll q = m/(k+1); //cout<<q<<pl;
	int r = m%(k+1); //cout<<r<<pl;
	ans+=q*(k*max1 + max2);
	
	ans+=r*max1;
	cout<<ans<<pl;
	
}
