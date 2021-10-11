
#include <vector>
#include <tuple>
#include <queue>
#include <list>
#include <iostream>
class WeightedGraph{
    public:
        // vis[u]<timer ==> u has not been visited
        // vis[u]==timer ==> u has been visited
        // timer++ ==> unvisit every node
        int timer = 0;
        static const int ms = 300000;
        static const int inf = 1e8+5;
        std::vector<int> dis; // distance
        std::vector<int> vis; // visited
        std::vector<std::vector<std::pair<int,int>>> G;

        WeightedGraph(int n = ms, bool usingInverseGraph = false){
            G.assign(n, {});
            dis.assign(n,inf);
            if(vis.size() < n) vis.resize(n);
            timer++;
        }

        void add(int u, int v, int weigth ,bool bidirectional = false){ // USE 0 INDEXED VERTICES
            G[u].push_back({weigth,v});
            if(bidirectional){
                G[v].push_back({weigth,u});
            }
        }
};
