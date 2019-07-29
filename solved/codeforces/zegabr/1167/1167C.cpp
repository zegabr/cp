#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
const int V = 5e5+10;
int ds[V],siz[V];
void makeset(){
	for(int i=1;i<V;i++){ ds[i]=i; siz[i]=1;}
}

int find(int i){//find
	if(ds[i]==i) return i;
	return ds[i]=find(ds[i]);
}

bool uni(int a, int b){//union
	int x=find(a), y=find(b);
	if(x==y) return false;
	ds[y]=x;
	siz[x]+=siz[y];
	return true;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k,i,io;
	cin>>n>>m;
	makeset();

	while(m--){
		cin>>k;
		if(k){ cin>>io;k--;}
		while(k--){
			cin>>i;
			uni(i,io);
		}
	}

	for(i=1;i<=n;i++)cout<<siz[find(i)]<<sp;


}
