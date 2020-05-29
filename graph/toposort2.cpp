vector<int> ans;
vector<vector<int>> g;
vector<int> vis;

bool dfs(int u){
    if(vis[u] == 2) return true;
    if(vis[u] == 1) return false;//found cycle

    vis[u] = 1;
    bool res = true;

    for(int &v : g[u])
        res &= dfs(v);

    vis[u] = 2;
    ans.push_back(u);
    return res;
}

bool toposort(int N){
    //fill graph

    vis.assign(N,0);
    ans.clear();
    for(int i = 0; i < N; i++)
        if(!dfs(i)) return false;

    reverse(ans.begin(), ans.end());
    return true;

}
