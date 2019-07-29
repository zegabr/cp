#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
const int ms = 1e5+5;
vector<int>g0[ms], g1[ms],g2[ms];
set<pair<int,int>> ed0, ed1;
vector<int> vis(ms),tin(ms),low(ms);
int timer;
//============lca===========
const int ln=25;
int up[ms][ln+1], lv[ms];
void dfs(int u, int p, int h=0){
	lv[u]=h;
	up[u][0]=p;
	for(int i=1;i<=ln;i++)up[u][i]=up[up[u][i-1]][i-1];
	for(int v:g2[u]) if(v!=p) dfs(v,u,h+1);
}
int lca(int a, int b){
	if(lv[b]>lv[a]) swap(a,b);
	int d = lv[a]-lv[b];
	for(int i=0;i<ln;i++) if((d>>i)&1) a=up[a][i];
	if(a==b) return a;
	for(int i=ln;i>-1;i--){
		if(up[a][i]!=up[b][i]){
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0];
}


//============DISJOINT SET UNION==============
int ds[ms],rnk[ms];
void makeset(){
	for(int i=0;i<ms;i++){ ds[i]=i; rnk[i]=0;}
}

int find(int i){//find
	if(ds[i]==i) return i;
	return ds[i]=find(ds[i]);
}

bool uni(int a, int b){//union
	int x=find(a), y=find(b);
	if(x==y) return false;
	if(rnk[x]>rnk[y]) ds[y]=x;
	else{
		ds[x]=y;
		rnk[y] += rnk[x]==rnk[y];
	} 
	return true;
}
//=========find bridge
void dfsb(int u, int p=-1){
	vis[u]=1;
	tin[u]=low[u]=timer++;
	for(int v : g0[u]){
		if(v==p)continue;
		if(vis[v]){
			low[u]=min(low[u],tin[v]);
		}else{
			dfsb(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>tin[u]){ 
				//		cout<<"ponte:"<<u<<sp<<v<<pl;
				ed1.erase({u,v}), ed1.erase({v,u});}
		}
	}
}
void findbrigde(int n){
	timer=0;
	vis.assign(n+1,0);
	tin.assign(n+1,-1);
	low.assign(n+1,-1);
	for(int i=1;i<n+1;i++) if(!vis[i]) dfsb(i);
}

//===dfs ds=====
void dfsset(int u,int p){
	if(vis[u])return;
	vis[u]=1;
	uni(u,p);
	for(int v : g1[u]){
		dfsset(v,p);
	}
}
void printg(vector<int> g[ms],int  n){
	for(int i=0;i<=n;i++){
		cout<<i<<"->";
		for(int j : g[i]) cout<<j<<sp;
		cout<<pl;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a,b,n,m; cin>>n>>m;
	while(m--){
		cin>>a>>b;
		ed0.insert({a,b});
		g0[a].push_back(b);
		g0[b].push_back(a);
	}//cria 1o grafo
	ed1=ed0;//copia conjunto de edges

	//printg(g0,n);

	findbrigde(n);//acha pontes, retirando de ed1

	makeset();
	for(auto p : ed1){
		g1[p.first].push_back(p.second);
		g1[p.second].push_back(p.first);
	}//constroi grafo sem pontes g1
	//printg(g1,n);


	vis.assign(n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0)dfsset(i,i);//une cada componente conexo em um vertice	
		//		cout<<i<<" pertence ao vertice "<<find(i)<<pl;
	}
	for(auto p : ed0){//constroi grafo com vertices q representam componentes conexos g2
		if(ed1.count(p)==0){
			g2[find(p.first)].push_back(find(p.second));
			g2[find(p.second)].push_back(find(p.first));
		}
	}
	//printg(g2,n);

	int root=find(1);
	dfs(root,root);
	int k; cin>>k;
	while(k--){
		cin>>a>>b;
		//cout<<a<<sp<<b<<" means ";
		a=find(a), b=find(b);//pega componentes conexos representantes
		//cout<<a<<sp<<b<<pl;
		//ok até aqui
		//cout<<"lca de "<<a<<" e "<<b<<" deu "<<lca(a,b)<<pl;
		int ha=lv[a], hb=lv[b], hl=lv[lca(a,b)];
		//cout<<"altura a="<<ha<<sp<<"altura b="<<hb<<sp<<"altura lca = "<<hl<<pl;
		cout<<ha+hb-hl-hl<<pl;
	}






}
