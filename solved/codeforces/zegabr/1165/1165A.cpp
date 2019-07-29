#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s; 
	int n, x,y; cin>>n>>x>>y;
	cin>>s;

	s = s.substr(n-x);
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(i!=s.size()-1-y){
			ans+= s[i]=='1';
		}else{
			ans+= s[i]=='0';
		}
	}

	cout<<ans<<pl;
}
