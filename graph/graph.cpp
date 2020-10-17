
/*
   vis[u]<timer ==> u has not been visited
   vis[u]==timer ==> u has been visited
   timer++ ==> unvisit every node
*/

int timer = 0;;
const int ms = 300000;
const int inf = 1e8+5;
vector<int> dis, vis; 
vector<vector<int>> g, inv;
vector<pair<int,int>> eds;

void add(int u, int v, bool bidirectional = 0, bool usingInverseGraph = false){ //USE 0 INDEXED VERTICES
    g[u].push_back(v);
    if(usingInverseGraph) inv[v].push_back(u);
    if(bidirectional){
        g[v].push_back(u);
        if(usingInverseGraph) inv[u].push_back(v);
    } 
    //eds.push_back({u,v});
}

void init(int n = ms, bool usingInverseGraph = false){
    if(usingInverseGraph) inv.assign(n,{});
    g.assign(n, {});
    dis.assign(n,inf);
    if(vis.size() < n) vis.resize(n);
    timer++;
}

