
#include "weightedGraph.h"
class SPFA : public WeightedGraph{
    // generally as fast as dijkstra
    std::vector<bool> inq;
    static const int inf = 0x3f3f3f3f;
    int V;// number of vertices, update in main

    int spfa(int S, int T){
        bool way = false;
        dis.assign(ms, inf);
        inq.assign(ms,0);
        vis.assign(ms,0);

        std::queue<int> q({S});
        dis[S]=0;
        inq[S]=1;

        while(q.size()){
            int u = q.front(); 
            q.pop(); inq[u]=0;
            if(vis[u] > V) return -1;//has negative cycle
            for(auto child : G[u]){
                int v = child.y, w = child.x;
                if(dis[u]+w < dis[v]){
                    dis[v] = dis[u]+w;
                    if(!inq[v]){
                        q.push(v); 
                        inq[v]=1;
                        vis[v]++;
                    }
                }
            }
        }
        return dis[T];
    }
};
