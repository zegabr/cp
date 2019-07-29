#include<stack>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; typedef long long ll;
#define sp ' '
#define pl '\n'
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
const int N = 5 + 1e5 * 3;
const int mod = 1e9+7;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	int ans = 0;
	stack<char> st;
	for(char c : s){
		if(st.empty()) st.push(c);
		else if(st.top()==c) st.pop(), ans++;
		else st.push(c);
	}
	if(ans&1) cout<<"Yes"<<pl;
	else cout<<"No"<<pl;
}
