
//for directed graphs
//pls use 0 indexed vertices
const int V = 1e5+5;
vector<int> g[V], gr[V];
vector<bool> used;
vector<int> order, component;
vector<vector<int>> sccs;
vector<ii> eds;

void dfs1(int u){
	used[u]=1;
	for(auto v : g[u]){
		if(!used[v]){
			dfs1(v);
		}
	}
	order.pb(u);
}

void dfs2(int u){
	used[u]=1;
	component.pb(u);
	for(auto v : gr[u]){
		if(!used[v]){
			dfs2(v);
		}
	}
}

void init(int n){
	for(int i=0;i<n;i++){
		g[i].clear();
		gr[i].clear();
	}
	eds.clear();
	order.clear();
	used.clear();
	sccs.clear();
	component.clear();
}

void add(int u, int v){
	u--;v--;//if already 0-indexed, comment this line
	g[u].pb(v);
	gr[v].pb(u);
	eds.pb({u,v});
}

void getsccs(int n){
	used.assign(n,0);
	for(int i=0;i<n;i++)
		if(!used[i]) dfs1(i);

	used.assign(n,0);
	for(int i=0;i<n;i++){
		int u = order[n-1-i];
		if(!used[u]){
			dfs2(u);
			sccs.pb(component);//storing scc here
			component.clear();
		}
	}
}
