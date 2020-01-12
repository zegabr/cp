
int timer=1;
/*
   vis[u]<timer ==> u nao visitado
   vis[u]==timer ==> u visitado
   timer++ ==> desvisita todo mundo
   */
const int ms= 10;
const int inf = 1e8+5;
vector<int> dis(ms,inf), vis(ms); 
vector<vector<int>> g(ms);
vector<ii> eds;

//PLS USE 0 INDEXED VERTICES
void add(int u, int v){
  u--;v--;//if already 0-indexed, comment this line
  g[u].pb(v);
  g[v].pb(u);
  //  eds.pb({u,v});
}

void cleargraph(){
  g.assign(ms, vector<int>(0));
  dis.assign(ms,inf);
}

