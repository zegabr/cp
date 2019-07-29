#include<bits/stdc++.h>
using namespace std;
#define sp ' '
#define pl '\n'
typedef long long ll;





int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	priority_queue<int> ma, mi;
	int n,a;
	cin >>n;
	while(n--){
		cin>>a;
		mi.push(-a);
	}
	while(mi.size()>1){
		cout<<-mi.top()<<sp;
		mi.pop();
		ma.push(-mi.top());
		mi.pop();
		
		}
		if(mi.size())cout<<-mi.top()<<sp;
		while(ma.size()){
			cout<<ma.top()<<sp;
			ma.pop();
	}
	
}