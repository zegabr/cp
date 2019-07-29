#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int v[n];

	for(int &val : v)cin>>val;
	sort(v,v+n);

	int ans=0;
	int k=1;
	
	for(int i=0;i<n;i++){
		while(i<n and k>v[i])i++;
		if(i<n)ans++, k++;
	}


	cout<<ans<<pl;
}
