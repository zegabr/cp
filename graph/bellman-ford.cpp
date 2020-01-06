
vector<ii> G[ms];//G[u] contains {w, v}

dis[s]=0; 
for(int i=0 ; i<V-1 ; i++){
    for(int u=0 ; u<V ; u++){
        for(auto &v :    G[u]){
            dis[v.y] = min(dis[v.y], dis[u]+v.x);
        }
    }
}
