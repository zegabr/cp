#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
//#define int ll


const int N = 510;
char a[N][N];
bool vis[N][N];
int h,w;
void print(){

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<vis[i][j];

		}
		cout<<pl;
	}
cout<<pl;
}

bool iscenter(int i,int j){

	return a[i+1][j]=='*' and a[i-1][j]=='*' and a[i][j+1]=='*' and a[i][j-1]=='*';
}






bool unique(int i,int j){


	memset(vis,0,sizeof vis);
	vis[i][j]=1;
	// print();
	//visita pra todos os lados
	int in=i-1,jn;
	while(in>=0 and a[in][j]=='*')vis[in][j]=1,in--;
	// print();
	in=i+1;
	while(in<h and a[in][j]=='*')vis[in][j]=1,in++;
	// print();
	jn=j-1;
	while(jn>=0 and a[i][jn]=='*')vis[i][jn]=1,jn--;
	// print();
	jn=j+1;
	while(jn<w and a[i][jn]=='*')vis[i][jn]=1,jn++;
	// print();

	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		if((a[i][j]=='*' and vis[i][j]==0)){
			cout<<"NO"<<pl;
			exit(0);
		}
	}
	return 1;

}
vector<pair<int,int>> centers;
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>h>>w;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>a[i][j];
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		if(i==0 or j==0 or i==h-1 or j==w-1 or a[i][j]=='.') continue;
		// cout<<"testing "<<i<<sp<<j<<pl;
		if(iscenter(i,j) and unique(i,j)){
			cout<<"YES"<<pl;
			return 0;
		}
	}
		// print();
	cout<<"NO"<<pl;
}


