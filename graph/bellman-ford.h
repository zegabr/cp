
// TODO: relearn when to use this
#include "weightedGraph.h"
class BellmanFord : public WeightedGraph{
    void bellmanFord(int start, int V){
        dis[start] = 0;
        for(int i = 0; i < V - 1 ; i++){
            for(int u = 0; u < V ; u++){
                for(auto &p : G[u]){
                    int v,w;
                    std::tie(w,v) = p;
                    dis[v] = std::min(dis[v], dis[u] + w);
                }
            }
        }
    }
};
