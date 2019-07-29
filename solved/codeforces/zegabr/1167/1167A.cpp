#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>s;
		bool maisigual11=n>=11;
		bool tem8=0;
	int qnumantesde8=0;
		for(char c : s){
			if(c=='8'){
				tem8=1; break;
			}else qnumantesde8++;
		}
		
		if(tem8 and n - qnumantesde8 >= 11) cout<<"YES"<<pl;
		else cout<<"NO"<<pl;

	}
}
