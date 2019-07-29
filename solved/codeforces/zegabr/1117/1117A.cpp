#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;

const int N = 2e5+10;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a[N];
	int n;
	cin>>n;
	int maxint=-1;
	for(int i=0;i<n;i++)cin>>a[i], maxint = max(maxint,a[i]);
	int len=1;
	int ans=1, rep, bestrep=a[0];
	
	for(int i = 1;i<n;i++){
		if(a[i]==a[i-1]){
			rep = a[i];
			len++;
		}else{
			len=1;
		}
		if(rep>bestrep or (rep==bestrep and len > ans)){
			bestrep=rep;
			ans=len;
		}
	}
	if(bestrep<maxint)cout<<1<<pl;
	else cout<<ans<<pl;
	
}
