#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
#define fi first
#define se second
#define mod(X) (X)%MOD
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
using namespace std; typedef long long ll;
const int N = 5 + 1e5 * 3;
const int MOD = 1e9+7;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a[]={100,20,10,5,1};
	int n, k=0;
	cin>>n;
	rep(i,0,4){
		if(n>=a[i]){
			k+=n/a[i];
			n=n%a[i];
		}
	}
	cout<<k<<pl;
}
