
#include "graph.h"
class Diameter: public Graph{
    std::vector<int> center;
    std::vector<bool> findnode;
    int maxdist, maxdistnode;
    int len;

    void dfs1(int u, int distu=0, int par=-1){
        if(maxdist < distu){
            maxdist=distu;
            maxdistnode=u;
        }
        for(int v : g[u]){
            if(v!=par) dfs1(v,distu+1,u);
        }
    }

    void dfs2(int u, int distu=0, int par=-1){
        if(distu==len){
            findnode[u]=1;
            return;
        }	
        for(int v : g[u]){
            if(v!=par) dfs2(v,distu+1,u);
        }
    }

    void dfs3(int u, int distu=0, int par=-1){
        if(distu==len){
            if(findnode[u]){
                center.push_back(u);
                center.push_back(par);
            }
            return;
        }	

        for(int v : g[u]){
            if(v!=par) dfs3(v,distu+1,u);
        }
    }

    void findcenters(int n){
        //finding diameter
        center.clear();
        int start, end, diam;

        maxdist=-1;
        dfs1(0);
        start = maxdistnode;

        maxdist=-1;
        dfs1(start);
        end = maxdistnode;

        diam = maxdist;//tree diameter here


        //finding centers
        len=diam/2;
        findnode.assign(n,0);

        if(diam%2){
            dfs2(start);
            len++;
            dfs3(end);
            if(center[0]>center[1])
                std::swap(center[0],center[1]);
        }else{
            dfs2(start);
            dfs3(end);
            center.pop_back();
        }

        //finding most distant nodes from center
        findnode.assign(n,0);
        for(int c : center){
            dfs2(c);
        }
        //findnode has worst nodes
    }
};
