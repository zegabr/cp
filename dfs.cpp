void dfs(int u){
    if(vis[u]) return;
    vis[u]=true;
    for(auto v : g[u]){
        if(vis[v]) continue;
        
        dfs(v);
    }
}