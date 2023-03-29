
#include "graph.h"
class Kuhn : public Graph{
    // bipartite unweighted graph maximum matching
    // Only needs to create adjacency from left to right as it was a directed graph
    int matchl[ms], matchr[ms];
    // m nodes in one group and n in another ==> m+n == ms
    void clr(){
        for(int i = 0; i < ms; i++)
            matchr[i] = matchl[i] = -1;
    }

    bool kuhn(int v){//dfs
        if(vis[v] == timer) return 0;
        vis[v] = timer;
        for(int to : g[v]){
            if(matchl[to] == -1 or kuhn(matchl[to])){
                matchl[to] = v;
                matchr[v] = to;
                return 1;
            }
        }
        return 0;
    }

    int findmatching(int n){//O(mn)
        int ans = 0;
        clr();
        for(int i = 0; i < n; i++){// left nodes
            timer++;
            ans += kuhn(i);
        }
        // return number of edges used in maximum match (min vertex cover)
        return ans;
        //return ans==n;//perfect match
    }
    //MAXIMUM INDEPENDENT SET = ms - MAXIMUM BIPARTITE MATCHING
    void printmatch(int n){
        for(int i = 0; i < n; i++)
            std::cout << "match[" << i << "]=" << matchr[i] - n << std::endl;
    }
};
