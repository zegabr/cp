///dfs bipartite check
bool dfsbicolor(int u){
	for(int v : g[u]){
		if(vis[v]<tempo){
			vis[v]=tempo;
			color[v]=!color[u];
			if(!dfsbicolor(v)) return false;
		}else if(color[u]==color[v])
			return false;
	}
	return true;
}