#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';

vector<pair<int,int>> v;
int a,b,i,n;
bool ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i =0;i<n;i++){
		cin>>a>>b;
		v.push_back({a,b});
	}	
	sort(v.begin(),v.end());
	ans=0;
	for(i=0;i<n-1 and !ans;i++){
		ans|=(v[i].first<v[i+1].first and v[i].second>v[i+1].second);
	}	
	if(ans)cout<<"Happy Alex"<<pl;
	else cout<<"Poor Alex"<<pl;


}