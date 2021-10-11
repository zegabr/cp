
#include "graph.h"
class TarjanSCC : public Graph{
    // find SCCs for directed graphs
    std::vector<int> low, num, visitingStack;
    std::vector<int> comp; // store components
    std::vector<int> assignment; // store 2 - SAT assignment
    int sccCount, dfsId;

    void tarjanSCC(int u){
        low[u] = num[u] = dfsId++; 
        visitingStack.push_back(u);
        vis[u] = 1;

        for(int v : g[u]){
            if(num[v] == 0) // never visited
                tarjanSCC(v);

            if(vis[v] == 1) 
                low[u] = std::min(low[u], low[v]);
        }

        if(low[u] == num[u]){
            sccCount++;
            while(1){
                int v = visitingStack.back();
                visitingStack.pop_back();
                vis[v] = 0;
                comp[v] = sccCount;
                if(u == v) break;
            }
        }
    }

    int findSCCs(int n){
        dfsId = 1; // this should start bigger than unvisited
        num.assign(n+1,0);
        low.assign(n+1,0);
        vis.assign(n+1,0);

        sccCount = 0;
        comp.assign(n+1,0);

        for(int i=0;i<n;i++){
            if(num[i] == 0){// never visited
                tarjanSCC(i);
            }
        }
        return sccCount;
    }

    //2-sat below
    void add_clause(int a, int b){//a and b has to be already at form 2k or 2k+1
        //a V b
        add(a^1, b);//not( a) => b
        add(b^1, a);//not( b) => a
    }

    void add_coincidence(int a, int b){
        //~a V b and ~b V a
        add_clause(a, b^1);
        add_clause(b, a^1);
    }

    void add_xor(int a, int b){
        //a V b and ~a V ~b
        add_clause(a, b);
        add_clause(a^1, b^1);
    }

    bool is_2SAT(int n){//solve 2-SAT (n has to be 2 times number of variables)
        assignment.assign(n/2, false);
        for(int i=0;i<n;i+=2){
            if(comp[i] == comp[i+1])
                return false;
            assignment[i/2] = comp[i] > comp[i+1];
        }
        return true;
    }
};
