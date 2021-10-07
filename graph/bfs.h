
//shortest path without weight
#include "graph.h"
class BFS : public Graph{
    void bfs(int start){//O(V+E)
        dis.assign(ms, inf);
        dis[start]=0;
        std::queue<int> q({start});

        while(q.size()){
            int u = q.front(); q.pop();
            for(auto &v : g[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }  
    }
};
