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
//#include <random>
//#include <chrono>

#define endl '\n'
#define dif !=
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(k) (k).begin(),(k).end()
#define rall(k) (k).rbegin(),(k).rend()
#define db(k) cerr << #k<< " = " << k << endl
#define popcount(a) __builtin_popcountll((long long)(a))
#define fr(i,a,b) for(int i=a; i<=b; i++) 
#define rf(i,a,b) for(int i=a; i>=b; i--) 
#define fauto(k,c) for(auto &k : c)
#define PI acos(-1)

#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll
using namespace std;


main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	int n; cin>>n;
	int sum=0;
	vector<pair<int,int>> parties,ans;
	fr(i,1,n){
		int v;
		cin>>v;
		parties.pb({v,i});
		sum+=v;
	}
	ans.pb(parties[0]);
	int sum2 = ans[0].x;
	sort(rall(parties));

	for(int i=0;i<parties.size() and sum2<=sum/2 ; i++){
		if(parties[i].x<=ans[0].x/2){
			ans.pb(parties[i]);
			sum2+=parties[i].x;
		}

	}
	if(sum2<=sum/2){
		cout<<0<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	fauto(a,ans) cout<<a.y<<' ';
	cout<<endl;


}
