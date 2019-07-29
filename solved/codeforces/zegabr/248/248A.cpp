#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




	int n, d, e;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	int k=n;
	while(k--){
		int x,y;
		cin>>x>>y;
		d+=y;
		e+=x;
	}
	d=min(d, n-d);
	e=min(e,n-e);
	cout<<e+d<<pl;
}