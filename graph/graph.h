
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
class Graph {
    public:
        // vis[u]<timer ==> u has not been visited
        // vis[u]==timer ==> u has been visited
        // timer++ ==> unvisit every node
        int timer = 0;
        static const int ms = 300000;
        static const int inf = 1e8+5;
        std::vector<int> dis; // distance
        std::vector<int> vis; // visited
        std::vector<std::vector<int>> g, inv; // graph and inverse graph

        Graph(int n = ms, bool usingInverseGraph = false){
            if(usingInverseGraph) inv.assign(n,{});
            g.assign(n, {});
            dis.assign(n,inf);
            if(vis.size() < n) vis.resize(n);
            timer++;
        }

        void add(int u, int v, bool bidirectional = false, bool usingInverseGraph = false){ // USE 0 INDEXED VERTICES
            g[u].push_back(v);
            if(usingInverseGraph) inv[v].push_back(u);

            if(bidirectional){
                g[v].push_back(u);
                if(usingInverseGraph) inv[u].push_back(v);
            }
        }
};
