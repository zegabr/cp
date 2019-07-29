#include <bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
#define Y "YES"
#define N "NO"
typedef long long ll;
typedef pair<ll,ll> pll;



vector<int> v(200010,1);



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	int i,j,ans;
	i=j=0;
	ans=1;
	for(i=0;i<n;i++){
		j=i;
		while(j+1<n and a[j+1]<=2*a[j]) j++;
		ans=max(ans,j-i+1);
		i=j;
	
	}
	cout<<ans<<pl;





}
