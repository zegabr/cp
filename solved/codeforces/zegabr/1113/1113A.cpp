#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,v,m;
	cin>>n>>v;
	m=v;
	for(int i=2;i<=n-v;i++)m+=i;
	if(n-1==v)m=v;
	else if (v>n-1)m=n-1;
	cout<<m<<pl;
	

}
