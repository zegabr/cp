#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	int	ans=0;
	while(	cin>>s){
		stack<char> st;
		ans =0;	
		for(char c : s){
			if(c=='('){
				st.push(c);	
			}else{
				if(st.size()){
					st.pop();
					ans++;
				}


			}
			//	cout<<c<<sp<<co<<pl;
		}
		cout<<2*ans<<pl;
		//cout<<pl;
	}
}
