// TODO: format and add 2 - sat    
vector<int> num, low, par, criticalNode; // for SCC, bridges and cut vertexes
    int dfsId, numSCC, dfsroot, rootchildren;
    vector<int> S, comp; // pra guardar os SCCs
    
 //scc
    void tarjanSCC(int u){// DFS
        low[u] = num[u] = dfsId++; 
        S.push_back(u);
        vis[u] = 1;
        
        for(int v : g[u]){
            if(num[v] == 0) 
                tarjanSCC(v);
            
            if(vis[v] == 1) 
                low[u] = min(low[u], low[v]);
        }
        
        if(low[u] == num[u]){
            numSCC++; // aumenta em um a quantidade de SCC
            while(1){
                int v = S.back();
                S.pop_back();
                vis[v] = 0;
                comp[v] = numSCC;
                if(u == v) break;
            }
        }
    }

    void initTarjan(int n){
        dfsId = 1;
        num.assign(n+1,0);
        low.assign(n+1,0);
        vis.assign(n+1,0);
    }

    void findSCCs(int n){
        initTarjan(n);
        numSCC = 0;
        comp.assign(n+1,0);
        
        for(int i=0;i<n;i++){
            if(num[i] == 0){//nao visitei ainda
                tarjanSCC(i);
            }
        }
    }


void setCriticalNode(int v){
    criticalNode[v] = true;
}

void setBridge(int u, int v){

}
void tarjanCritical(int u){
    low[u] = num[u] = dfsId++;
    for(int v : g[u]){
        if(num[v] == 0){
            par[v] = u;
            if(u == dfsroot) rootchildren++;

            tarjanCritical(v);

            if(low[v]>=num[u]){
                setCriticalNode(v);
            }
            if(low[v] > num[u]){
                setBridge(u,v);
            }
            low[u] = min(low[u], low[v]);
        }else if(v != par[u]) low[u] = min(low[u], num[v]);
    }
}

    void findCritical(int n){ // find critical nodes and bridges
    initTarjan(n);
    par.assign(n+1,0);
    criticalNode.assign(n+1,0);
    for(int i=0;i<n;i++){
        if(num[i] == 0){
            dfsroot = i; 
            rootchildren = 0; 
            tarjanCritical(i);
            if(rootchildren > 1) setCriticalNode(i);
        }
    }
}
