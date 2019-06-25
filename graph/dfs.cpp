//==========DFS=============
vector<int> vis(N);
int tempo=1;//fazer tempo++ para cada vez que precisar zerar visitados
void dfs(int u){//O(V+E)
	if(vis[u]==tempo) return;
	vis[u]=tempo;
	for(auto v : g[u]){
		if(vis[v]==tempo) continue;
		dfs(v);
	}
}