//---------------------------
/*
   vis[u]<timer ==> u has not been visited
   vis[u]==timer ==> u has been visited
   timer++ ==> unvisit every node
   */
int timer=1;
const int ms= 300000;
const int inf = 1e8+5;
vector<int> dis, vis; 
vector<vector<int>> g;
vector<ii> eds;

void add(int u, int v, bool bi=0){ //PLS USE 0 INDEXED VERTICES
  g[u].pb(v);
  if(bi) g[v].pb(u);
  //eds.pb({u,v});
}

void reset_graph(int n = ms){
  g.assign(n, vector<int>());
  dis.assign(n,inf);
  if(vis.empty()) vis.assign(n,0);
}
//----------------------------