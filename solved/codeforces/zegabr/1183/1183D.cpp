#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
//#define int ll


unordered_map<int,int> f;
set<int> used;
priority_queue<int> pq;

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		while(pq.size())pq.pop();
		int n; cin>>n;
		f.clear();
		while(n--){
			int v; cin>>v;
			f[v]++;
		}
		for(auto &p : f){
			pq.push(p.second);
		}
		int ans=0;
		int d;
		used.clear();
		while(pq.size() and d){
			auto  p = pq.top();
			pq.pop();
			d=p;
			while(d>0 and used.count(d) ) d--;
			ans+=d;
			if(d==0)break;
			used.insert(d);			
		}
		cout<<ans<<endl;
	}	
}
