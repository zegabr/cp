#include<bits/stdc++.h>

#define sp ' '

#define pl '\n'

using namespace std;

typedef long long ll;


int pd[10001][701][3];//index,weight,how many is not activated
int p[10001],w[10001],d[10001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i]>>w[i]>>d[i];

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){//backpack size
			for(int ac=0; ac<3;ac++){
				//pegar sem ativar
				if(w[i]>j) pd[i][j][ac]=pd[i-1][j][ac];//nao pode pegar
				else pd[i][j][ac]=max(pd[i-1][j][ac], pd[i-1][j-w[i]][ac]);//pegar sem ativar = maximo entre nao pegar e pegar sem ativar

				if(ac){//pode ativar
					if(w[i]>j) pd[i][j][ac-1] = pd[i-1][j][ac-1];
					else pd[i][j][ac-1] = max(pd[i-1][j][ac-1], pd[i-1][j-w[i]][ac-1]);
					if(j+d[i]>=w[i]) pd[i][j+d[i]][ac-1] = max(pd[i-1][j][ac-1], pd[i-1][j-w[i]][ac]+p[i] );//pegar ativando = maximo entre nao pegar(logo nao ativar) e pegar ativando

				}
			}
		}

	}
	int ans=0;

	for(int i=1;i<=n;i++)
		for(int j=0;j<=700;j++)
			for(int a=0;a<3;a++)
				ans = max(ans, pd[i][j][a]);
	cout<<ans<<pl;


}

