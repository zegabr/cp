
#include "weightedGraph.h"
class Dijkstra : public WeightedGraph{

    void dijkstra(int S, int T){//O(E logV)
        std::priority_queue <
            std::pair<int,int>, 
            std::vector<std::pair<int,int>>, 
            std::greater<std::pair<int,int>>
                > pq;//contains {dis[u], u}
        pq.push({0, S});
        dis.assign(ms, inf);
        dis[S] = 0;

        while(pq.size()){
            int u, disu;
            std::tie(disu, u) = pq.top();
            pq.pop();
            if(disu > dis[u])continue;
            for(auto child : G[u]){
                int v, w;
                std::tie(w, v) = child;
                if(dis[v] > dis[u] + w){           
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
    }
};
