////////DFS////////
vector<int> vis(N);
int tempo=1;
void dfs(int u){
	if(vis[u]==tempo) return;
	tempo++;
	for(auto v : g[u]){
		if(vis[v]==tempo) continue;
		dfs(v);
	}
}
///dfs bipartite check
bool dfsbicolor(int u){
	for(int v : g[u]){
		if(!vis[v]){
			vis[v]=1;
			color[v]=!color[u];
			if(!dfsbicolor(v)) return false;
		}else if(color[u]==color[v])
			return false;
	}
	return true;
}