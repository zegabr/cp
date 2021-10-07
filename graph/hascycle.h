
#include "graph.h"
class CycleChecker : public Graph{

    enum state {VISITING, VISITED};

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

    bool hasCycle(int N){ // must build graph before calling this
        vis.assign(N,0);
        for(int i = 0; i < N; i++)
            if(findCycle(i)) return true;
        return false;
    }
};
