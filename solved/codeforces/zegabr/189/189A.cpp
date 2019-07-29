#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;


int dp[50000],r[3],n,a,b,c;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>r[0]>>r[1]>>r[2];
	fill(dp+1,dp+n+1,-1);
	dp[0]=0;
	sort(r,r+3);
	a=r[0],b=r[1],c=r[2];
	for(int i=0;i<=n;i++){
	if(dp[i]==-1)continue;
		dp[i+a]=max(dp[i+a],dp[i]+1);
		dp[i+b]=max(dp[i+b],dp[i]+1);
		dp[i+c]=max(dp[i+c],dp[i]+1);
		//cout<<i<<":"<<dp[i]<<pl;
	}//cout<<pl;
	cout<<dp[n]<<pl;

}
