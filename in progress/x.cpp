#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;


int pd[10001][910][3];//index, current capacity, how many can activate
int p[10001],w[10001],d[10001];
int m,n;

//offset capacity
int S;
inline int off(int j){ return j+S;}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	int me=0,me2=0;
	memset(pd, 0, sizeof pd);

	for(int i=1;i<=n;i++){
		cin>>p[i]>>w[i]>>d[i];
		if(d[i]>me2)me2=d[i];
		if(me2>me)swap(me,me2);
	}

	S=me+me2;

	for(int i=1;i<=n;i++){
		for(int j=off(0);j<=off(m);j++){
			for(int a=0;a<3;a++){
				//caso de pegar ou nao pegar sem ativar
				if(off(w[i])>j)pd[i][j][a] = pd[i-1][j][a];//n pode pegar
				else pd[i][j][a] = max(pd[i-1][j][a], pd[i-1][j-w[i]][a]+p[i]);//nao pega ou pega 
	
				if(a){	
					pd[i][j+d[i]][a-1] = max(pd[i-1][j+d[i]][a-1], pd[i-1][j+d[i]-w[i]][a]+p[i]);//nao pegar ou pegar (ativando)
				}

			}

		}
	}

	int ans=0;
	//	cout<<S<<pl;
	for(int i=1;i<=n;i++)
		for(int j=off(1);j<=off(m);j++)
			for(int a=0;a<3;a++)
				ans = max(ans, pd[i][j][a]);


//	cout<<pd[n][off(m)][0]<<pl;
	cout<<ans<<pl;




}
