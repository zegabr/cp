
vector<int> dist(V,inf); dist[s]=0; 
for(int i=0 ; i<V-1 ; i++){
    for(int u=0 ; u<V ; u++){
        for(auto &v :    g[u]){
            dist[v.first] = min(dist[v.first], dist[u]+v.second);
        }
    }
}
