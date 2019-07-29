#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std; typedef long long ll;
#define sp ' '
#define pl '\n'
const int N = 5 + 1e5 * 3;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll ans=0,n,k;
	cin>>n>>k;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	string s;
	cin>>s;
	int i=0,j;
	priority_queue<ll> pq;
	while(i<n){
		j=i;
		pq.push(a[i]);
		while(j+1<n and s[j+1]==s[j]){
			j++;
			pq.push(a[j]);
		}
		ll k2=k;
		while(k2-- and pq.size()){
			ans+=pq.top();
			//cout<<pq.top()<<sp;
			pq.pop();
		}
		//cout<<pl;
		while(pq.size())pq.pop();
		i=j+1;	
	}
	cout<<ans<<pl;

}
