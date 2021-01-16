
vector<pair<int,int>> G[ms];//G[u] contains {w, v}

dis[s] = 0;
for(int i = 0; i < V - 1 ; i++){
    for(int u = 0; u < V ; u++){
        for(auto &p : G[u]){
            int v,w;
            tie(w,v) = p;
            dis[v] = min(dis[v], dis[u] + w);
        }
    }
}
