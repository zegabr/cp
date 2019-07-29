#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,a[50010],sum=0LL,maxd=-1,indmaxd,indmin,mini=INT64_MAX,ans;
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]<mini){
			mini=a[i];
			indmin=i;
		}
		sum+=a[i];
	}
ans = sum;
	rep(i,1,n){
		for(ll d=1;d*d<=a[i];d++){
			if(a[i]%d==0){
				int d2=a[i]/d;
				ans = min(ans, sum - a[indmin]-a[i]+a[i]/d+a[indmin]*d);
				ans = min(ans, sum - a[indmin]-a[i]+a[i]/d2+a[indmin]*d2);
					
			}
		}
	}
	cout<<ans<<pl;

}
