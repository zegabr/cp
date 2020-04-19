
//---------------------------
int timer=1;
/*
   vis[u]<timer ==> u nao visitado
   vis[u]==timer ==> u visitado
   timer++ ==> desvisita todo mundo

*/
const int ms= 300000;
const int inf = 1e8+5;
vector<int> dis, vis; 
vector<vector<int>> g;
vector<ii> eds;
//----------------------------

//PLS USE 0 INDEXED VERTICES
void add(int u, int v){
  u--;v--;//if already 0-indexed, delete this line
  g[u].pb(v);
  g[v].pb(u);
  //  eds.pb({u,v});
}

void cleargraph(int n = ms){
  g.assign(n, vector<int>());
  dis.assign(n,inf);
  if(vis.empty()) vis.assign(n,0);
}

