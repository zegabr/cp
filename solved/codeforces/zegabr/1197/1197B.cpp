#define debug 
#define yes "YES"
#define no "NO"
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
#define db(k) cerr << #k<< " = " << k << '\n'
#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll


main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//	cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	int n; cin>>n;
	vector<int> a(n);
	uset<int> to;
	fauto(v,a){
		cin>>v;
		to.insert(v);
	}
	if(to.size()!=n){
		cout<<no<<endl;
		return 0;
	}
	int k=0;
	for(int i=1;i<n;i++) if(a[k]<a[i])k=i;
	//	cout<<a[k]<<endl;
	bool y=1;

	int big = a[k];
	queue<int> l,r;
	for(int i=k-1;~i;i--) l.push(a[i]);
	for(int i=k+1;i<n;i++) r.push(a[i]);

	while(l.size() and r.size() and y){
//db(big);
		if(r.front() > l.front()){
			if(r.front() < big){
				big = r.front();
				r.pop();
			}else y=0;
		}else if(l.front()>r.front()){
			if(l.front()<big){
				big = l.front();
				l.pop();
			}else y=0;

		}else y=0;

	}

	while(y and r.size()){
//db(big);
		if(r.front()<big){
			big = r.front();
			r.pop();
		}else y=0;
	}
	while(y and l.size()){
//db(big);
		if(l.front()<big){
			big = l.front();
			l.pop();
		}else y=0;
	}



	cout<<(y? yes:no)<<endl;

}
