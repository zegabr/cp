#include <bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
priority_queue<int> pq;
int n,a1,a2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(10);
	cin>>n;
	while(n--){
		cin>>a1;
		pq.push(-a1);
	}
	int c=0;
	while(pq.size()){
		a1=-pq.top(); pq.pop();
		a2=-pq.top(); pq.pop();
		c+=a2-a1;
		
	}
	
	
	
	cout<<c<<pl;
    return 0;
}

