
#include "graph.h"
class Toposort : public Graph {
    std::vector<int> dg;//entry degree
    std::vector<int> ans;

    void toposort(int n){//O((V+E)logV)
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(int i = 0; i < n; i++) if(!dg[i]) pq.push(i);
        while(pq.size()){
            int u = pq.top(); pq.pop();
            for(auto v : g[u]){
                if(--dg[v] == 0) pq.push(v);
            }
            ans.push_back(u);
        }
    }
};
