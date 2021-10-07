
#include "graph.h"
class DFS : public Graph{
    void dfs(int u){//O(V+E)
        vis[u]=timer;
        for(auto v : g[u]){
            if(vis[v]<timer)
                dfs(v);
        }
    }
};
