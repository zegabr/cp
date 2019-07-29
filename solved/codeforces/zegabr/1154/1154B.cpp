#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	bool zero = 1;
	for(int i=1;i<n and zero;i++) zero&= a[i]==a[i-1];
	if(zero){
		cout<<0<<pl;
		return 0;
	}
	for(int d=1;d<=100;d++){
		map<int,int> freq;
		for(auto v : a){
		 freq[v]++;
		 freq[v-d]++;
		 freq[v+d]++;
		}
		for(auto p : freq){
			if(p.second==n){
				cout<<d<<pl;
				return 0;
			}
		}
	}
	cout<<-1<<pl;
}
