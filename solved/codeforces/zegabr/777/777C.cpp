#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
int main(){
int n,m,k,r,l,i,j;
	cin>>n>>m;
	int t[n+1][m+1], dp[n+1][m+1], dp2[n+1];
	for(i=1;i<=n;i++){
		dp2[i]=0;
		
		for(j=1;j<=m;j++){
			cin>>t[i][j];
			if(i==1) dp[i][j]=1;//base
			else if(t[i][j]>=t[i-1][j]) dp[i][j]=dp[i-1][j]+1;//ordenado
			else dp[i][j]=1;//nao ordenado a partir daqui
		
			dp2[i] = max(dp2[i], dp[i][j]);
		}
	}
	
	
	cin>>k;
	while(k--){
		cin>>l>>r;
	
		l=r-l+1;//tamanho do range

		if(dp2[r]>=l)cout<<"Yes\n";
		else cout<<"No\n";
	}
}