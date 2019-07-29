#include <bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
#define Y "YES"
#define N "NO"
typedef long long ll;
typedef pair<ll,ll> pll;





int n,t,tans,mincost,minans=1002000000;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(t=1;t<=a[n-1];t++){
		mincost=0;
		for(int i=0;i<n;i++){
			if(a[i]>t) mincost+=abs(a[i]-(t+1));
			else if(a[i]<t) mincost+=abs(a[i]-(t-1));
		}	
		if(mincost<minans){
			minans=mincost; tans=t;
		}	
	
	}
	cout<<tans<<sp<<minans<<pl;




}
