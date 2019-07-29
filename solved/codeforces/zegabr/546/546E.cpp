#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

using ll = long long;
//#define int ll


//========DINIC MAX FLOW===============
const ll inf = 0x3f3f3f3f;//atualizar com fluxo maximo possivel em caso de runtime error
const int ms = 202; // Quantidade maxima de vertices
const int me = 1601; // Quantidade maxima de arestas
int t[ms][ms];
int to[me], ant[me], z;
int adj[ms], copy_adj[ms], fila[ms], level[ms];
ll wt[me];

void add(int u, int v, ll k,ll rev =0) {//adiciona aresta e aresta residual (2 arestas)
	//chamar add(a,b,cap) se direcionado
	//chamar add(a,b,cap,cap) se nao direcionado
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = k;
	adj[u] = z++;
	swap(u, v);
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = rev;
	adj[u] = z++;
}

int bfs(int source, int sink) {
	memset(level, -1, sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while(front < size) {
		v = fila[front++];
		for(int i = adj[v]; i != -1; i = ant[i]) {//percorre adjacencia de v (existem arestas v->to[i])
			if(wt[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

ll dfs(int v, int sink, ll flow) {
	if(v == sink) return flow;
	ll f;
	for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if(wt[i] && level[to[i]] == level[v] + 1 and
				(f = dfs(to[i], sink, min(flow, wt[i])))) {
			wt[i] -= f;
			wt[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

ll maxflow(int source, int sink) {
	ll ret = 0, flow;
	while(bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(source, sink, inf))) {
			ret += flow;
		}
	}
	return ret;
}

void clear() { // Lembrar de chamar no main
	memset(adj, -1, sizeof adj);
	z = 0;
}
int main(){
	//ios::sync_with_stdio(0); cin.tie(0);
	clear();
	int m,n,suma=0,sumb=0;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	int source = 0, sink = n+n+1;//ai = 1->n, bi=n+1->2n
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++){cin>>a[i]; suma+=a[i];}
	for(int i=1;i<=n;i++){cin>>b[i];sumb+=b[i];}
int u,v;
	while(m--){
	  //cin>>u>>v;
		scanf("%d%d",&u,&v);
		add(u,v+n,inf);
		add(v,u+n,inf);
	}
	
	for(int i=1;i<=n;i++){
	 add(source,i,a[i]);//source - > u 
	 add(i+n,sink,b[i]);//v -> sink
	 add(i,i+n,inf);//dele pra ele msm
	}
	
	if(int mf = maxflow(source,sink)!=sumb or suma!=sumb){
		//cout<<"NO"<<endl;
		printf("NO\n");
		return 0;
	}		

	//cout<<"YES"<<endl;
	printf("YES\n");

	for(int e=0;e<z;e+=2){
			int u = to[e^1], v = to[e];
			t[u][v-n] = wt[e^1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<t[i][j]<<' ';
			printf("%d ",t[i][j]);
		}
		//cout<<endl;
		printf("\n");
	}	





}