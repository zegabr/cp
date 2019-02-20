#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ms = 1e5+10; // Quantidade maxima de vertices
const int me = 5e5+10; // Quantidade maxima de arestas
const ll INF = 6e13+10;

ll wt[me];
int adj[ms], to[me], ant[me], z, n;
int copy_adj[ms], fila[ms], level[ms];

void clear() { // Lembrar de chamar no main
  memset(adj, -1, sizeof adj);
  z = 0;
}

void add(int u, int v, ll k) {
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = k;
  adj[u] = z++;
  swap(u, v);
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = 0; // Lembrar de colocar = 0
  adj[u] = z++;
}

bool bfs(int source, int sink) {
  memset(level, -1, sizeof level);
  level[source] = 0;
  int front = 0, size = 0, v;
  fila[size++] = source;
  while(front < size) {
  v = fila[front++];
  for(int i = adj[v]; i != -1; i = ant[i]) {
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
  if(wt[i] && level[to[i]] == level[v] + 1 && 
    (f = dfs(to[i], sink, min(flow, wt[i])))) {
    wt[i] -= f;
    wt[i ^ 1] += f;
    return f;
  }
  }
  return 0;
}

int maxflow(int source, int sink) {
  int ret = 0, flow;
  while(bfs(source, sink)) {
  memcpy(copy_adj, adj, sizeof adj);
  while((flow = dfs(source, sink, INF))) {
    ret += flow;
  }
  }
  return ret;
}

int main(){
	clear();
	map<pair<int,int>, ll> w;
	int N, M;
	cin>>N>>M;
	while(M--){
		int a,b; ll c;
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		w[{a,b}]+=c;
		
	}
	for(auto tri : w){
		auto p = tri.first; ll c = tri.second;
		if(p.first==p.second)continue;
		add(p.first,p.second,c);
	}

	cout<<maxflow(1,N)<<'\n';

}
