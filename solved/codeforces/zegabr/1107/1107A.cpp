#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;


vector<string> ans;
string s,aux;
int q,currsz,n;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	cin>>q;
	while(q--){
		cin>>n>>s;
		if(n==2){
			if(s[0]>=s[1]){
				cout<<"NO"<<pl;
			}else{
				cout<<"YES"<<pl<<2<<pl<<s[0]<<sp<<s[1]<<pl;
			}
		}else{
			cout<<"YES"<<pl<<2<<pl<<s[0]<<sp<<s.substr(1)<<pl;

		}
	}

}
