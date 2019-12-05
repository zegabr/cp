
//for directed graphs
//pls use 0 indexed vertices
const int V = 1e6+5;
vector<int> g[V], gr[V];
vector<bool> used;
vector<int> order, component;
vector<vector<int>> sccs;

void dfs1(int u){
	used[u]=1;
	component.pb(u);
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
	order.clear();
	used.clear();
	sccs.clear();
	component.clear();
}

void add(int u, int v){
	g[u].pb(v);
	gr[v].pb(u);
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
		}
	}
}
