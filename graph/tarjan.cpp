
//for directed graphs
const int V=1e6+5;
vector<int> num,low,vis,S;
int dfsCounter,sccCounter;
vector<vector<int>> sccs;
vector<pair<int,int>> g[V];//g[u] contains {v, w}

void tarjan(int u){
    low[u]=num[u]=dfsCounter++;
    S.push_back(u);
    vis[u]=1;
    for(auto &v: g[u]){//g is adjacency list
        if(num[v.first]==0) tarjan(v.first);
        if(vis[v.first]) low[u]=min(low[u],low[v.first]);
    }

    if(low[u]==num[u]){
        sccCounter++;
        vector<int> scc;
        while(1){
            int v = S.back(); S.pop_back(); vis[v]=0;
            scc.push_back(v);
            if(u==v) break;
        }
        sccs.push_back(scc);//scc has one scc, store it on sccs
    }
}

void findscc(int n=V){
    num.assign(n+1,0);
    low.assign(n+1,0);
    vis.assign(n+1,0);
    dfsCounter=sccCounter=0;
    for(int i=0; i<V; i++){
        if(num[i]==0) tarjan(i);
    }
}
