#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <cmath>

#define debug 1
#if debug
#endif

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i=a;i<=b;i++)//a..b
#define repb(i, b, a) for(int i=b;i>=a;i--)//b..a
#define fi first
#define se second

#define pl '\n'
#define sp ' '
#define yes "YES\n"
#define no "NO\n"

#define inf INT32_MAX

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> ii;

const ll mod=1e9+7;
const int N=2e5+5;

set<int> g[N];
vector<bool> used(N);
vector<int>ans;

void checklast2(){
	///troca 2 ultimos se houver inconsistencia
	if(g[ans[sz(ans)-2]].count(ans[sz(ans)-1])==0) 
		swap(ans[sz(ans)-2],ans[sz(ans)-1]);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	int n,a,b;
	cin>>n;
	rep(i,1,n){
		cin>>a>>b;
		g[i].insert(a);
		g[i].insert(b);
	}
	ans.pb(1);
	for(int v : g[1]) ans.pb(v);
	checklast2();

	for(int v : ans) used[v]=1;	
	while(sz(ans)<n){
		for(int v : g[ans.back()]){
			if(!used[v]){
				ans.pb(v);
				used[v]=1;
			}	
		}	
		checklast2();			
	}
	for(int v : ans) cout<<v<<sp;
	cout<<pl;		

}
