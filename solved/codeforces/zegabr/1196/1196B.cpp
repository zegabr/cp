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
#define popcount(a) __builtin_popcountll((long long)a)
#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll
#define yes "YES"
#define no "NO"

main(){
 	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		vector<int> ans;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]=a[i]&1;
			//cout<<a[i]<<' ';
			if(a[i])ans.pb(i+1);
		}
		if((int)ans.size()-k<0 or (ans.size()-k)&1){
			cout<<no<<endl;
			continue;
		}
		
		ans.resize(k);
		ans[k-1]=n;
		cout<<yes<<endl;
		for(int i=0;i<k;i++)cout<<ans[i]<<' ';
		cout<<endl;
	
		
		
		
		
	}
	
	
	

}
