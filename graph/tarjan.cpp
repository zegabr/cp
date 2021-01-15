
//for undirected graph
//TODO: relearn how it works
int dfsroot, rootchildren;
vector<int>num, low, par, cutvertex;

void iscutvertex(int v){
    cutvertex[v]=true;
}

void isbridge(int u, int v){

}

void dfspointbridge(int u){
    low[u]=num[u]=timer++;
    for(int v : g[u]){
        if(num[v]==0){
            par[v]=u;
            if(u == dfsroot) rootchildren++;

            dfspointbridge(v);

            if(low[v]>=num[u]){
                iscutvertex(v);
            }
            if(low[v]>num[u]){
                isbridge(u,v);
            }
            low[u]=min(low[u], low[v]);
        }else if(v != par[u]) low[u]=min(low[u],num[v]);
    }
}

void findpointbridge(int n=ms){
    timer=0;
    num.assign(n+1,0);
    low.assign(n+1,0);
    par.assign(n+1,0);
    cutvertex.assign(n+1,0);
    for(int i=0;i<n;i++){
        if(num[i]==0){
            dfsroot=i; rootchildren=0; dfspointbridge(i);
            if(rootchildren > 1) iscutvertex(i);
        }
    }
}



//tarjan SCC aqui
/*
TODO: refatorar pra reuzir repeticao de codigo, manter compativel com graph.cpp e ao final disso, copiar 2sat pra esse arquivo.
todo: manter kosaraju na lib, pois eh mais intuitivo
*/
class Solution{
    vector<vector<int>> g;
    vector<int> vis;
    void init(int n){//zera grafo
        g.assign(n, {});
        if(vis.size() < n) vis.resize(n);
    }

    vector<int> num, low;
    vector<int> S, comp // pra guardar os SCCs
    int numSCC, dfsId;

    void tarjanSCC(int u){// DFS
        low[u] = num[u] = ++dfsId; // o 1o valor de low e num tem q ser diferente de 0...
        S.push_back(u);
        vis[u] = 1;
        
        for(int v : g[u]){
            if(num[v]==0) // ...pois usei 0 aqui pra dizer que nao foi visitado ainda
                tarjanSCC(v);
            if(vis[v]) 
                low[u]=min(low[u], low[v]);
        }
        
        if(low[u] == num[u]){
            numSCC++; // aumenta em um a quantidade de SCC
            while(1){
                int v = S.back(); S.pop_back(); vis[v] = 0;
                comp[v] = numSCC; // diz q numSCC eh o componente de v
                if(u == v) break; // acabou o componente
            }
        }
    }

    void findSCCs(int n){
        dfsId = numSCC = 0;
        num.assign(n+1,0);//esse valor inicial tem q ser diferente do inicial de dfsId
        low.assign(n+1,0);
        comp.assign(n+1,0);
        vis.assign(n+1,0);
        
        for(int i=0;i<n;i++){
            if(num[i]==0){//nao visitei ainda
                tarjanSCC(i);
            }
        }
    }
	public:
	
    int SCC(int V, vector<int> adj[]) {
        init(V);
        for(int i = 0; i < V; i++)
            g[i] = adj[i];
        
        numSCC = 0;
        findSCCs(V);
        return numSCC;
    }
};

// problems for testing:
//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
//https://binarysearch.com/problems/Edges-that-Disconnect-the-Graph