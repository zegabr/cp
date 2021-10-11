
#include "graph.h"
class TarjanArticulation : public Graph{
    // find articulation nodes and briges for undirected graphs
    std::vector<int> articulationNode, low, num, par;
    int dfsId, bridgeCount, dfsRoot, rootChildren;

    void setArticulationNode(int v){
        articulationNode[v] = true;
    }

    void setBridge(int u, int v){
        bridgeCount ++;
    }

    void tarjanArticulation(int u){
        low[u] = num[u] = dfsId++;

        for(int v : g[u]){
            if(num[v] == 0){
                par[v] = u;
                if(u == dfsRoot) rootChildren++;

                tarjanArticulation(v);

                if(low[v] >= num[u]){
                    setArticulationNode(v);
                }

                if(low[v] > num[u]){
                    setBridge(u,v);
                }

                low[u] = std::min(low[u], low[v]);

            }else if(v != par[u]){ 
                low[u] = std::min(low[u], num[v]);
            }
        }
    }

    void findArticulation(int n){
        dfsId = 1;
        bridgeCount = 0;
        num.assign(n+1,0);
        low.assign(n+1,0);
        par.assign(n+1,0);
        articulationNode.assign(n+1,0);

        for(int i = 0; i < n; i++){
            if(num[i] == 0){
                dfsRoot = i; 
                rootChildren = 0; 
                tarjanArticulation(i);
                if(rootChildren > 1) setArticulationNode(i);
            }
        }
    }
};
