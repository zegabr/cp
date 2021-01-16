
#define VISITING 1
#define VISITED 2

bool findCycle(int u){
    if(vis[u] == VISITED) return false;
    if(vis[u] == VISITING) return true;//found cycle

    vis[u] = VISITING;

    bool res = false;
    for(int &v : g[u])
        res |= findCycle(v);

    vis[u] = VISITED;
    return res;
}

bool hasCycle(int N){
    //fill graph

    vis.assign(N,0);
    for(int i = 0; i < N; i++)
        if(findCycle(i)) return true;
    return false;

}
