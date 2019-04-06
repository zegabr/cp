#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;

int pd[10001][701][3];//index,weight,how many is not activated
int p[10001],w[10001],d[10001];
//int s[10001][701][3];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>w[i]>>d[i];
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){//backpack size
			if(w[i]<=j){//can get artifact
				for(int ac=2; ac>=0;ac--){
					if(ac==0){//cannot activate it
						pd[i][j][0] = max(pd[i][j][0], pd[i-1][j-w[i]][0]+p[i]);
					}else if(ac==1){//can activate 1
						pd[i][j][1] = max(pd[i][j][1], pd[i-1][j-w[i]][1]+p[i]);
						pd[i][j+d[i]][0] = max(pd[i][j+d[i]][0], pd[i-1][j-w[i]][1]+p[i]);
					}else{//can activate 2
						pd[i][j][2] = max(pd[i][j][2], pd[i-1][j-w[i]][2]+p[i]);
						pd[i][j+d[i]][1] = max(pd[i][j+d[i]][1], pd[i-1][j-w[i]][2]+p[i]);
					}
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


