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
#define dif !=
#define x first
#define y second
#define pb push_back
#define fauto(k,c) for(auto &k : c)
#define all(k) (k).begin(),(k).end()
#define rall(k) (k).rbegin(),(k).rend()
#define db(k) cerr << #k<< " = " << k << endl
#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll


main(){
 	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	vector<int> a;
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		a.resize(n);
		fauto(v,a) cin>>v;
		sort(rall(a));
		int mn = min(a[0],a[1]);
		int k=0;
		for(int i=2;i<n;i++){
			k++;
		}
		k = min(k,mn-1);
		cout<<k<<endl;
	}
	

}
