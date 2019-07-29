#define debug 
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <complex>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


#define sc1(a) scanf("%d", &(a))
#define sc2(a,b) scanf("%d%d", &(a),&(b))
#define sc3(a,b,c) scanf("%d%d%d", &(a),&(b),&(c))
#define pri(a) printf("%d\n",(a))

#define endl '\n'
#define x first
#define y second
#define pb push_back
#define sz(x) (int)(x).size()
#define fauto(k,c) for(auto &k : c)
#define all(k) (k).begin(),(k).end()
#define rall(k) (k).rbegin(),(k).rend()
#define db(k) cerr << #k<< " = " << k << endl
#define popcount(a) __builtin_popcountll((long long)a)
#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll
const int mx=222222;
vector<string> s(mx);
string r,g,b,oi="RGB";
int t,kk[mx];

int getmin(string &p, string &t,int &k){
	int ans = k;
	int c=0;
	int i=0;
	while(i<k){
		c+=p[i]!=t[i];
		i++;
		//db(c);
	}
	i--;
	//db(i);
	//db(p);db(t);
	ans = min(ans,c);
	while(i<p.size()-1){
		c+=p[i+1]!=t[i+1];
		c-=p[i-k+1]!=t[i-k+1];
		ans = min(ans,c);
		i++;
		//		db(c);
	}

	return ans;
}


int solve(string &p, int &k){
	int ans[] = {getmin(p,r,k),getmin(p,g,k),getmin(p,b,k)};
	return *min_element(ans,ans+3);
}

main(){
 	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>kk[i]>>kk[i]>>s[i];
	}
	
	int bigg=mx;
	int ri=0,gi=1,bi=2;
	while(bigg--){
		r.pb(oi[ri]);
		g.pb(oi[gi]);
		b.pb(oi[bi]);
		ri++; ri%=3;
		gi++; gi%=3;
		bi++; bi%=3;
	}
	
	for(int i=0;i<t;i++){
		//db(s[i]);db(kk[i]);
		cout<<solve(s[i],kk[i])<<endl;
	}
}
